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
        auto actionHandler = [this](const MenuItemID& id, const QString& objName) {
            onViewMenuActionHandler(id, objName);
        };

        createMenu(this, GetMenuItems(MenuType::MENU_VIEW), actionHandler);
    }

    void HMenuView::onViewMenuActionHandler(const MenuItemID& itemId, const QString& objName)
    {
        HDEBUG("ITEM_ID: " + std::to_string(static_cast<int>(itemId))+ ", OBJ: " + objName.toStdString());
    }
}