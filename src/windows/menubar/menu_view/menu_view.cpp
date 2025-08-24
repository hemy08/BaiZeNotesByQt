//
// Created by Administrator on 25-7-5.
//

#include "menu_view.h"


namespace HemyUI
{
    HMenuView::HMenuView(QWidget *parent): MenuBase(parent) {
        InitialMenuItems();

    }
    void HMenuView::InitialMenuItems()
    {
        auto actionHandler = [this](const MenuItemID& id, const QString& objName) {
            MenuActionHandle(id, objName);
        };

        CreateMenu(this, GetMenuItems(MenuType::MENU_VIEW), actionHandler);
    }

    void HMenuView::MenuActionHandle(const MenuItemID& itemId, const QString& objName)
    {
        LOG_DEBUG("ITEM_ID: ", std::to_string(static_cast<int>(itemId)), ", OBJ: ", objName.toStdString());
    }
}