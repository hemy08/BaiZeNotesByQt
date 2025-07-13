//
// Created by Administrator on 25-7-5.
//

#include "hemy_menu.h"

namespace HemyMenu
{
    HMenuTools::HMenuTools(QWidget *parent): MenuBase(parent) {
        CreateMenuTools();

    }
    void HMenuTools::CreateMenuTools()
    {
        QList<MenuItem> menuItems;
        ParserMenuItems(":/main_menu/tools.xml", menuItems);
        // 在这里可以使用 menuItems 构建菜单系统
        buildMenuSystem(this, menuItems);
    }
}