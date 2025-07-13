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
        QList<MenuItem> menuItems = {
            createMenuItem(MenuType::MENU_EDIT, MenuItemID::M_EDIT_UNDO),
            createMenuItem(MenuType::MENU_EDIT, MenuItemID::M_EDIT_REDO),
            MenuItem::createSeparator(),
            createMenuItem(MenuType::MENU_EDIT, MenuItemID::M_EDIT_COPY),
            createMenuItem(MenuType::MENU_EDIT, MenuItemID::M_EDIT_CUT),
            createMenuItem(MenuType::MENU_EDIT, MenuItemID::M_EDIT_PASTE),
            MenuItem::createSeparator(),
            createMenuItem(MenuType::MENU_EDIT, MenuItemID::M_EDIT_FIND_FILE),
            createMenuItem(MenuType::MENU_EDIT, MenuItemID::M_EDIT_REPLACE_FILE),
            createMenuItem(MenuType::MENU_EDIT, MenuItemID::M_EDIT_FIND_DIR),
            createMenuItem(MenuType::MENU_EDIT, MenuItemID::M_EDIT_REPLACE_DIR),
            createMenuItem(MenuType::MENU_EDIT, MenuItemID::M_EDIT_GO_LINE),
        };

        auto actionHandler = [this](const MenuItemID& id, const QString& objName) {
            onEditMenuActionHandler(id, objName);
        };

        createMenu(this, menuItems, actionHandler);
    }

    void HMenuEdit::onEditMenuActionHandler(const MenuItemID& itemId, const QString& objName)
    {
        HDEBUG("ITEM_ID: " + std::to_string(static_cast<int>(itemId))+ ", OBJ: " + objName.toStdString());
    }
}