//
// Created by Administrator on 25-7-5.
//

#include "hemy_menu.h"

namespace HemyMenu
{
    HMenuOnlineTool::HMenuOnlineTool(QWidget *parent): MenuBase(parent) {
        InitialOnlineMenuItems();
    }
    void HMenuOnlineTool::InitialOnlineMenuItems()
    {
        auto actionHandler = [this](const MenuItemID& id, const QString& objName, const QString& url) {
            onOnlineMenuActionHandler(id, objName, url);
        };
        QList<MenuItem> menuItems;
        ParserMenuItems(":/main_menu/online.xml", menuItems);
        // 在这里可以使用 menuItems 构建菜单系统
        createMenu(this, menuItems, actionHandler);
    }

    void HMenuOnlineTool::onOnlineMenuActionHandler(const MenuItemID& itemId, const QString& objName, const QString& url)
    {
        HDEBUG("ITEM_ID: " + std::to_string(static_cast<int>(itemId))+ ", OBJ: " + objName.toStdString() + ", url: " + url.toStdString());
    }
}