//
// Created by zhaoj on 25-7-7.
//

#include "menu_model.h"


namespace HemyUI
{
    HMenuModel::HMenuModel(QWidget *parent): MenuBase(parent) {
        InitialMenuItems();

    }
    void HMenuModel::InitialMenuItems()
    {
        auto actionHandler = [this](const MenuItemID& id, const QString& objName) {
            MenuActionHandle(id, objName);
        };

        CreateMenu(this, GetMenuItems(MenuType::MENU_MODEL), actionHandler);
    }

    void HMenuModel::MenuActionHandle(const MenuItemID& itemId, const QString& objName)
    {
        LOG_DEBUG("ITEM_ID: ", std::to_string(static_cast<int>(itemId)), ", OBJ: ", objName.toStdString());
    }
}