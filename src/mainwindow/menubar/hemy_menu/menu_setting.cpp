//
// Created by Administrator on 25-7-5.
//

#include "hemy_menu.h"

namespace HemyMenu
{
    HMenuSetting::HMenuSetting(QWidget *parent): MenuBase(parent) {
        CreateMenuSettings();

    }
    void HMenuSetting::CreateMenuSettings()
    {
        QList<MenuItem> menuItems;
        ParserMenuItems(":/main_menu/settings.xml", menuItems);
        // 在这里可以使用 menuItems 构建菜单系统
        buildMenuSystem(this, menuItems);
    }
}