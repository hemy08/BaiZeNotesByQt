//
// Created by zhaoj on 25-7-13.
//

#include "editor_line_no.h"

#include <QPainter>
#include <QTextBlock>


namespace HemyUI
{
    // 取消注释并修改
    LineNumberArea::LineNumberArea(HWorkBenchEditor *editor)
        : QWidget(editor), m_editor(editor) {}

    QSize LineNumberArea::sizeHint() const {
        return { static_cast<int> (m_editor->lineNumberAreaWidth()), 0};
    }

    void LineNumberArea::paintEvent(QPaintEvent *event) {
        m_editor->paintLineNumberArea(event);
    }
}
