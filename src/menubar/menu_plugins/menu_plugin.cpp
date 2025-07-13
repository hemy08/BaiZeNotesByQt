//
// Created by Administrator on 25-7-5.
//

#include "menu_plugin.h"
#include <QMessageBox>

namespace HemyMenu
{
    HMenuPlugin::HMenuPlugin(QWidget *parent): MenuBase(parent) {
        InitialPluginMenuItems();

    }
    void HMenuPlugin::InitialPluginMenuItems()
    {
        auto actionHandler = [this](const MenuItemID& id, const QString& objName, const QString& url) {
            onPluginMenuActionHandler(id, objName, url);
        };

        QList<MenuItem> menuItems;
        ParserMenuItems(":/main_menu/plugins.xml", menuItems);
        createMenu(this, menuItems, actionHandler);
    }

    void HMenuPlugin::onPluginMenuActionHandler(const MenuItemID& itemId, const QString& objName, const QString& url)
    {
        HDEBUG("ITEM_ID: " + std::to_string(static_cast<int>(itemId))+ ", OBJ: " + objName.toStdString() + ", url: " + url.toStdString());
    }
}