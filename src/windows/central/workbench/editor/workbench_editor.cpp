//
// Created by zhaoj on 25-7-11.
//

#include "workbench_editor.h"
#include <QTextDocument>
#include <QAbstractTextDocumentLayout>
#include "editor_line_no.h"
#include "gui_comm_def.h"

namespace HemyUI
{
    // 构造函数
    HWorkBenchEditor::HWorkBenchEditor(QWidget *parent)
        : QTextEdit(parent)
    {
        this->setObjectName("HWorkBenchEditor");
        this->setContentsMargins(HEMY_GUI::ZERO_MARGINS);
        m_line_view = new LineNumberArea(this); // 使用新定义的 LineNumberArea
        m_line_view->setObjectName("LineNoView");
        Initial();
    }

    void HWorkBenchEditor::Initial()
    {
        // 连接信号槽
        connect(this->document(), &QTextDocument::blockCountChanged,
                this, &HWorkBenchEditor::updateLineNumberAreaWidth);
        connect(this->verticalScrollBar(), &QScrollBar::valueChanged,
                this, [this](int){ this->m_line_view->update(); });
        connect(this, &QTextEdit::textChanged,
                this, [this](){ this->m_line_view->update(); });
        connect(this, &QTextEdit::cursorPositionChanged,
                this, [this](){ this->m_line_view->update(); });

        // 初始更新行号区域宽度
        updateLineNumberAreaWidth(0);
    }

    // 计算行号区域宽度
    uint32_t HWorkBenchEditor::lineNumberAreaWidth() const
    {
        uint32_t digits = 1;
        uint32_t max = qMax(1, document()->blockCount());
        while (max >= 10) {
            max /= 10;
            ++digits;
        }

        uint32_t space = 6 + fontMetrics().horizontalAdvance(QLatin1Char('9')) * digits;
        return space;
    }

    // 更新行号区域宽度
    void HWorkBenchEditor::updateLineNumberAreaWidth(uint32_t /* newBlockCount */)
    {
        /*QSignalBlocker blocker(this);
        const auto oldMargins = viewportMargins();
        const int width =
            m_line_view->isLineNumAreaEnabled()
                ? m_line_view->sizeHint().width() + _lineNumberLeftMarginOffset
                : oldMargins.left();
        const auto newMargins = QMargins{width, oldMargins.top(),
                                         oldMargins.right(), oldMargins.bottom()};

        if (newMargins != oldMargins) {
            setViewportMargins(newMargins);
        }

        // Grow lineNumArea font-size with the font size of the editor
        const int pointSize = this->font().pointSize();
        if (pointSize > 0) {
            QFont font = _lineNumArea->font();
            font.setPointSize(pointSize);
            _lineNumArea->setFont(font);
        }*/

        setViewportMargins(lineNumberAreaWidth(), 0, 0, 0);
    }

    // 调整大小事件
    void HWorkBenchEditor::resizeEvent(QResizeEvent *event)
    {
        QTextEdit::resizeEvent(event);

        // 设置行号区域位置和大小
        QRect cr = contentsRect();
        m_line_view->setGeometry(QRect(cr.left(), cr.top(), lineNumberAreaWidth(), cr.height()));
    }

    // 实现 paintLineNumberArea
    void HWorkBenchEditor::paintLineNumberArea(QPaintEvent *event)
    {
        QPainter painter(m_line_view);
        painter.fillRect(event->rect(), QColor(240, 240, 240)); // 浅灰色背景

        QTextDocument* doc = document();
        QTextBlock block = doc->begin();
        int blockNumber = 0;

        // 获取当前可见区域
        QRect visibleRect = viewport()->rect();
        int verticalScrollValue = verticalScrollBar()->value();

        // 计算可见区域的顶部和底部位置
        int visibleTop = verticalScrollValue;
        int visibleBottom = verticalScrollValue + visibleRect.height();

        while (block.isValid()) {
            blockNumber++;

            // 获取文本块的位置和大小
            QTextLayout* layout = block.layout();
            if (!layout) {
                block = block.next();
                continue;
            }

            // 计算文本块的位置
            QPointF position = layout->position();
            QRectF blockRect(position.x(), position.y(),
                            layout->boundingRect().width(),
                            layout->boundingRect().height());

            // 只绘制可见行号
            if (blockRect.top() > visibleBottom) break;
            if (blockRect.bottom() < visibleTop) {
                block = block.next();
                continue;
            }

            // 计算行号在行号区域中的位置
            int yPos = static_cast<int>(blockRect.y()) - verticalScrollValue;

            // 绘制行号
            QString number = QString::number(blockNumber);
            painter.setPen(Qt::darkGray);
            painter.drawText(
                0,
                yPos,
                m_line_view->width() - 5,
                static_cast<int>(blockRect.height()),
                Qt::AlignRight | Qt::AlignVCenter,
                number
            );

            block = block.next();
        }
    }

    // 更新行号区域
    void HWorkBenchEditor::updateLineNumberArea(const QRect &rect, int dy)
    {
        if (dy != 0) {
            m_line_view->scroll(0, dy);
        } else {
            m_line_view->update(0, rect.y(), m_line_view->width(), rect.height());
        }

        if (rect.contains(viewport()->rect())) {
            updateLineNumberAreaWidth(0);
        }
    }
}
