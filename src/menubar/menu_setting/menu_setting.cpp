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
        auto actionHandler = [this](const MenuItemID& id, const QString& objName) {
            onSettingMenuActionHandler(id, objName);
        };

        createMenu(this, GetMenuItems(MenuType::MENU_SETTING), actionHandler);
    }

    void HMenuSetting::onSettingMenuActionHandler(const MenuItemID& itemId, const QString& objName)
    {
        HDEBUG("ITEM_ID: " + std::to_string(static_cast<int>(itemId))+ ", OBJ: " + objName.toStdString());
    }
}