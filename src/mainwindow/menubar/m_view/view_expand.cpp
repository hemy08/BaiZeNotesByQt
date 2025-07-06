//
// Created by zhaoj on 25-7-6.
//

#include "view_expand.h"
#include "common.h"

namespace HemyMenu
{
    HemyViewSubMenuExpand::HemyViewSubMenuExpand(QWidget *parent): MenuBase(parent) {
        CreateViewSubMenuExpand();
        this->setTitle(getMenuItemAttr(MenuItem::MENU_VIEW, MenuItemType::M_VIEW_EXPAND).label);
        this->setObjectName(getMenuItemAttr(MenuItem::MENU_VIEW, MenuItemType::M_VIEW_EXPAND).obj_name);
    }

    void HemyViewSubMenuExpand::CreateViewSubMenuExpand()
    {
        actionExpand1 = createAction(getMenuItemAttr(MenuItem::MENU_VIEW, MenuItemType::M_VIEW_EXPAND_1));
        actionExpand2 = createAction(getMenuItemAttr(MenuItem::MENU_VIEW, MenuItemType::M_VIEW_EXPAND_2));
        actionExpand3 = createAction(getMenuItemAttr(MenuItem::MENU_VIEW, MenuItemType::M_VIEW_EXPAND_3));
        actionExpand4 = createAction(getMenuItemAttr(MenuItem::MENU_VIEW, MenuItemType::M_VIEW_EXPAND_4));
        actionExpand5 = createAction(getMenuItemAttr(MenuItem::MENU_VIEW, MenuItemType::M_VIEW_EXPAND_5));
        actionExpand6 = createAction(getMenuItemAttr(MenuItem::MENU_VIEW, MenuItemType::M_VIEW_EXPAND_6));
    }
}