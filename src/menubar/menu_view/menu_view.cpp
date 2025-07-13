//
// Created by Administrator on 25-7-5.
//

#include "menu_view.h"


namespace HemyMenu
{
    HMenuView::HMenuView(QWidget *parent): MenuBase(parent) {
        InitialViewMenuItems();

    }
    void HMenuView::InitialViewMenuItems()
    {
        const QList<MenuItem> expandItems = {
            createMenuItem(MenuType::MENU_VIEW, MenuItemID::M_VIEW_EXPAND_1),
            createMenuItem(MenuType::MENU_VIEW, MenuItemID::M_VIEW_EXPAND_2),
            createMenuItem(MenuType::MENU_VIEW, MenuItemID::M_VIEW_EXPAND_3),
            createMenuItem(MenuType::MENU_VIEW, MenuItemID::M_VIEW_EXPAND_4),
            createMenuItem(MenuType::MENU_VIEW, MenuItemID::M_VIEW_EXPAND_5),
            createMenuItem(MenuType::MENU_VIEW, MenuItemID::M_VIEW_EXPAND_6),
        };

        const QList<MenuItem> foldItems = {
            createMenuItem(MenuType::MENU_VIEW, MenuItemID::M_VIEW_FOLD_1),
            createMenuItem(MenuType::MENU_VIEW, MenuItemID::M_VIEW_FOLD_2),
            createMenuItem(MenuType::MENU_VIEW, MenuItemID::M_VIEW_FOLD_3),
            createMenuItem(MenuType::MENU_VIEW, MenuItemID::M_VIEW_FOLD_4),
            createMenuItem(MenuType::MENU_VIEW, MenuItemID::M_VIEW_FOLD_5),
            createMenuItem(MenuType::MENU_VIEW, MenuItemID::M_VIEW_FOLD_6),
        };

        const QList<MenuItem> menuItems = {
            createMenuItem(MenuType::MENU_VIEW, MenuItemID::M_VIEW_EDIT_MOD),
            createMenuItem(MenuType::MENU_VIEW, MenuItemID::M_VIEW_PREVIEW_MOD),
            createMenuItem(MenuType::MENU_VIEW, MenuItemID::M_VIEW_EDIT_PREVIEW),
            MenuItem::createSeparator(),
            createMenuItem(MenuType::MENU_VIEW, MenuItemID::M_VIEW_SHOW_EXPLORER),
            createMenuItem(MenuType::MENU_VIEW, MenuItemID::M_VIEW_SHOW_TOC),
            createMenuItem(MenuType::MENU_VIEW, MenuItemID::M_VIEW_SHOW_LINE_NO),
            createMenuItem(MenuType::MENU_VIEW, MenuItemID::M_VIEW_SHOW_LINE_BREAK),
            createMenuItem(MenuType::MENU_VIEW, MenuItemID::M_VIEW_SHOW_SPACE),
            createMenuItem(MenuType::MENU_VIEW, MenuItemID::M_VIEW_SHOW_ALL),
            MenuItem::createSeparator(),
            createMenuItem(MenuType::MENU_VIEW, MenuItemID::M_VIEW_EXPAND_ALL),
            createMenuItem(MenuType::MENU_VIEW, MenuItemID::M_VIEW_FOLD_ALL),
            createMenuItem(MenuType::MENU_VIEW, MenuItemID::M_VIEW_EXPAND_CUR),
            createMenuItem(MenuType::MENU_VIEW, MenuItemID::M_VIEW_FOLD_CUR),
            MenuItem::createSeparator(),
            createMenuItems(MenuType::MENU_VIEW, MenuItemID::M_VIEW_EXPAND, expandItems),
            createMenuItems(MenuType::MENU_VIEW, MenuItemID::M_VIEW_FOLD, foldItems),
        };

        auto actionHandler = [this](const MenuItemID& id, const QString& objName) {
            onViewMenuActionHandler(id, objName);
        };

        createMenu(this, menuItems, actionHandler);
    }

    void HMenuView::onViewMenuActionHandler(const MenuItemID& itemId, const QString& objName)
    {
        HDEBUG("ITEM_ID: " + std::to_string(static_cast<int>(itemId))+ ", OBJ: " + objName.toStdString());
    }
}