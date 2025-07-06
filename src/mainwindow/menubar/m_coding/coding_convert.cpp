//
// Created by zhaoj on 25-7-6.
//

#include "coding_convert.h"
#include "common.h"

namespace HemyMenu
{
    HemyCodingSubMenuCvt::HemyCodingSubMenuCvt(QWidget *parent): MenuBase(parent) {
        CreateCodingSubMenuConvert();
        this->setTitle(getMenuItemAttr(MenuItem::MENU_CODING, MenuItemType::M_CODING_CONVERT).label);
        this->setObjectName(getMenuItemAttr(MenuItem::MENU_CODING, MenuItemType::M_CODING_CONVERT).obj_name);
    }

    void HemyCodingSubMenuCvt::CreateCodingSubMenuConvert()
    {
        actionCodeCvtAnsi = createAction(getMenuItemAttr(MenuItem::MENU_CODING, MenuItemType::M_CODING_CVT_ANSI));
        addSeparator();
        actionCodeCvtUtf8 = createAction(getMenuItemAttr(MenuItem::MENU_CODING, MenuItemType::M_CODING_CVT_UTF8));
        actionCodeCvtUtf16LE = createAction(getMenuItemAttr(MenuItem::MENU_CODING, MenuItemType::M_CODING_CVT_UTF16LE));
        actionCodeCvtUtf16BE = createAction(getMenuItemAttr(MenuItem::MENU_CODING, MenuItemType::M_CODING_CVT_UTF16BE));
        addSeparator();
        actionCodeCvtBig5 = createAction(getMenuItemAttr(MenuItem::MENU_CODING, MenuItemType::M_CODING_CVT_GBK));
        actionCodeCvtBig5Hkscs = createAction(getMenuItemAttr(MenuItem::MENU_CODING, MenuItemType::M_CODING_CVT_GB2312));
        actionCodeCvtGbk = createAction(getMenuItemAttr(MenuItem::MENU_CODING, MenuItemType::M_CODING_CVT_GB18030));
        addSeparator();
        actionCodeCvtGbk2312 = createAction(getMenuItemAttr(MenuItem::MENU_CODING, MenuItemType::M_CODING_CVT_BG5));
        actionCodeCvtGbk18030 = createAction(getMenuItemAttr(MenuItem::MENU_CODING, MenuItemType::M_CODING_CVT_BG5_HKSCS));
        addSeparator();
        actionCodeCvtHex = createAction(getMenuItemAttr(MenuItem::MENU_CODING, MenuItemType::M_CODING_CVT_HEX));
    }
}