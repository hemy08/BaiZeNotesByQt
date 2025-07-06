//
// Created by zhaoj on 25-7-6.
//

#include "view_fold.h"

namespace HemyMenu
{
    HemyViewSubMenuFold::HemyViewSubMenuFold(QWidget *parent): MenuBase(parent) {
        CreateViewSubMenuFold();
        this->setTitle(getMenuItemAttr(MenuItem::MENU_VIEW, MenuItemType::M_VIEW_FOLD).label);
        this->setObjectName(getMenuItemAttr(MenuItem::MENU_VIEW, MenuItemType::M_VIEW_FOLD).obj_name);
    }

    void HemyViewSubMenuFold::CreateViewSubMenuFold()
    {
        actionFold1 = createAction(getMenuItemAttr(MenuItem::MENU_VIEW, MenuItemType::M_VIEW_FOLD_1));
        actionFold2 = createAction(getMenuItemAttr(MenuItem::MENU_VIEW, MenuItemType::M_VIEW_FOLD_2));
        actionFold3 = createAction(getMenuItemAttr(MenuItem::MENU_VIEW, MenuItemType::M_VIEW_FOLD_3));
        actionFold4 = createAction(getMenuItemAttr(MenuItem::MENU_VIEW, MenuItemType::M_VIEW_FOLD_4));
        actionFold5 = createAction(getMenuItemAttr(MenuItem::MENU_VIEW, MenuItemType::M_VIEW_FOLD_5));
        actionFold6 = createAction(getMenuItemAttr(MenuItem::MENU_VIEW, MenuItemType::M_VIEW_FOLD_6));
    }
}