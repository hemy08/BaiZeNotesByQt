//
// Created by zhaoj on 25-7-11.
//

#ifndef PREVIEW_WIDGET_H
#define PREVIEW_WIDGET_H
#include <QTextBrowser>

namespace HemyUI
{
    class HWorkBenchPreview : public QTextBrowser {
        Q_OBJECT
    public:
        explicit HWorkBenchPreview(QWidget *parent = nullptr);
        ~HWorkBenchPreview() override = default;

        void updatePreview(const QString &content);
    public slots:
        void RenderResult(const QString& content);
    private:
        void Initial();
    };
}


#endif //PREVIEW_WIDGET_H
