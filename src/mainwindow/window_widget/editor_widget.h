//
// Created by zhaoj on 25-7-11.
//

#ifndef EDITOR_WIDGET_H
#define EDITOR_WIDGET_H
#include "editor_line_no.h"
#include <QTextEdit>
#include <QWidget>
#include <QScrollBar>
#include <QPainter>
#include <QTextBlock>


namespace HMainLayOut
{
    class HemyEditorWidget : public QTextEdit {
        Q_OBJECT
    public:
        explicit HemyEditorWidget(QWidget *parent = nullptr);
        ~HemyEditorWidget() override = default;

        /*void setLineNumbersVisible(const bool visible);
        // 获取编辑器内容
        int lineNumberAreaWidth() const;*/
        // 获取编辑器内容
        QString editorContent() const {
            return m_textEdit->toPlainText();
        }
    //protected:
        //void resizeEvent(QResizeEvent *event) override;

    /*private slots:
        void updateLineNumberAreaWidth();
        void updateLineNumberArea(const QRect &rect, int dy) const;*/

    private:
        //friend class LineNumberArea;
        QTextEdit *m_textEdit;
        //LineNumberArea* m_lineNumberArea_ = nullptr;
        /*void lineNumberAreaPaintEvent(QPaintEvent *event) const;
        QRectF blockBoundingGeometry(const QTextBlock &block) const;*/
    };
}

#endif //EDITOR_WIDGET_H
