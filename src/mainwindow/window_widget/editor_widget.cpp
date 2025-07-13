//
// Created by zhaoj on 25-7-11.
//

#include "editor_widget.h"
#include <QTextDocument>
#include <QAbstractTextDocumentLayout>

namespace HMainLayOut
{
    HemyEditorWidget::HemyEditorWidget(QWidget *parent) : QTextEdit(parent) {
        // 创建行号区域
        //m_lineNumberArea_ = new LineNumberArea(this);

        // 连接信号
        /*connect(document(), &QTextDocument::blockCountChanged,
                this, &HemyEditorWidget::updateLineNumberAreaWidth);
        connect(verticalScrollBar(), &QScrollBar::valueChanged,
                [this](int) { updateLineNumberAreaWidth(); });
        connect(this, &QTextEdit::cursorPositionChanged,
                this, &HemyEditorWidget::updateLineNumberAreaWidth);*/

        // 初始更新
        //updateLineNumberAreaWidth();
    }
/*
    void HemyEditorWidget::setLineNumbersVisible(bool visible) {
        m_lineNumberArea_->setVisible(visible);
        updateLineNumberAreaWidth();
    }

    int HemyEditorWidget::lineNumberAreaWidth() const {
        if (!m_lineNumberArea_->isVisible())
            return 0;

        int digits = 1;
        int max = qMax(1, document()->blockCount());
        while (max >= 10) {
            max /= 10;
            ++digits;
        }

        // 计算宽度 = 左边距 + 数字宽度 + 右边距
        int space = 10 + fontMetrics().horizontalAdvance(QLatin1Char('9')) * digits + 10;
        return space;
    }
    void HemyEditorWidget::resizeEvent(QResizeEvent *event) {
        QTextEdit::resizeEvent(event);

        // 更新行号区域位置
        QRect cr = contentsRect();
        m_lineNumberArea_->setGeometry(
            QRect(cr.left(), cr.top(),
                  lineNumberAreaWidth(), cr.height()));
    }

    void HemyEditorWidget::updateLineNumberAreaWidth() {
        // 设置视口边距
        setViewportMargins(lineNumberAreaWidth(), 0, 0, 0);

        // 更新行号区域大小
        QRect cr = contentsRect();
        m_lineNumberArea_->setGeometry(
            QRect(cr.left(), cr.top(),
                  lineNumberAreaWidth(), cr.height()));
    }

    void HemyEditorWidget::updateLineNumberArea(const QRect &rect, int dy) const
    {
        Q_UNUSED(dy);
        m_lineNumberArea_->update(rect);
    }

    QRectF HemyEditorWidget::blockBoundingGeometry(const QTextBlock &block) const {
        QTextLayout *layout = block.layout();
        if (!layout)
            return QRectF();

        const QRectF boundingRect = layout->boundingRect();
        const QPointF position = document()->documentLayout()->blockBoundingRect(block).topLeft();
        return {position.x(), position.y(), boundingRect.width(), boundingRect.height()};
    }

    void HemyEditorWidget::lineNumberAreaPaintEvent(QPaintEvent *event) const
    {
        QPainter painter(m_lineNumberArea_);
        painter.fillRect(event->rect(), QColor(240, 240, 240)); // 浅灰色背景

        // 获取当前视口区域
        QRect viewportRect = viewport()->rect();
        QPointF contentOffset = contentOffset();

        // 计算可见区域
        int visibleTop = viewportRect.top() + contentOffset.y();
        int visibleBottom = visibleTop + viewportRect.height();

        // 遍历所有文本块
        QTextBlock block = document()->begin();
        int blockNumber = 0;

        while (block.isValid()) {
            QRectF blockRect = blockBoundingGeometry(block);
            blockRect.translate(contentOffset);

            // 检查是否在可见区域内
            if (blockRect.top() > visibleBottom)
                break;

            if (block.isVisible() && blockRect.bottom() >= visibleTop) {
                // 绘制行号
                QString number = QString::number(blockNumber + 1);
                painter.setPen(Qt::darkGray);
                painter.drawText(
                    0,
                    static_cast<int>(blockRect.top()),
                    m_lineNumberArea_->width() - 5,
                    static_cast<int>(blockRect.height()),
                    Qt::AlignRight | Qt::AlignVCenter,
                    number
                );
            }

            block = block.next();
            blockNumber++;
        }
    }*/
}
