//
// Created by Administrator on 25-7-5.
//

#include "hemy_menu.h"

namespace HemyMenu
{
    HMenuInsert::HMenuInsert(QWidget *parent): MenuBase(parent) {
        CreateMenuInsert();

    }
    void HMenuInsert::CreateMenuInsert()
    {
        QList<MenuItem> menuItems;
        ParserMenuItems(":/main_menu/insert.xml", menuItems);
        // 在这里可以使用 menuItems 构建菜单系统
        buildMenuSystem(this, menuItems);
    }
}