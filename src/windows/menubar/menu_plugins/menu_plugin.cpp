//
// Created by Administrator on 25-7-5.
//

#include "menu_plugin.h"
#include <QMessageBox>

namespace HemyUI
{
    HMenuPlugin::HMenuPlugin(QWidget *parent): MenuBase(parent) {
        InitialMenuItems();

    }
    void HMenuPlugin::InitialMenuItems()
    {
        auto actionHandler = [this](const MenuItemID& id, const QString& objName, const QString& url) {
            MenuActionHandle(id, objName, url);
        };

        QList<MenuItem> menuItems;
        ParserMenuItems(":/main_menu/plugins.xml", menuItems);
        CreateMenu(this, menuItems, actionHandler);
    }

    void HMenuPlugin::MenuActionHandle(const MenuItemID& itemId, const QString& objName, const QString& url)
    {
        LOG_DEBUG("ITEM_ID: ", std::to_string(static_cast<int>(itemId)), ", OBJ: ", objName.toStdString(), ", url: ", url.toStdString());
    }
}