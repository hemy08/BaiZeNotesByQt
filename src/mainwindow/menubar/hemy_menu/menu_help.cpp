//
// Created by Administrator on 25-7-5.
//

#include "hemy_menu.h"


namespace HemyMenu
{
    HMenuHelp::HMenuHelp(QWidget *parent): MenuBase(parent) {
        CreateMenuHelp();
    }
    void HMenuHelp::CreateMenuHelp()
    {
        QList<MenuItem> menuItems;
        ParserMenuItems(":/main_menu/help.xml", menuItems);
        // 在这里可以使用 menuItems 构建菜单系统
        buildMenuSystem(this, menuItems);
    }
}