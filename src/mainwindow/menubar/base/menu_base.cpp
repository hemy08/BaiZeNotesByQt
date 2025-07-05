//
// Created by Administrator on 25-7-5.
//

#include "menu_base.h"

namespace HemyMenu {
    MenuBase::MenuBase(QWidget *parent): QMenu(parent) {

    }

    MenuBase::MenuBase(const QString &title, QWidget *parent): QMenu(title, parent) {

    }

    QAction* MenuBase::createAction(const MenuItemAttr& menuItem) {
        QAction* action = addAction(menuItem.label);
        action->setObjectName(menuItem.obj_name);
        action->setShortcut(menuItem.shortcut);
        return action;
    }
}