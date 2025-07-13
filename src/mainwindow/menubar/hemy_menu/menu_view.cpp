//
// Created by Administrator on 25-7-5.
//

#include "hemy_menu.h"


namespace HemyMenu
{
    HMenuView::HMenuView(QWidget *parent): MenuBase(parent) {
        CreateMenuView();

    }
    void HMenuView::CreateMenuView()
    {
        QList<MenuItem> menuItems;
        ParserMenuItems(":/main_menu/view.xml", menuItems);
        // 在这里可以使用 menuItems 构建菜单系统
        buildMenuSystem(this, menuItems);
    }
}