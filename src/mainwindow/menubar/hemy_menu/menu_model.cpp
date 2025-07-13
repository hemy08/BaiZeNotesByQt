//
// Created by zhaoj on 25-7-7.
//

#include "hemy_menu.h"


namespace HemyMenu
{
    HMenuModel::HMenuModel(QWidget *parent): MenuBase(parent) {
        CreateMenuModel();

    }
    void HMenuModel::CreateMenuModel()
    {
        QList<MenuItem> menuItems;
        ParserMenuItems(":/main_menu/model.xml", menuItems);
        // 在这里可以使用 menuItems 构建菜单系统
        buildMenuSystem(this, menuItems);
    }
}