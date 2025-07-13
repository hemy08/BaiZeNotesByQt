//
// Created by Administrator on 25-7-5.
//

#include "menu_edit.h"

namespace HemyMenu
{
    HMenuEdit::HMenuEdit(QWidget *parent): MenuBase(parent) {
        InitialEditMenuItems();
    }
    void HMenuEdit::InitialEditMenuItems()
    {
        auto actionHandler = [this](const MenuItemID& id, const QString& objName) {
            onEditMenuActionHandler(id, objName);
        };

        createMenu(this, GetMenuItems(MenuType::MENU_EDIT), actionHandler);
    }

    void HMenuEdit::onEditMenuActionHandler(const MenuItemID& itemId, const QString& objName)
    {
        HDEBUG("ITEM_ID: " + std::to_string(static_cast<int>(itemId))+ ", OBJ: " + objName.toStdString());
    }
}