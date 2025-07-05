//
// Created by Administrator on 25-7-5.
//

#include "file_export_to.h"
#include "const_def.h"

namespace HemyMenu {
    HemyFileSubMenuExport::HemyFileSubMenuExport(QWidget *parent): MenuBase(parent) {
        CreateFileSubMenuExport();
        this->setTitle(getMenuAttr(MenuItemType::M_FILE_EXPORT).label);
        this->setObjectName(getMenuAttr(MenuItemType::M_FILE_EXPORT).obj_name);
    }
    void HemyFileSubMenuExport::CreateFileSubMenuExport()
    {
        actionToWord = createAction(getMenuAttr(MenuItemType::M_FILE_EXPORT_WORD));
        actionToHtml = createAction(getMenuAttr(MenuItemType::M_FILE_EXPORT_HTML));
        actionToXml = createAction(getMenuAttr(MenuItemType::M_FILE_EXPORT_XML));
        actionToYaml = createAction(getMenuAttr(MenuItemType::M_FILE_EXPORT_YAML));
        actionToJson = createAction(getMenuAttr(MenuItemType::M_FILE_EXPORT_JSON));
        actionToPdf = createAction(getMenuAttr(MenuItemType::M_FILE_EXPORT_PDF));
    }
}