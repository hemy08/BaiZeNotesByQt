//
// Created by Administrator on 25-7-5.
//

#include "menu_coding.h"

namespace HemyMenu
{
    HMenuCoding::HMenuCoding(QWidget *parent): MenuBase(parent) {
        InitialCodingMenuItems();
    }
    void HMenuCoding::InitialCodingMenuItems()
    {
        auto actionHandler = [this](const MenuItemID& id, const QString& objName) {
            onCodingMenuActionHandler(id, objName);
        };

        createMenu(this, GetMenuItems(MenuType::MENU_CODING), actionHandler);
    }

    void HMenuCoding::onCodingMenuActionHandler(const MenuItemID& itemId, const QString& objName)
    {
        HDEBUG("ITEM_ID: " + std::to_string(static_cast<int>(itemId))+ ", OBJ: " + objName.toStdString());
    }
}