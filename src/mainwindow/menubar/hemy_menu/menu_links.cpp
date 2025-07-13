//
// Created by Administrator on 25-7-5.
//

#include "hemy_menu.h"

namespace HemyMenu
{
    HMenuLinks::HMenuLinks(QWidget *parent): MenuBase(parent) {
        CreateMenuLinks();

    }
    void HMenuLinks::CreateMenuLinks()
    {
        QList<MenuItem> menuItems;
        ParserMenuItems(":/main_menu/links.xml", menuItems);
        // 在这里可以使用 menuItems 构建菜单系统
        buildMenuSystem(this, menuItems);
    }
}