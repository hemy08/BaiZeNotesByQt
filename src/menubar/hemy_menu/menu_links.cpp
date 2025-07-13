//
// Created by Administrator on 25-7-5.
//

#include "hemy_menu.h"

namespace HemyMenu
{
    HMenuLinks::HMenuLinks(QWidget *parent): MenuBase(parent) {
        InitialMenuItems();

    }
    void HMenuLinks::InitialMenuItems()
    {
        auto actionHandler = [this](const MenuItemID& id, const QString& objName) {
            qDebug() << "HMenuLinks::CreateMenuCoding()" << objName;
        };
        QList<MenuItem> menuItems;
        ParserMenuItems(":/main_menu/links.xml", menuItems);
        // 在这里可以使用 menuItems 构建菜单系统
        buildMenuSystem(this, menuItems, MenuType::MENU_LINK, actionHandler);
    }
}