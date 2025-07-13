//
// Created by zhaoj on 25-7-11.
//

#ifndef EDITOR_MENU_WIDGET_H
#define EDITOR_MENU_WIDGET_H
#include <QWidget>
#include <QHBoxLayout>
#include <QToolButton>

namespace HMainLayOut
{
    class HemyContentMenuWidget : public QWidget {
        Q_OBJECT
    public:
        explicit HemyContentMenuWidget(QWidget *parent = nullptr);
        ~HemyContentMenuWidget() override = default;

        void addToolButton(const QIcon &icon, const QString &tooltip);
    private:
        void setupUI();

        QHBoxLayout *m_layout;
    };
}

#endif //EDITOR_MENU_WIDGET_H
