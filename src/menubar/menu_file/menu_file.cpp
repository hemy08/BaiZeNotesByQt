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
        const QList<MenuItem> importItems = {
            createMenuItem(MenuType::MENU_FILE, MenuItemID::M_FILE_IMPORT_WORD),
            createMenuItem(MenuType::MENU_FILE, MenuItemID::M_FILE_IMPORT_WORD),
            createMenuItem(MenuType::MENU_FILE, MenuItemID::M_FILE_IMPORT_HTML),
            createMenuItem(MenuType::MENU_FILE, MenuItemID::M_FILE_IMPORT_JSON),
            createMenuItem(MenuType::MENU_FILE, MenuItemID::M_FILE_IMPORT_YAML),
            createMenuItem(MenuType::MENU_FILE, MenuItemID::M_FILE_IMPORT_XML),
            createMenuItem(MenuType::MENU_FILE, MenuItemID::M_FILE_IMPORT_TXT),
        };

        const QList<MenuItem> exportItems = {
            createMenuItem(MenuType::MENU_FILE, MenuItemID::M_FILE_EXPORT_WORD),
            createMenuItem(MenuType::MENU_FILE, MenuItemID::M_FILE_EXPORT_JSON),
            createMenuItem(MenuType::MENU_FILE, MenuItemID::M_FILE_EXPORT_XML),
            createMenuItem(MenuType::MENU_FILE, MenuItemID::M_FILE_EXPORT_YAML),
            createMenuItem(MenuType::MENU_FILE, MenuItemID::M_FILE_EXPORT_HTML),
            createMenuItem(MenuType::MENU_FILE, MenuItemID::M_FILE_EXPORT_PDF),
        };
        const QList<MenuItem> menuItems = {
            createMenuItem(MenuType::MENU_FILE, MenuItemID::M_FILE_NEW_File),
            createMenuItem(MenuType::MENU_FILE, MenuItemID::M_FILE_NEW_DIR),
            createMenuItem(MenuType::MENU_FILE, MenuItemID::M_FILE_OPEN_File),
            createMenuItem(MenuType::MENU_FILE, MenuItemID::M_FILE_OPEN_DIR),
            MenuItem::createSeparator(),
            createMenuItems(MenuType::MENU_FILE, MenuItemID::M_FILE_IMPORT, importItems),
            createMenuItems(MenuType::MENU_FILE, MenuItemID::M_FILE_EXPORT, exportItems),
            MenuItem::createSeparator(),
            createMenuItem(MenuType::MENU_FILE, MenuItemID::M_FILE_SAVE),
            createMenuItem(MenuType::MENU_FILE, MenuItemID::M_FILE_SAVE_AS),
            createMenuItem(MenuType::MENU_FILE, MenuItemID::M_FILE_RELOAD),
            MenuItem::createSeparator(),
            createMenuItem(MenuType::MENU_FILE, MenuItemID::M_FILE_EXIT),
        };

        auto actionHandler = [this](const MenuItemID& id, const QString& objName) {
            onFileMenuActionHandler(id, objName);
        };

        createMenu(this, menuItems, actionHandler);
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