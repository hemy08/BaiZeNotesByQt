//
// Created by Administrator on 25-7-5.
//

#include "file_import_from.h"
#include "common.h"

namespace HemyMenu {
    HemyFileSubMenuImport::HemyFileSubMenuImport(QWidget *parent): MenuBase(parent) {
        CreateFileSubMenuImport();
        this->setTitle(getMenuItemAttr(MenuItem::MENU_FILE, MenuItemType::M_FILE_IMPORT).label);
        this->setObjectName(getMenuItemAttr(MenuItem::MENU_FILE, MenuItemType::M_FILE_IMPORT).obj_name);
    }

    void HemyFileSubMenuImport::CreateFileSubMenuImport()
    {
        actionFromWord = createAction(getMenuItemAttr(MenuItem::MENU_FILE, MenuItemType::M_FILE_IMPORT_WORD));
        actionFromHtml = createAction(getMenuItemAttr(MenuItem::MENU_FILE, MenuItemType::M_FILE_IMPORT_HTML));
        actionFromJson = createAction(getMenuItemAttr(MenuItem::MENU_FILE, MenuItemType::M_FILE_IMPORT_JSON));
        actionFromYaml = createAction(getMenuItemAttr(MenuItem::MENU_FILE, MenuItemType::M_FILE_IMPORT_YAML));
        actionFromXml = createAction(getMenuItemAttr(MenuItem::MENU_FILE, MenuItemType::M_FILE_IMPORT_XML));
        actionFromTxt = createAction(getMenuItemAttr(MenuItem::MENU_FILE, MenuItemType::M_FILE_IMPORT_TXT));
    }
}