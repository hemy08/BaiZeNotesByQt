//
// Created by Administrator on 25-7-5.
//

#include "menu_tools.h"

namespace HemyMenu
{
    HMenuTools::HMenuTools(QWidget *parent): MenuBase(parent) {
        InitialToolsMenuItems();

    }
    void HMenuTools::InitialToolsMenuItems()
    {
        auto actionHandler = [this](const MenuItemID& id, const QString& objName) {
            onToolsMenuActionHandler(id, objName);
        };

        createMenu(this, GetMenuItems(MenuType::MENU_TOOLS), actionHandler);
    }

    void HMenuTools::onToolsMenuActionHandler(const MenuItemID& itemId, const QString& objName)
    {
        HDEBUG("ITEM_ID: " + std::to_string(static_cast<int>(itemId))+ ", OBJ: " + objName.toStdString());
    }
}