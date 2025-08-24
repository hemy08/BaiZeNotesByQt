//
// Created by zhaoj on 25-7-13.
//

#ifndef MENU_FILE_H
#define MENU_FILE_H
#include "menu_base.h"
#include "common.h"

namespace HemyUI
{
    // 1. 文件菜单映射
    class HMenuFile final : public MenuBase {
    public:
        explicit HMenuFile(QWidget *parent = nullptr);
        ~HMenuFile() override = default;

    private:
        void InitialMenuItems();
        void MenuActionHandle(const MenuItemID& itemId, const QString& objName);
        void FileMenuImportHandle(const MenuItemID& itemId, const QString& objName);
        void FileMenuExportHandle(const MenuItemID& itemId, const QString& objName);
        void NewFile();
        void NewFolder();
        void OpenFile();
        void OpenFolder();
        QString FileImportFrom(const QString& extension);
        void FileImportFromWord();
        void FileImportFromHtml();
        void FileImportFromJson();
        void FileImportFromYaml();
        void FileImportFromXml();
        void FileImportFromTxt();
        void FileExportTo(const QString& extension);
        void FileExportToWord();
        void FileExportToHtml();
        void FileExportToJson();
        void FileExportToYaml();
        void FileExportToXml();
        void FileExportToPdf();
        void SaveFile();
        void SaveAsFile();
        void ReloadFile();
        void Exit();
    };


}

#endif //MENU_FILE_H