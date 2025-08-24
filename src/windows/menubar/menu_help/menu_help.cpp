//
// Created by Administrator on 25-7-5.
//

#include "menu_help.h"


namespace HemyUI
{
    HMenuHelp::HMenuHelp(QWidget *parent): MenuBase(parent) {
        InitialMenuItems();
    }
    void HMenuHelp::InitialMenuItems()
    {
        auto actionHandler = [this](const MenuItemID& id, const QString& objName) {
            MenuActionHandle(id, objName);
        };

        CreateMenu(this, GetMenuItems(MenuType::MENU_HELP), actionHandler);
    }

    void HMenuHelp::MenuActionHandle(const MenuItemID& itemId, const QString& objName)
    {
        LOG_DEBUG("ITEM_ID: ", std::to_string(static_cast<int>(itemId)), ", OBJ: ", objName.toStdString());
    }
}