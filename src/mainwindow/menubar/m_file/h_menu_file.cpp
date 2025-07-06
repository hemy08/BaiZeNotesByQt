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
        actionNewFile = createAction(getMenuItemAttr(MenuItem::MENU_FILE, MenuItemType::M_FILE_NEW_File));
        actionNewDir = createAction(getMenuItemAttr(MenuItem::MENU_FILE, MenuItemType::M_FILE_NEW_DIR));
        addSeparator();
        // 打开
        actionOpenFile = createAction(getMenuItemAttr(MenuItem::MENU_FILE, MenuItemType::M_FILE_OPEN_File));
        actionOpenDir = createAction(getMenuItemAttr(MenuItem::MENU_FILE, MenuItemType::M_FILE_OPEN_DIR));
        addSeparator();
        // 导入导出
        m_import_ = new HemyFileSubMenuImport(this);
        addMenu(m_import_);
        m_export_ = new HemyFileSubMenuExport(this);
        addMenu(m_export_);
        addSeparator();
        // 保存
        actionSave = createAction(getMenuItemAttr(MenuItem::MENU_FILE, MenuItemType::M_FILE_SAVE));
        actionSaveAs = createAction(getMenuItemAttr(MenuItem::MENU_FILE, MenuItemType::M_FILE_SAVE_AS));
        actionReloadDisk = createAction(getMenuItemAttr(MenuItem::MENU_FILE, MenuItemType::M_FILE_RELOAD));
        addSeparator();
        actionExit = createAction(getMenuItemAttr(MenuItem::MENU_FILE, MenuItemType::M_FILE_EXIT));
    }
}