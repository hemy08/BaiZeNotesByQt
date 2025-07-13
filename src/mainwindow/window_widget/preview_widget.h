//
// Created by zhaoj on 25-7-11.
//

#ifndef PREVIEW_WIDGET_H
#define PREVIEW_WIDGET_H
#include <QTextBrowser>

namespace HMainLayOut
{
    class HemyPreviewWidget : public QTextBrowser {
        Q_OBJECT
    public:
        explicit HemyPreviewWidget(QWidget *parent = nullptr);
        ~HemyPreviewWidget() override = default;

        void updatePreview(const QString &content);
    private:
        void setupUI();
    };
}


#endif //PREVIEW_WIDGET_H
