//
// Created by zhaoj on 25-7-11.
//

#ifndef EDITOR_MENU_WIDGET_H
#define EDITOR_MENU_WIDGET_H
#include <QWidget>
#include <QHBoxLayout>
#include <QToolButton>

namespace HemyUI
{
    class HWorkBenchMenu : public QWidget {
        Q_OBJECT
    public:
        explicit HWorkBenchMenu(QWidget *parent = nullptr);
        ~HWorkBenchMenu() override = default;

        void addToolButton(const QIcon &icon, const QString &tooltip);
    private:
        void setupUI();

        QHBoxLayout *m_content_layout = nullptr;
    };
}

#endif //EDITOR_MENU_WIDGET_H
