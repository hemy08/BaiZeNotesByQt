//
// Created by Administrator on 25-7-5.
//

#include "menu_setting.h"

namespace HemyMenu
{
    HMenuSetting::HMenuSetting(QWidget *parent): MenuBase(parent) {
        InitialSettingMenuItems();

    }
    void HMenuSetting::InitialSettingMenuItems()
    {
        QList<MenuItem> menuItems = {
            createMenuItem(MenuType::MENU_SETTING, MenuItemID::M_SETTING_SYSTEM),
            createMenuItem(MenuType::MENU_SETTING, MenuItemID::M_SETTING_THEME),
            createMenuItem(MenuType::MENU_SETTING, MenuItemID::M_SETTING_QUICK),
            createMenuItem(MenuType::MENU_SETTING, MenuItemID::M_SETTING_EDITOR),
            createMenuItem(MenuType::MENU_SETTING, MenuItemID::M_SETTING_MD_PARSE),
            createMenuItem(MenuType::MENU_SETTING, MenuItemID::M_SETTING_SHORTCUT),
        };

        auto actionHandler = [this](const MenuItemID& id, const QString& objName) {
            onSettingMenuActionHandler(id, objName);
        };

        createMenu(this, menuItems, actionHandler);
    }

    void HMenuSetting::onSettingMenuActionHandler(const MenuItemID& itemId, const QString& objName)
    {
        HDEBUG("ITEM_ID: " + std::to_string(static_cast<int>(itemId))+ ", OBJ: " + objName.toStdString());
    }
}