//
// Created by zhaoj on 25-7-11.
//

#ifndef EDITOR_WIDGET_H
#define EDITOR_WIDGET_H
#include <QTextEdit>
#include <QWidget>
#include <QScrollBar>
#include <QPainter>
#include <QTextBlock>


namespace HemyUI
{
    class LineNumberArea;
    class HWorkBenchEditor : public QTextEdit
    {
        Q_OBJECT
    public:
        explicit HWorkBenchEditor(QWidget *parent = nullptr);
        ~HWorkBenchEditor() override = default;

        [[nodiscard]] LineNumberArea *lineNoView() const { return m_line_view; } // 修改返回类型

    private:
        friend class LineNumberArea; // 添加友元声明
        LineNumberArea *m_line_view = nullptr; // 修改类型为 LineNumberArea

        void Initial();
        uint32_t lineNumberAreaWidth() const;
        void resizeEvent(QResizeEvent *event);
        void updateLineNumberAreaWidth(uint32_t /* newBlockCount */);
        void paintLineNumberArea(QPaintEvent *event);
        void updateLineNumberArea(const QRect &rect, int dy);
    };
}

#endif //EDITOR_WIDGET_H
