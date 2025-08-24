//
// Created by zhaoj on 25-8-10.
//
#include <QFileDialog>
#include "dialog_file.h"

#include <combaseapi.h>
#include <QInputDialog>
#include <QMessageBox>
#include "gui_comm_def.h"
#include "error.h"
#include "common.h"

namespace HEMY_DIALOGS
{
    ErrCode HFile::NewFile(QString& fileName, QString title)
    {
        fileName = QFileDialog::getSaveFileName(
                this,
                title,
                QDir::homePath(),
                tr("*.md")
            );

        if (fileName.isEmpty()) {
            LOG_ERROR("create new file failed, file name is empty");
            QMessageBox::critical(this, HEMY_GUI::MSG_TYPE_ERROR, HEMY_GUI::ERR_STR::ERR_FILE_NAME_EMPTY);
            return ERR_NEW_FILE_FAILED;
        }

        QFile file(fileName);
        if (file.exists()) {
            QMessageBox::warning(this, HEMY_GUI::MSG_TYPE_WARNING, HEMY_GUI::ERR_STR::ERR_FILE_ALREADY_EXIST);
            LOG_ERROR("create new file failed, file name is already exist");
            return ERR_NEW_FILE_EXIST;
        }

        if (!file.open(QIODevice::WriteOnly)) {
            LOG_ERROR("create new file failed, failed to open file ", fileName);
            QMessageBox::critical(this, HEMY_GUI::MSG_TYPE_ERROR, HEMY_GUI::ERR_STR::ERR_FILE_CREATE_FAILED);
            return ERR_NEW_FILE_FAILED;
        }

        file.close();
        QMessageBox::information(this, HEMY_GUI::MSG_TYPE_SUCCESS, HEMY_GUI::ERR_STR::ERR_FILE_CREATE_SUCCESS);
        return ERR_OK;
    }

    ErrCode HFile::NewFolder(QString& folderName, QString title)
    {
        const QString dirPath = QFileDialog::getExistingDirectory(
            this,
            title,
            QDir::homePath()
        );

        if (dirPath.isEmpty())        {
            LOG_ERROR("create new folder failed, dirPath is empty");
            QMessageBox::critical(this, HEMY_GUI::MSG_TYPE_ERROR, HEMY_GUI::ERR_STR::ERR_FOLDER_CREATE_FAILED);
            return ERR_NEW_FOLDER_FAILED;
        }

        bool ok;
        folderName = QInputDialog::getText(
            this,
            title,
            HEMY_GUI::DIALOG::FOLDER::NAME,
            QLineEdit::Normal,
            "",
            &ok
        );

        if (!ok || folderName.isEmpty()) {
            LOG_ERROR("create new folder failed, not ok or folderName is empty");
            QMessageBox::critical(this, HEMY_GUI::MSG_TYPE_ERROR, HEMY_GUI::ERR_STR::ERR_FOLDER_NAME_EMPTY);
            return ERR_NEW_FOLDER_FAILED;
        }

        QDir dir(dirPath);
        if (!dir.mkdir(folderName)) {
            LOG_ERROR("create new folder failed, name ", folderName);
            QMessageBox::critical(this, HEMY_GUI::MSG_TYPE_ERROR, HEMY_GUI::ERR_STR::ERR_FOLDER_CREATE_FAILED);
            return ERR_NEW_FOLDER_FAILED;
        }

        QMessageBox::information(this, HEMY_GUI::MSG_TYPE_SUCCESS, HEMY_GUI::ERR_STR::ERR_FOLDER_CREATE_SUCCESS);
        return ERR_OK;
    }

    // 打开文件
    ErrCode HFile::OpenFile(QString& fileName, QString title)
    {
        fileName = QFileDialog::getOpenFileName(
            this,
            title,
            QDir::homePath(),
            HEMY_GUI::DIALOG::FILE::ALL_FILE
        );

        if (fileName.isEmpty()) {
            LOG_ERROR("open file failed, file name is empty");
            return ERR_OPEN_FILE_FAILED;
        }

        // 实际应用中这里处理文件打开操作
        const QString message = HEMY_GUI::DIALOG::FILE::SELECT + fileName;
        QMessageBox::information(this, HEMY_GUI::DIALOG::FILE::SELECTED, message);
        return ERR_OK;
    }

    // 打开文件夹
    ErrCode HFile::OpenFolder(QString& dirPath, QString title)
    {
        dirPath = QFileDialog::getExistingDirectory(
            this,
            title,
            QDir::homePath()
        );

        if (dirPath.isEmpty()) {
            return ERR_OPEN_FOLDER_FAILED;
        }

        // 实际应用中这里处理文件夹打开操作
        QMessageBox::information(this, HEMY_GUI::DIALOG::FOLDER::SELECTED,
                                HEMY_GUI::DIALOG::FOLDER::SELECT.arg(dirPath));
        return ERR_OK;
    }


    ErrCode HFile::SaveFile(QString title)
    {
        return ERR_OK;
    }

    ErrCode HFile::SaveAsFile(QString title)
    {
        return ERR_OK;
    }
}
