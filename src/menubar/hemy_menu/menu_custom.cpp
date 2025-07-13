//
// Created by zhaoj on 25-7-8.
//

#include "hemy_menu.h"


namespace HemyMenu
{
    HMenuCustom::HMenuCustom(QWidget *parent): MenuBase(parent) {
        InitialMenuItems();
    }
    void HMenuCustom::InitialMenuItems()
    {
        auto actionHandler = [this](const MenuItemID& id, const QString& objName) {
            qDebug() << "HMenuCustom::CreateMenuCoding()" << objName;
        };
        QList<MenuItem> menuItems;
        ParserMenuItems(":/main_menu/custom_tools.xml", menuItems);
        // 在这里可以使用 menuItems 构建菜单系统
        buildMenuSystem(this, menuItems, MenuType::MENU_CODING, actionHandler);
    }
}