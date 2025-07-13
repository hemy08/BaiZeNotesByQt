//
// Created by Administrator on 25-7-5.
//

#include "hemy_menu.h"
#include <QMessageBox>

namespace HemyMenu
{
    HMenuPlugin::HMenuPlugin(QWidget *parent): MenuBase(parent) {
        CreateMenuPlugin();

    }
    void HMenuPlugin::CreateMenuPlugin()
    {
        QList<MenuItem> menuItems;
        ParserMenuItems(":/main_menu/plugins.xml", menuItems);
        // 在这里可以使用 menuItems 构建菜单系统
        buildMenuSystem(this, menuItems);
    }
}