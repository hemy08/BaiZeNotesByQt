//
// Created by Administrator on 25-7-5.
//

#include "hemy_menu.h"
#include "common.h"

namespace HemyMenu
{
    HMenuFile::HMenuFile(QWidget *parent): MenuBase(parent) {
        CreateMenuFile();
    }
    void HMenuFile::CreateMenuFile()
    {
        QList<MenuItem> menuItems;
        ParserMenuItems(":/main_menu/file.xml", menuItems);
        // 在这里可以使用 menuItems 构建菜单系统
        buildMenuSystem(this, menuItems);
    }
}