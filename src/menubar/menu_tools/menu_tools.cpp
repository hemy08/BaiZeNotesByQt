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
        QList<MenuItem> menuItems = {
            createMenuItem(MenuType::MENU_TOOLS, MenuItemID::M_TOOL_MERMAID),
            createMenuItem(MenuType::MENU_TOOLS, MenuItemID::M_TOOL_PLANTUML),
            createMenuItem(MenuType::MENU_TOOLS, MenuItemID::M_TOOL_EXECL),
            createMenuItem(MenuType::MENU_TOOLS, MenuItemID::M_TOOL_DRAW),
            createMenuItem(MenuType::MENU_TOOLS, MenuItemID::M_TOOL_KATEX),
        };

        auto actionHandler = [this](const MenuItemID& id, const QString& objName) {
            onToolsMenuActionHandler(id, objName);
        };

        createMenu(this, menuItems, actionHandler);
    }

    void HMenuTools::onToolsMenuActionHandler(const MenuItemID& itemId, const QString& objName)
    {
        HDEBUG("ITEM_ID: " + std::to_string(static_cast<int>(itemId))+ ", OBJ: " + objName.toStdString());
    }
}