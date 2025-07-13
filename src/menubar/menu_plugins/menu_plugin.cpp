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
        QList<MenuItem> encdecItems = {
            createMenuItem(MenuType::MENU_PLUGIN, MenuItemID::M_PLUGIN_E),
            createMenuItem(MenuType::MENU_PLUGIN, MenuItemID::M_PLUGIN_),
            createMenuItem(MenuType::MENU_PLUGIN, MenuItemID::M_PLUGIN_),
            createMenuItem(MenuType::MENU_PLUGIN, MenuItemID::M_PLUGIN_),
            createMenuItem(MenuType::MENU_PLUGIN, MenuItemID::M_PLUGIN_),
            createMenuItem(MenuType::MENU_PLUGIN, MenuItemID::M_PLUGIN_),
            createMenuItem(MenuType::MENU_PLUGIN, MenuItemID::M_PLUGIN_),
        };

        QList<MenuItem> convertItems = {
            createMenuItem(MenuType::MENU_PLUGIN, MenuItemID::M_PLUGIN_),
            createMenuItem(MenuType::MENU_PLUGIN, MenuItemID::M_PLUGIN_),
            createMenuItem(MenuType::MENU_PLUGIN, MenuItemID::M_PLUGIN_),
            createMenuItem(MenuType::MENU_PLUGIN, MenuItemID::M_PLUGIN_),
            createMenuItem(MenuType::MENU_PLUGIN, MenuItemID::M_PLUGIN_),
            MenuItem::createSeparator(),
            createMenuItem(MenuType::MENU_PLUGIN, MenuItemID::M_PLUGIN_),
            createMenuItem(MenuType::MENU_PLUGIN, MenuItemID::M_PLUGIN_),
            createMenuItem(MenuType::MENU_PLUGIN, MenuItemID::M_PLUGIN_),
            createMenuItem(MenuType::MENU_PLUGIN, MenuItemID::M_PLUGIN_),
            createMenuItem(MenuType::MENU_PLUGIN, MenuItemID::M_PLUGIN_),
            createMenuItem(MenuType::MENU_PLUGIN, MenuItemID::M_PLUGIN_),
        };

        QList<MenuItem> formatItems = {
            createMenuItem(MenuType::MENU_PLUGIN, MenuItemID::M_PLUGIN_),
            createMenuItem(MenuType::MENU_PLUGIN, MenuItemID::M_PLUGIN_),
            createMenuItem(MenuType::MENU_PLUGIN, MenuItemID::M_PLUGIN_),
            createMenuItem(MenuType::MENU_PLUGIN, MenuItemID::M_PLUGIN_),
            createMenuItem(MenuType::MENU_PLUGIN, MenuItemID::M_PLUGIN_),
        };

        QList<MenuItem> netToolsItems = {
            createMenuItem(MenuType::MENU_PLUGIN, MenuItemID::M_PLUGIN_),
            createMenuItem(MenuType::MENU_PLUGIN, MenuItemID::M_PLUGIN_),
            createMenuItem(MenuType::MENU_PLUGIN, MenuItemID::M_PLUGIN_),
            createMenuItem(MenuType::MENU_PLUGIN, MenuItemID::M_PLUGIN_),
            createMenuItem(MenuType::MENU_PLUGIN, MenuItemID::M_PLUGIN_),
            createMenuItem(MenuType::MENU_PLUGIN, MenuItemID::M_PLUGIN_),
            createMenuItem(MenuType::MENU_PLUGIN, MenuItemID::M_PLUGIN_),
        };

        QList<MenuItem> infoCompItems = {
            createMenuItem(MenuType::MENU_PLUGIN, MenuItemID::M_PLUGIN_),
            createMenuItem(MenuType::MENU_PLUGIN, MenuItemID::M_PLUGIN_),
            createMenuItem(MenuType::MENU_PLUGIN, MenuItemID::M_PLUGIN_),
            createMenuItem(MenuType::MENU_PLUGIN, MenuItemID::M_PLUGIN_),
            createMenuItem(MenuType::MENU_PLUGIN, MenuItemID::M_PLUGIN_),
            createMenuItem(MenuType::MENU_PLUGIN, MenuItemID::M_PLUGIN_),
            createMenuItem(MenuType::MENU_PLUGIN, MenuItemID::M_PLUGIN_),
            createMenuItem(MenuType::MENU_PLUGIN, MenuItemID::M_PLUGIN_),
            createMenuItem(MenuType::MENU_PLUGIN, MenuItemID::M_PLUGIN_),
            createMenuItem(MenuType::MENU_PLUGIN, MenuItemID::M_PLUGIN_),
        };

        QList<MenuItem> menuItems = {
            createMenuItem(MenuType::MENU_PLUGIN, MenuItemID::M_PLUGIN_),
            createMenuItem(MenuType::MENU_PLUGIN, MenuItemID::M_PLUGIN_),
            createMenuItem(MenuType::MENU_PLUGIN, MenuItemID::M_PLUGIN_),
            createMenuItem(MenuType::MENU_PLUGIN, MenuItemID::M_PLUGIN_),
            createMenuItem(MenuType::MENU_PLUGIN, MenuItemID::M_PLUGIN_),
        };

        auto actionHandler = [this](const MenuItemID& id, const QString& objName) {
            onPluginMenuActionHandler(id, objName);
        };

        createMenu(this, menuItems, actionHandler);
    }

    void HMenuPlugin::onPluginMenuActionHandler(const MenuItemID& itemId, const QString& objName)
    {
        HDEBUG("ITEM_ID: " + std::to_string(static_cast<int>(itemId))+ ", OBJ: " + objName.toStdString());
    }
}