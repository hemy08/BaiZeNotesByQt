//
// Created by zhaoj on 25-7-11.
//

#include "workbench_preview.h"

#include "default.h"
#include "hemy_debug.h"
#include "hmain_window.h"

namespace HemyUI
{
    HWorkBenchPreview::HWorkBenchPreview(QWidget *parent) : QTextBrowser(parent) {
        this->setObjectName("HWorkBenchPreview");
        Initial();
    }

    void HWorkBenchPreview::Initial() {
        connect(HMainWindow::GetInst(), &HMainWindow::SgPlainTextRenderResult, this, RenderResult);
    }

    void HWorkBenchPreview::updatePreview(const QString &content) {
        setMarkdown(content);
    }

    void HWorkBenchPreview::RenderResult(const QString &content) {
        LOG_INFO("RenderResult ", content.toUtf8().constData());
        updatePreview(content);
    }
}
