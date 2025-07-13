//
// Created by Administrator on 25-7-5.
//

#include "menu_insert.h"

namespace HemyMenu
{
    HMenuInsert::HMenuInsert(QWidget *parent): MenuBase(parent) {
        InitialInsertMenuItems();

    }
    void HMenuInsert::InitialInsertMenuItems()
    {
        auto actionHandler = [this](const MenuItemID& id, const QString& objName) {
            onInsertMenuActionHandler(id, objName);
        };

        createMenu(this, GetMenuItems(MenuType::MENU_INSERT), actionHandler);
    }

    void HMenuInsert::onInsertMenuActionHandler(const MenuItemID& itemId, const QString& objName)
    {
        HDEBUG("ITEM_ID: " + std::to_string(static_cast<int>(itemId))+ ", OBJ: " + objName.toStdString());
    }
}