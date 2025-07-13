//
// Created by zhaoj on 25-7-11.
//

#include "editor_widget.h"

namespace HMainLayOut
{
    HemyEditorWidget::HemyEditorWidget(QWidget *parent) : QPlainTextEdit(parent) {
        setupUI();
    }

    void HemyEditorWidget::setupUI() {
        setStyleSheet(
            "HemyEditorWidget {"
            "   background-color: #ffffff;"
            "   border: none;"
            "   font-family: 'Consolas', monospace;"
            "   font-size: 12pt;"
            "}"
        );
    }

    void HemyEditorWidget::setEditorContent(const QString &content) {
        setPlainText(content);
    }

    QString HemyEditorWidget::editorContent() const {
        return toPlainText();
    }
}