//
// Created by zhaoj on 25-7-6.
//

#include "coding_open.h"
#include "common.h"

namespace HemyMenu
{
    HemyCodingSubMenuOpen::HemyCodingSubMenuOpen(QWidget *parent): MenuBase(parent) {
        CreateCodingSubMenuOpen();
        this->setTitle(getMenuItemAttr(MenuItem::MENU_CODING, MenuItemType::M_CODING_OPEN).label);
        this->setObjectName(getMenuItemAttr(MenuItem::MENU_CODING, MenuItemType::M_CODING_OPEN).obj_name);
    }

    void HemyCodingSubMenuOpen::CreateCodingSubMenuOpen()
    {
        actionCodeOpenAnsi = createAction(getMenuItemAttr(MenuItem::MENU_CODING, MenuItemType::M_CODING_OPEN_ANSI));
        addSeparator();
        actionCodeOpenUtf8 = createAction(getMenuItemAttr(MenuItem::MENU_CODING, MenuItemType::M_CODING_OPEN_UTF8));
        actionCodeOpenUtf16LE = createAction(getMenuItemAttr(MenuItem::MENU_CODING, MenuItemType::M_CODING_OPEN_UTF16LE));
        actionCodeOpenUtf16BE = createAction(getMenuItemAttr(MenuItem::MENU_CODING, MenuItemType::M_CODING_OPEN_UTF16BE));
        addSeparator();
        actionCodeOpenBig5 = createAction(getMenuItemAttr(MenuItem::MENU_CODING, MenuItemType::M_CODING_OPEN_GBK));
        actionCodeOpenBig5Hkscs = createAction(getMenuItemAttr(MenuItem::MENU_CODING, MenuItemType::M_CODING_OPEN_GB2312));
        actionCodeOpenGbk = createAction(getMenuItemAttr(MenuItem::MENU_CODING, MenuItemType::M_CODING_OPEN_GB18030));
        addSeparator();
        actionCodeOpenGbk2312 = createAction(getMenuItemAttr(MenuItem::MENU_CODING, MenuItemType::M_CODING_OPEN_BG5));
        actionCodeOpenGbk18030 = createAction(getMenuItemAttr(MenuItem::MENU_CODING, MenuItemType::M_CODING_OPEN_BG5_HKSCS));
        addSeparator();
        actionCodeOpenHex = createAction(getMenuItemAttr(MenuItem::MENU_CODING, MenuItemType::M_CODING_OPEN_HEX));
    }
}