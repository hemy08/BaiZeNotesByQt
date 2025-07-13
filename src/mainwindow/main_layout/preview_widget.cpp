//
// Created by zhaoj on 25-7-11.
//

#include "preview_widget.h"

namespace HMainLayOut
{
    HemyPreviewWidget::HemyPreviewWidget(QWidget *parent) : QTextBrowser(parent) {
        setupUI();
    }

    void HemyPreviewWidget::setupUI() {
        setStyleSheet(
            "HemyPreviewWidget {"
            "   background-color: #f9f9f9;"
            "   border: none;"
            "   padding: 10px;"
            "   font-size: 11pt;"
            "}"
        );
    }

    void HemyPreviewWidget::updatePreview(const QString &content) {
        setHtml(QString("<pre>%1</pre>").arg(content.toHtmlEscaped()));
    }
}