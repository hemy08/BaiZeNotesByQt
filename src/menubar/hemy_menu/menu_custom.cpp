//
// Created by zhaoj on 25-7-8.
//

#include "hemy_menu.h"


namespace HemyMenu
{
    HMenuCustom::HMenuCustom(QWidget *parent): MenuBase(parent) {
        InitialCustomMenuItems();
    }
    void HMenuCustom::InitialCustomMenuItems()
    {
        auto actionHandler = [this](const MenuItemID& id, const QString& objName, const QString& url, const QString& qml) {
            onCustomMenuActionHandler(id, objName, url, qml);
        };
        QList<MenuItem> menuItems;
        ParserMenuItems(":/main_menu/custom_tools.xml", menuItems);
        // 在这里可以使用 menuItems 构建菜单系统
        createMenu(this, menuItems, actionHandler);
    }

    void HMenuCustom::onCustomMenuActionHandler(const MenuItemID& itemId, const QString& objName, const QString& url, const QString& qml)
    {
        HDEBUG("ITEM_ID: " + std::to_string(static_cast<int>(itemId))+ ", OBJ: " + objName.toStdString() +
            ", URL: " + url.toStdString()  + ", QML: " + qml.toStdString());
    }
}