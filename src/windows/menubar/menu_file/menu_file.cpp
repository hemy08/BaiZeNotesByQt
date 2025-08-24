//
// Created by Administrator on 25-7-5.
//

#include "menu_file.h"
#include <QFile>
#include <QDir>
#include <QFileDialog>
#include <QInputDialog>
#include <QMessageBox>
#include "common_api.h"
#include "gui_comm_def.h"

namespace HemyUI
{
    HMenuFile::HMenuFile(QWidget *parent): MenuBase(parent) {
        InitialMenuItems();
    }

    void HMenuFile::InitialMenuItems()
    {
        auto actionHandler = [this](const MenuItemID& id, const QString& objName) {
            MenuActionHandle(id, objName);
        };

        CreateMenu(this, GetMenuItems(MenuType::MENU_FILE), actionHandler);
    }

    void HMenuFile::MenuActionHandle(const MenuItemID& itemId, const QString& objName)
    {
        switch (itemId){
            case MenuItemID::M_FILE_NEW_FILE:
                return NewFile();
            case MenuItemID::M_FILE_NEW_FOLDER:
                return NewFolder();
            case MenuItemID::M_FILE_OPEN_FILE:
                return OpenFile();
            case MenuItemID::M_FILE_OPEN_FOLDER:
                return OpenFolder();
            case MenuItemID::M_FILE_SAVE:
                return SaveFile();
            case MenuItemID::M_FILE_SAVE_AS:
                return SaveAsFile();
            case MenuItemID::M_FILE_RELOAD:
                return ReloadFile();
            case MenuItemID::M_FILE_EXIT:
                return Exit();
            case MenuItemID::M_FILE_IMPORT:
            case MenuItemID::M_FILE_IMPORT_WORD:
            case MenuItemID::M_FILE_IMPORT_HTML:
            case MenuItemID::M_FILE_IMPORT_JSON:
            case MenuItemID::M_FILE_IMPORT_YAML:
            case MenuItemID::M_FILE_IMPORT_XML:
            case MenuItemID::M_FILE_IMPORT_TXT:
                return FileMenuImportHandle(itemId, objName);
            case MenuItemID::M_FILE_EXPORT:
            case MenuItemID::M_FILE_EXPORT_WORD:
            case MenuItemID::M_FILE_EXPORT_HTML:
            case MenuItemID::M_FILE_EXPORT_JSON:
            case MenuItemID::M_FILE_EXPORT_YAML:
            case MenuItemID::M_FILE_EXPORT_XML:
            case MenuItemID::M_FILE_EXPORT_PDF:
                return FileMenuExportHandle(itemId, objName);
            default:
                LOG_DEBUG("ITEM_ID: ", std::to_string(static_cast<int>(itemId)), ", OBJ: ", objName.toStdString(), " not fond");
        }
    }

    void HMenuFile::FileMenuImportHandle(const MenuItemID& itemId, const QString& objName)
    {
        switch (itemId)
        {
            case MenuItemID::M_FILE_IMPORT_WORD:
                return FileImportFromWord();
            case MenuItemID::M_FILE_IMPORT_HTML:
                return FileImportFromHtml();
            case MenuItemID::M_FILE_IMPORT_JSON:
                return FileImportFromJson();
            case MenuItemID::M_FILE_IMPORT_YAML:
                return FileImportFromYaml();
            case MenuItemID::M_FILE_IMPORT_XML:
                return FileImportFromXml();
            case MenuItemID::M_FILE_IMPORT_TXT:
                return FileImportFromTxt();
            default:
                LOG_DEBUG("ITEM_ID: ", std::to_string(static_cast<int>(itemId)), ", OBJ: ", objName.toStdString(), " not fond");
        }
    }

    void HMenuFile::FileMenuExportHandle(const MenuItemID& itemId, const QString& objName)
    {
        switch (itemId)
        {
        case MenuItemID::M_FILE_EXPORT_WORD:
            return FileExportToWord();
        case MenuItemID::M_FILE_EXPORT_HTML:
            return FileExportToHtml();
        case MenuItemID::M_FILE_EXPORT_JSON:
            return FileExportToJson();
        case MenuItemID::M_FILE_EXPORT_YAML:
            return FileExportToYaml();
        case MenuItemID::M_FILE_EXPORT_XML:
            return FileExportToXml();
        case MenuItemID::M_FILE_EXPORT_PDF:
            return FileExportToPdf();
        default:
            LOG_DEBUG("ITEM_ID: ", std::to_string(static_cast<int>(itemId)), ", OBJ: ", objName.toStdString(), " not fond");
        }
    }

