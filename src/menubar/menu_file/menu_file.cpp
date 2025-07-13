//
// Created by Administrator on 25-7-5.
//

#include "menu_file.h"

namespace HemyMenu
{
    HMenuFile::HMenuFile(QWidget *parent): MenuBase(parent) {
        InitialFileMenuItems();
    }

    void HMenuFile::InitialFileMenuItems()
    {
        auto actionHandler = [this](const MenuItemID& id, const QString& objName) {
            onFileMenuActionHandler(id, objName);
        };

        createMenu(this, GetMenuItems(MenuType::MENU_FILE), actionHandler);
    }

    void HMenuFile::onFileMenuActionHandler(const MenuItemID& itemId, const QString& objName)
    {
        HDEBUG("ITEM_ID: " + std::to_string(static_cast<int>(itemId))+ ", OBJ: " + objName.toStdString());
    }

    void HMenuFile::onFileMenuImportAction(const MenuItemID& itemId, const QString& objName)
    {
        HDEBUG("ITEM_ID: " + std::to_string(static_cast<int>(itemId))+ ", OBJ: " + objName.toStdString());
    }

    void HMenuFile::onFileMenuExportAction(const MenuItemID& itemId, const QString& objName)
    {
        HDEBUG("ITEM_ID: " + std::to_string(static_cast<int>(itemId))+ ", OBJ: " + objName.toStdString());
    }
}