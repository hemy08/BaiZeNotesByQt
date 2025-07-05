//
// Created by Administrator on 25-7-5.
//

#ifndef MD_EDITOR_BY_QT_MENU_BASE_H
#define MD_EDITOR_BY_QT_MENU_BASE_H
#include <QMenu>
#include "common.h"

namespace HemyMenu {
    class MenuBase : public QMenu {
    public:
        explicit MenuBase(QWidget *parent = nullptr);
        explicit MenuBase(const QString &title, QWidget *parent = nullptr);
        ~MenuBase() override = default;

        QAction* createAction(const MenuItemAttr& menuItem);
    };
}

#endif //MD_EDITOR_BY_QT_MENU_BASE_H
