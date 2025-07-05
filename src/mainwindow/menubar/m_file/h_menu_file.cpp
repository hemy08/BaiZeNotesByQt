//
// Created by Administrator on 25-7-5.
//

#include "h_menu_file.h"
#include "const_def.h"

namespace HemyMenu
{
    HMenuFile::HMenuFile(QWidget *parent): QMenu(parent) {
        CreateMenuFile();
    }
    void HMenuFile::CreateMenuFile()
    {
        // 新建
        ActionNewFile();
        ActionNewDir();
        addSeparator();
        // 打开
        ActionOpenFile();
        ActionOpenDir();
        addSeparator();
        // 导入导出
        m_import_ = new HemyFileSubMenuImport(this);
        m_export_ = new HemyFileSubMenuExport(this);
        addMenu(m_import_);
        addMenu(m_export_);
        addSeparator();
        // 保存
        ActionSave();
        ActionSaveAs();
        ActionReloadDisk();
        addSeparator();
        ActionExit();
    }

    void HMenuFile::ActionNewFile() {
        actionNewFile = addAction(ConstMenuFile::NEW_File.label);
        actionNewFile->setObjectName(ConstMenuFile::NEW_File.obj_name);
        actionNewFile->setShortcut(ConstMenuFile::NEW_File.shortcut);

    }

    void HMenuFile::ActionNewDir() {
        actionNewDir = addAction(ConstMenuFile::NEW_DIR.label);
        actionNewDir->setObjectName(ConstMenuFile::NEW_DIR.obj_name);
        actionNewDir->setShortcut(ConstMenuFile::NEW_DIR.shortcut);
    }

    void HMenuFile::ActionOpenFile() {
        actionNewFile = addAction(ConstMenuFile::OPEN_File.label);
        actionNewFile->setObjectName(ConstMenuFile::OPEN_File.obj_name);
        actionNewFile->setShortcut(ConstMenuFile::OPEN_File.shortcut);
    }

    void HMenuFile::ActionOpenDir() {
        actionNewFile = addAction(ConstMenuFile::OPEN_DIR.label);
        actionNewFile->setObjectName(ConstMenuFile::OPEN_DIR.obj_name);
        actionNewFile->setShortcut(ConstMenuFile::OPEN_DIR.shortcut);
    }

    void HMenuFile::ActionSave() {
        actionNewFile = addAction(ConstMenuFile::SAVE.label);
        actionNewFile->setObjectName(ConstMenuFile::SAVE.obj_name);
        actionNewFile->setShortcut(ConstMenuFile::SAVE.shortcut);
    }

    void HMenuFile::ActionSaveAs() {
        actionNewFile = addAction(ConstMenuFile::SAVE_AS.label);
        actionNewFile->setObjectName(ConstMenuFile::SAVE_AS.obj_name);
        actionNewFile->setShortcut(ConstMenuFile::SAVE_AS.shortcut);
    }

    void HMenuFile::ActionReloadDisk() {
        actionNewFile = addAction(ConstMenuFile::RELOAD.label);
        actionNewFile->setObjectName(ConstMenuFile::RELOAD.obj_name);
        actionNewFile->setShortcut(ConstMenuFile::RELOAD.shortcut);
    }

    void HMenuFile::ActionExit() {
        actionNewFile = addAction(ConstMenuFile::EXIT.label);
        actionNewFile->setObjectName(ConstMenuFile::EXIT.obj_name);
        actionNewFile->setShortcut(ConstMenuFile::EXIT.shortcut);
    }
}