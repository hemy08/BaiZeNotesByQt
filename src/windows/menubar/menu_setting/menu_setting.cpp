//
// Created by Administrator on 25-7-5.
//

#include "menu_setting.h"

namespace HemyUI
{
    HMenuSetting::HMenuSetting(QWidget *parent): MenuBase(parent) {
        InitialMenuItems();

    }
    void HMenuSetting::InitialMenuItems()
    {
        auto actionHandler = [this](const MenuItemID& id, const QString& objName) {
            MenuActionHandle(id, objName);
        };

        CreateMenu(this, GetMenuItems(MenuType::MENU_SETTING), actionHandler);
    }

    void HMenuSetting::MenuActionHandle(const MenuItemID& itemId, const QString& objName)
    {
        LOG_DEBUG("ITEM_ID: ", std::to_string(static_cast<int>(itemId)), ", OBJ: ", objName.toStdString());
    }
}