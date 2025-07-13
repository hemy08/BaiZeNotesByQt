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
        const QList<MenuItem> insertTextItem = {
            createMenuItem(MenuType::MENU_INSERT, MenuItemID::M_INSERT_T_IMAGES),
            createMenuItem(MenuType::MENU_INSERT, MenuItemID::M_INSERT_T_CODEBLOCK),
            createMenuItem(MenuType::MENU_INSERT, MenuItemID::M_INSERT_T_MD_LIST),
            createMenuItem(MenuType::MENU_INSERT, MenuItemID::M_INSERT_T_UPDATE_TIME),
        };

        const QList<MenuItem> insertFromFileItem = {
            createMenuItem(MenuType::MENU_INSERT, MenuItemID::M_INSERT_F_TXT),
            createMenuItem(MenuType::MENU_INSERT, MenuItemID::M_INSERT_F_JSON),
            createMenuItem(MenuType::MENU_INSERT, MenuItemID::M_INSERT_F_INI),
            createMenuItem(MenuType::MENU_INSERT, MenuItemID::M_INSERT_F_YAML),
            createMenuItem(MenuType::MENU_INSERT, MenuItemID::M_INSERT_F_XML),
            createMenuItem(MenuType::MENU_INSERT, MenuItemID::M_INSERT_F_CSV),
            createMenuItem(MenuType::MENU_INSERT, MenuItemID::M_INSERT_F_XLS),
        };
        const QList<MenuItem> menuItems = {
            createMenuItem(MenuType::MENU_INSERT, MenuItemID::M_INSERT_FONT),
            createMenuItem(MenuType::MENU_INSERT, MenuItemID::M_INSERT_KATEX),
            createMenuItem(MenuType::MENU_INSERT, MenuItemID::M_INSERT_MD_TABLE),
            createMenuItem(MenuType::MENU_INSERT, MenuItemID::M_INSERT_WEB_LINK),
            MenuItem::createSeparator(),
            createMenuItems(MenuType::MENU_INSERT, MenuItemID::M_INSERT_TXT, insertTextItem),
            createMenuItems(MenuType::MENU_INSERT, MenuItemID::M_INSERT_FROM_FILE, insertFromFileItem)
        };

        auto actionHandler = [this](const MenuItemID& id, const QString& objName) {
            onInsertMenuActionHandler(id, objName);
        };

        createMenu(this, menuItems, actionHandler);
    }

    void HMenuInsert::onInsertMenuActionHandler(const MenuItemID& itemId, const QString& objName)
    {
        HDEBUG("ITEM_ID: " + std::to_string(static_cast<int>(itemId))+ ", OBJ: " + objName.toStdString());
    }
}