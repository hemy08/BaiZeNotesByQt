//
// Created by Administrator on 25-7-5.
//

#include "hemy_menu.h"

namespace HemyUI
{
    HMenuOnlineTool::HMenuOnlineTool(QWidget *parent): MenuBase(parent) {
        InitialMenuItems();
    }
    void HMenuOnlineTool::InitialMenuItems()
    {
        auto actionHandler = [this](const MenuItemID& id, const QString& objName, const QString& url) {
            MenuActionHandle(id, objName, url);
        };
        QList<MenuItem> menuItems;
        ParserMenuItems(":/main_menu/online.xml", menuItems);
        // 在这里可以使用 menuItems 构建菜单系统
        CreateMenu(this, menuItems, actionHandler);
    }

    void HMenuOnlineTool::MenuActionHandle(const MenuItemID& itemId, const QString& objName, const QString& url)
    {
        LOG_DEBUG("ITEM_ID: ", std::to_string(static_cast<int>(itemId)), ", OBJ: ", objName.toStdString(), ", url: ", url.toStdString());
        openWebPage(url);
    }
}