    void HMenuFile::NewFile()
    {
        const QString fileName = QFileDialog::getSaveFileName(
                this,
                HEMY_GUI::DIALOG::FILE::TITLE,
                QDir::homePath(),
                tr("*.md")
            );

        if (!fileName.isEmpty()) {
            QFile file(fileName);
            if (file.exists()) {
                QMessageBox::warning(this, HEMY_GUI::MSG_TYPE_WARNING, HEMY_GUI::DIALOG::FILE::ALREADY_EXIST);
                return;
            }

            if (file.open(QIODevice::WriteOnly)) {
                file.close();
                QMessageBox::information(this, HEMY_GUI::MSG_TYPE_SUCCESS, HEMY_GUI::DIALOG::FILE::CREATE_SUCCESS);
            } else {
                QMessageBox::critical(this, HEMY_GUI::MSG_TYPE_ERROR, HEMY_GUI::DIALOG::FILE::CREATE_FAILED);
            }
        }
    }

    void HMenuFile::NewFolder()
    {
        const QString dirPath = QFileDialog::getExistingDirectory(
            this,
            HEMY_GUI::DIALOG::FOLDER::TITLE,
            QDir::homePath()
        );

        if (!dirPath.isEmpty()) {
            bool ok;
            const QString folderName = QInputDialog::getText(
                this,
                HEMY_GUI::DIALOG::FOLDER::TITLE,
                HEMY_GUI::DIALOG::FOLDER::NAME,
                QLineEdit::Normal,
                "",
                &ok
            );

            if (ok && !folderName.isEmpty()) {
                QDir dir(dirPath);
                if (dir.mkdir(folderName)) {
                    QMessageBox::information(this, HEMY_GUI::MSG_TYPE_SUCCESS, HEMY_GUI::DIALOG::FOLDER::CREATE_SUCCESS);
                } else {
                    QMessageBox::critical(this, HEMY_GUI::MSG_TYPE_ERROR, HEMY_GUI::DIALOG::FOLDER::CREATE_FAILED);
                }
            }
        }
    }

    // 打开文件
    void HMenuFile::OpenFile()
    {
        const QString fileNames = QFileDialog::getOpenFileName(
            this,
            HEMY_GUI::DIALOG::FILE::OPEN,
            QDir::homePath(),
            HEMY_GUI::DIALOG::FILE::ALL_FILE
        );

        if (!fileNames.isEmpty()) {
            // 实际应用中这里处理文件打开操作
            const QString message = HEMY_GUI::DIALOG::FILE::SELECT + fileNames;
            QMessageBox::information(this, HEMY_GUI::DIALOG::FILE::SELECTED, message);
        }
    }

    // 打开文件夹
    void HMenuFile::OpenFolder()
    {
        const QString dirPath = QFileDialog::getExistingDirectory(
            this,
            tr("Open Directory"),
            QDir::homePath()
        );

        if (!dirPath.isEmpty()) {
            // 实际应用中这里处理文件夹打开操作
            QMessageBox::information(this, HEMY_GUI::DIALOG::FOLDER::SELECTED,
                                    HEMY_GUI::DIALOG::FOLDER::SELECT.arg(dirPath));
        }
    }


    void HMenuFile::SaveFile()
    {

    }

    void HMenuFile::SaveAsFile()
    {

    }

    void HMenuFile::ReloadFile()
    {

    }

    void HMenuFile::Exit()
    {
    }

    QString HMenuFile::FileImportFrom(const QString& extension)
    {
        const QString fileName = QFileDialog::getOpenFileName(
            this,
            HEMY_GUI::DIALOG::FILE::OPEN,
            QDir::homePath(),
            extension
        );

        if (!fileName.isEmpty()) {
            // 实际应用中这里处理文件打开操作
            const QString message = HEMY_GUI::DIALOG::FILE::SELECT + fileName;
            QMessageBox::information(this, HEMY_GUI::DIALOG::FILE::SELECTED, message);
            return fileName;
        } else {
            return QString();
        }
    }

    void HMenuFile::FileImportFromWord()
    {
        const QString filter = "Word 文档 (*.doc *.docx);";
        const QString fileName = FileImportFrom(filter);
        // 检查用户是否取消了选择
        if (fileName.isEmpty()) {
            LOG_DEBUG("用户取消了文件选择");
            return;
        }
        QString content = "";
        HEMY_API::File::ReadFile(fileName, content,[this](const QString &title, const QString &text) {
            QMessageBox::critical(this, title, text);
        });
    }

    void HMenuFile::FileImportFromHtml()
    {

    }

    void HMenuFile::FileImportFromJson()
    {
    }

    void HMenuFile::FileImportFromYaml()
    {
    }

    void HMenuFile::FileImportFromXml()
    {
    }

    void HMenuFile::FileImportFromTxt()
    {
    }

    void HMenuFile::FileExportTo(const QString& extension)
    {
    }

    void HMenuFile::FileExportToWord()
    {
    }

    void HMenuFile::FileExportToHtml()
    {
    }

    void HMenuFile::FileExportToJson()
    {
    }

    void HMenuFile::FileExportToYaml()
    {
    }

    void HMenuFile::FileExportToXml()
    {
    }

    void HMenuFile::FileExportToPdf()
    {
    }
}
