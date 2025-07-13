//
// Created by zhaoj on 25-7-7.
//

#include "menu_model.h"


namespace HemyMenu
{
    HMenuModel::HMenuModel(QWidget *parent): MenuBase(parent) {
        InitialModelMenuItems();

    }
    void HMenuModel::InitialModelMenuItems()
    {
        auto actionHandler = [this](const MenuItemID& id, const QString& objName) {
            onModelMenuActionHandler(id, objName);
        };

        createMenu(this, GetMenuItems(MenuType::MENU_MODEL), actionHandler);
    }

    void HMenuModel::onModelMenuActionHandler(const MenuItemID& itemId, const QString& objName)
    {
        HDEBUG("ITEM_ID: " + std::to_string(static_cast<int>(itemId))+ ", OBJ: " + objName.toStdString());
    }
}