//
// Created by Administrator on 25-7-5.
//

#include "h_menu_coding.h"

namespace HemyMenu
{
    HMenuCoding::HMenuCoding(QWidget *parent): MenuBase(parent) {
        CreateMenuCoding();
    }
    void HMenuCoding::CreateMenuCoding()
    {
        // 导入导出
        m_open_ = new HemyCodingSubMenuOpen(this);
        addMenu(m_open_);
        m_convert_ = new HemyCodingSubMenuCvt(this);
        addMenu(m_convert_);
        const MenuItemAttr notifyItem = getMenuItemAttr(MenuItem::MENU_CODING, MenuItemType::M_CODING_NOTIFY);
        actionCodingNotify = addAction(notifyItem.label);
        actionCodingNotify->setObjectName(notifyItem.obj_name);
        actionCodingNotify->setDisabled(true);
    }
}