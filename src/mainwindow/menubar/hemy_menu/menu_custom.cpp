//
// Created by zhaoj on 25-7-8.
//

#include "hemy_menu.h"


namespace HemyMenu
{
    HMenuCustom::HMenuCustom(QWidget *parent): MenuBase(parent) {
        CreateMenuCustom();
    }
    void HMenuCustom::CreateMenuCustom()
    {
        QList<MenuItem> menuItems;
        ParserMenuItems(":/main_menu/custom_tools.xml", menuItems);
        // 在这里可以使用 menuItems 构建菜单系统
        buildMenuSystem(this, menuItems);
    }
}