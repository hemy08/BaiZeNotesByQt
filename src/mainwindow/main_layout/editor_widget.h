//
// Created by zhaoj on 25-7-11.
//

#ifndef EDITOR_WIDGET_H
#define EDITOR_WIDGET_H
#include <QPlainTextEdit>

namespace HMainLayOut
{
    class HemyEditorWidget : public QPlainTextEdit {
        Q_OBJECT
    public:
        explicit HemyEditorWidget(QWidget *parent = nullptr);
        ~HemyEditorWidget() override = default;

        void setEditorContent(const QString &content);
        QString editorContent() const;

    private:
        void setupUI();
    };
}

#endif //EDITOR_WIDGET_H
