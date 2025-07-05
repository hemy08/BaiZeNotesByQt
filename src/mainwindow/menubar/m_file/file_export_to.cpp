//
// Created by Administrator on 25-7-5.
//

#include "file_export_to.h"
#include "const_def.h"

namespace HemyMenu {
    HemyFileSubMenuExport::HemyFileSubMenuExport(QWidget *parent): QMenu("导出", parent) {
        CreateFileSubMenuExport();
    }
    void HemyFileSubMenuExport::CreateFileSubMenuExport()
    {
        ActionToWord();
        ActionToHtml();
        ActionToTxt();
        ActionToXml();
        ActionToYaml();
        ActionToJson();
        ActionToPdf();
    }

    void HemyFileSubMenuExport::ActionToWord() {
        actionToWord = addAction(ConstMenuFile::EXPORT_WORD.label);
        actionToWord->setObjectName(ConstMenuFile::EXPORT_WORD.obj_name);
        actionToWord->setShortcut(ConstMenuFile::EXPORT_WORD.shortcut);
    }

    void HemyFileSubMenuExport::ActionToHtml() {
        actionToHtml = addAction(ConstMenuFile::EXPORT_HTML.label);
        actionToHtml->setObjectName(ConstMenuFile::EXPORT_HTML.obj_name);
        actionToHtml->setShortcut(ConstMenuFile::EXPORT_HTML.shortcut);
    }

    void HemyFileSubMenuExport::ActionToTxt() {
        actionToTxt = addAction(ConstMenuFile::EXPORT_TXT.label);
        actionToTxt->setObjectName(ConstMenuFile::EXPORT_TXT.obj_name);
        actionToTxt->setShortcut(ConstMenuFile::EXPORT_TXT.shortcut);
    }

    void HemyFileSubMenuExport::ActionToXml() {
        actionToXml = addAction(ConstMenuFile::EXPORT_XML.label);
        actionToXml->setObjectName(ConstMenuFile::EXPORT_XML.obj_name);
        actionToXml->setShortcut(ConstMenuFile::EXPORT_XML.shortcut);
    }

    void HemyFileSubMenuExport::ActionToYaml() {
        actionToYaml = addAction(ConstMenuFile::EXPORT_YAML.label);
        actionToYaml->setObjectName(ConstMenuFile::EXPORT_YAML.obj_name);
        actionToYaml->setShortcut(ConstMenuFile::EXPORT_YAML.shortcut);
    }

    void HemyFileSubMenuExport::ActionToJson() {
        actionToJson = addAction(ConstMenuFile::EXPORT_JSON.label);
        actionToJson->setObjectName(ConstMenuFile::EXPORT_JSON.obj_name);
        actionToJson->setShortcut(ConstMenuFile::EXPORT_JSON.shortcut);
    }

    void HemyFileSubMenuExport::ActionToPdf() {
        actionToPdf = addAction(ConstMenuFile::EXPORT_PDF.label);
        actionToPdf->setObjectName(ConstMenuFile::EXPORT_PDF.obj_name);
        actionToPdf->setShortcut(ConstMenuFile::EXPORT_PDF.shortcut);
    }
}