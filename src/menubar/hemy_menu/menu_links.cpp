//
// Created by Administrator on 25-7-5.
//

#include "hemy_menu.h"

namespace HemyMenu
{
    HMenuLinks::HMenuLinks(QWidget *parent): MenuBase(parent) {
        InitialLinksMenuItems();

    }
    void HMenuLinks::InitialLinksMenuItems()
    {
        auto actionHandler = [this](const MenuItemID& id, const QString& objName, const QString& url) {
            onLinksMenuActionHandler(id, objName, url);
        };
        QList<MenuItem> menuItems;
        ParserMenuItems(":/main_menu/links.xml", menuItems);
        // 在这里可以使用 menuItems 构建菜单系统
        createMenu(this, menuItems, actionHandler);
    }

    void HMenuLinks::onLinksMenuActionHandler(const MenuItemID& itemId, const QString& objName, const QString& url)
    {
        HDEBUG("ITEM_ID: " + std::to_string(static_cast<int>(itemId))+ ", OBJ: " + objName.toStdString() + ", url: " + url.toStdString());
    }
}