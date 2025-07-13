//
// Created by Administrator on 25-7-5.
//

#include "menu_help.h"


namespace HemyMenu
{
    HMenuHelp::HMenuHelp(QWidget *parent): MenuBase(parent) {
        InitialHelpMenuItems();
    }
    void HMenuHelp::InitialHelpMenuItems()
    {
        auto actionHandler = [this](const MenuItemID& id, const QString& objName) {
            onHelpMenuActionHandler(id, objName);
        };

        createMenu(this, GetMenuItems(MenuType::MENU_HELP), actionHandler);
    }

    void HMenuHelp::onHelpMenuActionHandler(const MenuItemID& itemId, const QString& objName)
    {
        HDEBUG("ITEM_ID: " + std::to_string(static_cast<int>(itemId))+ ", OBJ: " + objName.toStdString());
    }
}