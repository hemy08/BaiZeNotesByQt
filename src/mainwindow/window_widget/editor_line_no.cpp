//
// Created by zhaoj on 25-7-13.
//

#include "editor_line_no.h"

#include <QPainter>
#include <QTextBlock>


namespace HMainLayOut
{
    /*LineNumberArea::LineNumberArea(HemyEditorWidget *editor)
        : QWidget(editor), m_editor(editor) {}

    QSize LineNumberArea::sizeHint() const {
        return {m_editor->lineNumberAreaWidth(), 0};
    }

    void LineNumberArea::paintEvent(QPaintEvent *event) {
        QPainter painter(this);
        painter.fillRect(event->rect(), QColor(240, 240, 240)); // 浅灰色背景

        QTextBlock block = m_editor->m_text_edit_->document()->firstBlock();
        int blockNumber = block.blockNumber();

        // 获取当前视口的几何信息
        QRect viewportRect = m_editor->m_text_edit_->viewport()->rect();
        QPointF contentOffset = m_editor->m_text_edit_->contentOffset();

        // 计算可见区域
        int visibleTop = viewportRect.top() + contentOffset.y();
        int visibleBottom = visibleTop + viewportRect.height();

        // 只绘制可见行号
        while (block.isValid()) {
            QRectF blockRect = m_editor->m_text_edit_->blockBoundingGeometry(block);
            blockRect.translate(contentOffset);

            // 检查是否在可见区域内
            if (blockRect.top() > visibleBottom)
                break;

            if (blockRect.bottom() >= visibleTop) {
                QString number = QString::number(blockNumber + 1);
                painter.setPen(Qt::darkGray);
                painter.drawText(
                    0,
                    static_cast<int>(blockRect.top()),
                    width() - 5,
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
