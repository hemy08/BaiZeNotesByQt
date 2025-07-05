//
// Created by Administrator on 25-7-5.
//

#include "h_menu_file.h"
#include "common.h"

namespace HemyMenu
{
    HMenuFile::HMenuFile(QWidget *parent): MenuBase(parent) {
        CreateMenuFile();
    }
    void HMenuFile::CreateMenuFile()
    {
        // 新建
        actionNewFile = createAction(getMenuAttr(MenuItemType::M_FILE_NEW_File));
        actionNewDir = createAction(getMenuAttr(MenuItemType::M_FILE_NEW_DIR));
        addSeparator();
        // 打开
        actionOpenFile = createAction(getMenuAttr(MenuItemType::M_FILE_OPEN_File));
        actionOpenDir = createAction(getMenuAttr(MenuItemType::M_FILE_OPEN_DIR));
        addSeparator();
        // 导入导出
        m_import_ = new HemyFileSubMenuImport(this);
        m_export_ = new HemyFileSubMenuExport(this);
        addMenu(m_import_);
        addMenu(m_export_);
        addSeparator();
        // 保存
        actionSave = createAction(getMenuAttr(MenuItemType::M_FILE_SAVE));
        actionSaveAs = createAction(getMenuAttr(MenuItemType::M_FILE_SAVE_AS));
        actionReloadDisk = createAction(getMenuAttr(MenuItemType::M_FILE_RELOAD));
        addSeparator();
        actionExit = createAction(getMenuAttr(MenuItemType::M_FILE_EXIT));
    }
}