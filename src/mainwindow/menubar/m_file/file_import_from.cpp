//
// Created by Administrator on 25-7-5.
//

#include "file_import_from.h"
#include "const_def.h"

namespace HemyMenu {
    HemyFileSubMenuImport::HemyFileSubMenuImport(QWidget *parent): QMenu("导入", parent) {
        CreateFileSubMenuImport();
    }

    void HemyFileSubMenuImport::CreateFileSubMenuImport()
    {
        ActionFormWord();
        ActionFormHtml();
        ActionFormJson();
        ActionFormYaml();
        ActionFormXml();
        ActionFormTxt();
    }

    void HemyFileSubMenuImport::ActionFormWord() {
        actionFromWord = addAction(ConstMenuFile::IMPORT_WORD.label);
        actionFromWord->setObjectName(ConstMenuFile::IMPORT_WORD.obj_name);
        actionFromWord->setShortcut(ConstMenuFile::IMPORT_WORD.shortcut);
    }

    void HemyFileSubMenuImport::ActionFormHtml() {
        actionFromHtml = addAction(ConstMenuFile::IMPORT_HTML.label);
        actionFromHtml->setObjectName(ConstMenuFile::IMPORT_HTML.obj_name);
        actionFromHtml->setShortcut(ConstMenuFile::IMPORT_HTML.shortcut);
    }

    void HemyFileSubMenuImport::ActionFormJson() {
        actionFromJson = addAction(ConstMenuFile::IMPORT_JSON.label);
        actionFromJson->setObjectName(ConstMenuFile::IMPORT_JSON.obj_name);
        actionFromJson->setShortcut(ConstMenuFile::IMPORT_JSON.shortcut);
    }

    void HemyFileSubMenuImport::ActionFormYaml() {
        actionFromYaml = addAction(ConstMenuFile::IMPORT_YAML.label);
        actionFromYaml->setObjectName(ConstMenuFile::IMPORT_YAML.obj_name);
        actionFromYaml->setShortcut(ConstMenuFile::IMPORT_YAML.shortcut);
    }

    void HemyFileSubMenuImport::ActionFormXml() {
        actionFromXml = addAction(ConstMenuFile::IMPORT_XML.label);
        actionFromXml->setObjectName(ConstMenuFile::IMPORT_XML.obj_name);
        actionFromXml->setShortcut(ConstMenuFile::IMPORT_XML.shortcut);
    }

    void HemyFileSubMenuImport::ActionFormTxt() {
        actionFromTxt = addAction(ConstMenuFile::IMPORT_TXT.label);
        actionFromTxt->setObjectName(ConstMenuFile::IMPORT_TXT.obj_name);
        actionFromTxt->setShortcut(ConstMenuFile::IMPORT_TXT.shortcut);
    }
}