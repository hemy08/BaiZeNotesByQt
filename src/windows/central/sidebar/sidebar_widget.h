//
// Created by zhaoj on 25-7-11.
//

#ifndef SIDEBAR_WIDGET_H
#define SIDEBAR_WIDGET_H
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>

namespace HemyUI
{
    class HSidebar : public QFrame {
        Q_OBJECT
    public:
        explicit HSidebar(QWidget *parent = nullptr);
        ~HSidebar() override = default;

        void addNavigationButton(const QString &text);
        void setWidthRange(const int min, const int max);

        signals:
            void buttonClicked(const QString &buttonText);

    private:
        void Initial();

        QVBoxLayout *m_sidebar_layout{};
        QLabel *title{};
    };
}

#endif //SIDEBAR_WIDGET_H
