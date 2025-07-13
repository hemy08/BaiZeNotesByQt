//
// Created by Administrator on 25-7-5.
//

#include "hemy_menu.h"

namespace HemyMenu
{
    HMenuEdit::HMenuEdit(QWidget *parent): MenuBase(parent) {
        CreateMenuEdit();
    }
    void HMenuEdit::CreateMenuEdit()
    {
        QList<MenuItem> menuItems;
        ParserMenuItems(":/main_menu/edit.xml", menuItems);
        // 在这里可以使用 menuItems 构建菜单系统
        buildMenuSystem(this, menuItems);
    }
}