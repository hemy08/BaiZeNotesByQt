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
        const QList<MenuItem> materialItems = {
            createMenuItem(MenuType::MENU_MODEL, MenuItemID::M_MODEL_M_ADMONITION),
        };

        const QList<MenuItem> mermaidItems = {
            createMenuItem(MenuType::MENU_MODEL, MenuItemID::M_MODEL_ME_BASE),
            createMenuItem(MenuType::MENU_MODEL, MenuItemID::M_MODEL_ME_FLOWCHAT),
            createMenuItem(MenuType::MENU_MODEL, MenuItemID::M_MODEL_ME_SEQUENCE),
            createMenuItem(MenuType::MENU_MODEL, MenuItemID::M_MODEL_ME_CLASS),
            createMenuItem(MenuType::MENU_MODEL, MenuItemID::M_MODEL_ME_STATE),
            createMenuItem(MenuType::MENU_MODEL, MenuItemID::M_MODEL_ME_ENTITY),
            createMenuItem(MenuType::MENU_MODEL, MenuItemID::M_MODEL_ME_USER_JOURNEY),
            createMenuItem(MenuType::MENU_MODEL, MenuItemID::M_MODEL_ME_GANTT),
            createMenuItem(MenuType::MENU_MODEL, MenuItemID::M_MODEL_ME_PIE),
            createMenuItem(MenuType::MENU_MODEL, MenuItemID::M_MODEL_ME_QUADRANT),
            createMenuItem(MenuType::MENU_MODEL, MenuItemID::M_MODEL_ME_REQUIREMENT),
            createMenuItem(MenuType::MENU_MODEL, MenuItemID::M_MODEL_ME_GIT),
            createMenuItem(MenuType::MENU_MODEL, MenuItemID::M_MODEL_ME_C4),
            createMenuItem(MenuType::MENU_MODEL, MenuItemID::M_MODEL_ME_MINDMAP),
            createMenuItem(MenuType::MENU_MODEL, MenuItemID::M_MODEL_ME_TIMELINE),
            createMenuItem(MenuType::MENU_MODEL, MenuItemID::M_MODEL_ME_ZEN_UML),
            createMenuItem(MenuType::MENU_MODEL, MenuItemID::M_MODEL_ME_SANKEY),
            createMenuItem(MenuType::MENU_MODEL, MenuItemID::M_MODEL_ME_XY_CHART),
            createMenuItem(MenuType::MENU_MODEL, MenuItemID::M_MODEL_ME_BLOCK),
            createMenuItem(MenuType::MENU_MODEL, MenuItemID::M_MODEL_ME_PACKET),
            createMenuItem(MenuType::MENU_MODEL, MenuItemID::M_MODEL_ME_KANBAN),
            createMenuItem(MenuType::MENU_MODEL, MenuItemID::M_MODEL_ME_ARCHITECTURE),
            createMenuItem(MenuType::MENU_MODEL, MenuItemID::M_MODEL_ME_RADAR),
            createMenuItem(MenuType::MENU_MODEL, MenuItemID::M_MODEL_ME_TREEMAP),
        };

        const QList<MenuItem> plantumlItems = {
            createMenuItem(MenuType::MENU_MODEL, MenuItemID::M_MODEL_PL_BASE),
            createMenuItem(MenuType::MENU_MODEL, MenuItemID::M_MODEL_PL_SEQUENCE),
            createMenuItem(MenuType::MENU_MODEL, MenuItemID::M_MODEL_PL_USE_CASE),
            createMenuItem(MenuType::MENU_MODEL, MenuItemID::M_MODEL_PL_CLASS),
            createMenuItem(MenuType::MENU_MODEL, MenuItemID::M_MODEL_PL_ACTIVITY),
            createMenuItem(MenuType::MENU_MODEL, MenuItemID::M_MODEL_PL_COMP),
            createMenuItem(MenuType::MENU_MODEL, MenuItemID::M_MODEL_PL_STATE),
            createMenuItem(MenuType::MENU_MODEL, MenuItemID::M_MODEL_PL_OBJECT),
            createMenuItem(MenuType::MENU_MODEL, MenuItemID::M_MODEL_PL_TIMING),
            createMenuItem(MenuType::MENU_MODEL, MenuItemID::M_MODEL_PL_REGEX),
            createMenuItem(MenuType::MENU_MODEL, MenuItemID::M_MODEL_PL_NWDIAG),
            createMenuItem(MenuType::MENU_MODEL, MenuItemID::M_MODEL_PL_SALT),
            createMenuItem(MenuType::MENU_MODEL, MenuItemID::M_MODEL_PL_ARCHI_MATE),
            createMenuItem(MenuType::MENU_MODEL, MenuItemID::M_MODEL_PL_GANTT),
            createMenuItem(MenuType::MENU_MODEL, MenuItemID::M_MODEL_PL_CHRONOLOGY),
            createMenuItem(MenuType::MENU_MODEL, MenuItemID::M_MODEL_PL_MINDMAP),
            createMenuItem(MenuType::MENU_MODEL, MenuItemID::M_MODEL_PL_WBS),
            createMenuItem(MenuType::MENU_MODEL, MenuItemID::M_MODEL_PL_EBNF),
            createMenuItem(MenuType::MENU_MODEL, MenuItemID::M_MODEL_PL_JSON),
            createMenuItem(MenuType::MENU_MODEL, MenuItemID::M_MODEL_PL_YAML),
            createMenuItem(MenuType::MENU_MODEL, MenuItemID::M_MODEL_PL_SDL),
            createMenuItem(MenuType::MENU_MODEL, MenuItemID::M_MODEL_PL_ASCII_MATH),
            createMenuItem(MenuType::MENU_MODEL, MenuItemID::M_MODEL_PL_DITAA),
            createMenuItem(MenuType::MENU_MODEL, MenuItemID::M_MODEL_PL_ENTITY),
            createMenuItem(MenuType::MENU_MODEL, MenuItemID::M_MODEL_PL_INFO_ENG),
        };

        const QList<MenuItem> writeItems = {
            createMenuItem(MenuType::MENU_MODEL, MenuItemID::M_MODEL_W_LEETCODE),
            createMenuItem(MenuType::MENU_MODEL, MenuItemID::M_MODEL_W_QUESTION),
            createMenuItem(MenuType::MENU_MODEL, MenuItemID::M_MODEL_W_COVER),
            createMenuItem(MenuType::MENU_MODEL, MenuItemID::M_MODEL_W_PAPER),
        };
        const QList<MenuItem> menuItems = {
            createMenuItems(MenuType::MENU_MODEL, MenuItemID::M_MODEL_MATERIAL, materialItems),
            createMenuItems(MenuType::MENU_MODEL, MenuItemID::M_MODEL_MERMAID, mermaidItems),
            createMenuItems(MenuType::MENU_MODEL, MenuItemID::M_MODEL_PLANTUML, plantumlItems),
            MenuItem::createSeparator(),
            createMenuItems(MenuType::MENU_MODEL, MenuItemID::M_MODEL_WRITE_MODEL, writeItems),
            MenuItem::createSeparator(),
            createMenuItem(MenuType::MENU_MODEL, MenuItemID::M_MODEL_CUSTOM_MODEL),
            createMenuItem(MenuType::MENU_MODEL, MenuItemID::M_MODEL_CUSTOM_MANAGE),
        };

        auto actionHandler = [this](const MenuItemID& id, const QString& objName) {
            onModelMenuActionHandler(id, objName);
        };

        createMenu(this, menuItems, actionHandler);
    }

    void HMenuModel::onModelMenuActionHandler(const MenuItemID& itemId, const QString& objName)
    {
        HDEBUG("ITEM_ID: " + std::to_string(static_cast<int>(itemId))+ ", OBJ: " + objName.toStdString());
    }
}