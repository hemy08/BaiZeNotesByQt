//
// Created by Administrator on 25-7-5.
//

#include "menu_coding.h"

namespace HemyMenu
{
    HMenuCoding::HMenuCoding(QWidget *parent): MenuBase(parent) {
        InitialCodingMenuItems();
    }
    void HMenuCoding::InitialCodingMenuItems()
    {
        QList<MenuItem> openWithItem = {
            createMenuItem(MenuType::MENU_CODING, MenuItemID::M_CODING_OPEN_ANSI),
            createMenuItem(MenuType::MENU_CODING, MenuItemID::M_CODING_OPEN_UTF8),
            createMenuItem(MenuType::MENU_CODING, MenuItemID::M_CODING_OPEN_UTF16BE),
            createMenuItem(MenuType::MENU_CODING, MenuItemID::M_CODING_OPEN_UTF16LE),
            createMenuItem(MenuType::MENU_CODING, MenuItemID::M_CODING_OPEN_BG5),
            createMenuItem(MenuType::MENU_CODING, MenuItemID::M_CODING_OPEN_BG5_HKSCS),
            createMenuItem(MenuType::MENU_CODING, MenuItemID::M_CODING_OPEN_GBK),
            createMenuItem(MenuType::MENU_CODING, MenuItemID::M_CODING_OPEN_GB2312),
            createMenuItem(MenuType::MENU_CODING, MenuItemID::M_CODING_OPEN_GB18030),
            createMenuItem(MenuType::MENU_CODING, MenuItemID::M_CODING_OPEN_HEX),
        };

        QList<MenuItem> convertToItem = {
            createMenuItem(MenuType::MENU_CODING, MenuItemID::M_CODING_CVT_ANSI),
            createMenuItem(MenuType::MENU_CODING, MenuItemID::M_CODING_CVT_UTF8),
            createMenuItem(MenuType::MENU_CODING, MenuItemID::M_CODING_CVT_UTF16BE),
            createMenuItem(MenuType::MENU_CODING, MenuItemID::M_CODING_CVT_UTF16LE),
            createMenuItem(MenuType::MENU_CODING, MenuItemID::M_CODING_CVT_BG5),
            createMenuItem(MenuType::MENU_CODING, MenuItemID::M_CODING_CVT_BG5_HKSCS),
            createMenuItem(MenuType::MENU_CODING, MenuItemID::M_CODING_CVT_GBK),
            createMenuItem(MenuType::MENU_CODING, MenuItemID::M_CODING_CVT_GB2312),
            createMenuItem(MenuType::MENU_CODING, MenuItemID::M_CODING_CVT_GB18030),
            createMenuItem(MenuType::MENU_CODING, MenuItemID::M_CODING_CVT_HEX),
        };
        
        QList<MenuItem> menuItems = {
            MenuItem{MenuItemID::M_CODING_OPEN, "使用......编码打开", "CodingSubMenuOpen", openWithItem},
            MenuItem{MenuItemID::M_CODING_CONVERT, "转为......编码", "CodingSubMenuConvert", convertToItem},
            createMenuItem(MenuType::MENU_CODING, MenuItemID::M_CODING_NOTIFY),
        };

        auto actionHandler = [this](const MenuItemID& id, const QString& objName) {
            onCodingMenuActionHandler(id, objName);
        };

        createMenu(this, menuItems, actionHandler);
    }

    void HMenuCoding::onCodingMenuActionHandler(const MenuItemID& itemId, const QString& objName)
    {
        HDEBUG("ITEM_ID: " + std::to_string(static_cast<int>(itemId))+ ", OBJ: " + objName.toStdString());
    }
}