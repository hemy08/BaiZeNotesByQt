//
// Created by zhaoj on 25-7-11.
//

#ifndef SIDEBAR_WIDGET_H
#define SIDEBAR_WIDGET_H
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>

namespace HMainLayOut
{
    class HemySidebarWidget : public QFrame {
        Q_OBJECT
    public:
        explicit HemySidebarWidget(QWidget *parent = nullptr);
        ~HemySidebarWidget() override = default;

        void addNavigationButton(const QString &text);
        void setWidthRange(int min, int max);

        signals:
            void buttonClicked(const QString &buttonText);

    private:
        void setupUI();

        QVBoxLayout *m_sidebar_layout;
    };
}

#endif //SIDEBAR_WIDGET_H
