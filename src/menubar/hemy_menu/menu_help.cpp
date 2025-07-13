//
// Created by Administrator on 25-7-5.
//

#include "hemy_menu.h"


namespace HemyMenu
{
    HMenuHelp::HMenuHelp(QWidget *parent): MenuBase(parent) {
        InitialMenuItems();
    }
    void HMenuHelp::InitialMenuItems()
    {
        auto actionHandler = [this](const MenuItemID& id, const QString& objName) {
            qDebug() << "HMenuHelp::CreateMenuCoding()" << objName;
        };
        QList<MenuItem> menuItems;
        ParserMenuItems(":/main_menu/help.xml", menuItems);
        // 在这里可以使用 menuItems 构建菜单系统
        buildMenuSystem(this, menuItems, MenuType::MENU_HELP, actionHandler);
    }
}