//
// Created by Administrator on 25-7-5.
//

#include "file_import_from.h"
#include "common.h"

namespace HemyMenu {
    HemyFileSubMenuImport::HemyFileSubMenuImport(QWidget *parent): MenuBase(parent) {
        CreateFileSubMenuImport();
        this->setTitle(getMenuAttr(MenuItemType::M_FILE_IMPORT).label);
        this->setObjectName(getMenuAttr(MenuItemType::M_FILE_IMPORT).obj_name);
    }

    void HemyFileSubMenuImport::CreateFileSubMenuImport()
    {
        actionFromWord = createAction(getMenuAttr(MenuItemType::M_FILE_IMPORT_WORD));
        actionFromHtml = createAction(getMenuAttr(MenuItemType::M_FILE_IMPORT_HTML));
        actionFromJson = createAction(getMenuAttr(MenuItemType::M_FILE_IMPORT_JSON));
        actionFromYaml = createAction(getMenuAttr(MenuItemType::M_FILE_IMPORT_YAML));
        actionFromXml = createAction(getMenuAttr(MenuItemType::M_FILE_IMPORT_XML));
        actionFromTxt = createAction(getMenuAttr(MenuItemType::M_FILE_IMPORT_TXT));
    }
}