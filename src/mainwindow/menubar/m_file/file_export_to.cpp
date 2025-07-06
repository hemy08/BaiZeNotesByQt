//
// Created by Administrator on 25-7-5.
//

#include "file_export_to.h"
#include "const_def.h"

namespace HemyMenu {
    HemyFileSubMenuExport::HemyFileSubMenuExport(QWidget *parent): MenuBase(parent) {
        CreateFileSubMenuExport();
        this->setTitle(getMenuItemAttr(MenuItem::MENU_FILE, MenuItemType::M_FILE_EXPORT).label);
        this->setObjectName(getMenuItemAttr(MenuItem::MENU_FILE, MenuItemType::M_FILE_EXPORT).obj_name);
    }
    void HemyFileSubMenuExport::CreateFileSubMenuExport()
    {
        actionToWord = createAction(getMenuItemAttr(MenuItem::MENU_FILE, MenuItemType::M_FILE_EXPORT_WORD));
        actionToHtml = createAction(getMenuItemAttr(MenuItem::MENU_FILE, MenuItemType::M_FILE_EXPORT_HTML));
        actionToXml = createAction(getMenuItemAttr(MenuItem::MENU_FILE, MenuItemType::M_FILE_EXPORT_XML));
        actionToYaml = createAction(getMenuItemAttr(MenuItem::MENU_FILE, MenuItemType::M_FILE_EXPORT_YAML));
        actionToJson = createAction(getMenuItemAttr(MenuItem::MENU_FILE, MenuItemType::M_FILE_EXPORT_JSON));
        actionToPdf = createAction(getMenuItemAttr(MenuItem::MENU_FILE, MenuItemType::M_FILE_EXPORT_PDF));
    }
}