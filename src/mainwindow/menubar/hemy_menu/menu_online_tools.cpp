//
// Created by Administrator on 25-7-5.
//

#include "hemy_menu.h"

namespace HemyMenu
{
    HMenuOnlineTool::HMenuOnlineTool(QWidget *parent): MenuBase(parent) {
        CreateMenuOnlineTool();
    }
    void HMenuOnlineTool::CreateMenuOnlineTool()
    {
        QList<MenuItem> menuItems;
        ParserMenuItems(":/main_menu/online.xml", menuItems);
        // 在这里可以使用 menuItems 构建菜单系统
        buildMenuSystem(this, menuItems);
    }
}