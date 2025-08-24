//
// Created by Administrator on 25-7-5.
//

#include "menu_tools.h"

namespace HemyUI
{
    HMenuTools::HMenuTools(QWidget *parent): MenuBase(parent) {
        InitialMenuItems();

    }
    void HMenuTools::InitialMenuItems()
    {
        auto actionHandler = [this](const MenuItemID& id, const QString& objName) {
            MenuActionHandle(id, objName);
        };

        CreateMenu(this, GetMenuItems(MenuType::MENU_TOOLS), actionHandler);
    }

    void HMenuTools::MenuActionHandle(const MenuItemID& itemId, const QString& objName)
    {
        LOG_DEBUG("ITEM_ID: ", std::to_string(static_cast<int>(itemId)), ", OBJ: ", objName.toStdString());
    }
}