//
// Created by Administrator on 25-7-5.
//

#ifndef HEMY_MAIN_WIN_MENU_FILE_H
#define HEMY_MAIN_WIN_MENU_FILE_H
#include <QMenu>
#include "menu_base.h"
#include "common.h"
#include "file_export_to.h"
#include "file_import_from.h"

namespace HemyMenu
{
    class HMenuFile final : public MenuBase {
    public:
        explicit HMenuFile(QWidget *parent = nullptr);
        ~HMenuFile() override = default;

        // 提供访问子菜单的接口
        [[nodiscard]] HemyFileSubMenuImport* fileSubMenuImport() const { return m_import_; }
        [[nodiscard]] HemyFileSubMenuExport* fileSubMenuExport() const { return m_export_; }
    private:
        HemyFileSubMenuExport *m_export_{};
        HemyFileSubMenuImport *m_import_{};
        QAction *actionNewFile;
        QAction *actionNewDir;
        QAction *actionOpenFile;
        QAction *actionOpenDir;
        QAction *actionSave;
        QAction *actionSaveAs;
        QAction *actionReloadDisk;
        QAction *actionExit;

        void CreateMenuFile();
        void ActionNewFile();
        void ActionNewDir();
        void ActionOpenFile();
        void ActionOpenDir();
        void ActionSave();
        void ActionSaveAs();
        void ActionReloadDisk();
        void ActionExit();
    };
}



#endif //HEMY_MAIN_WIN_MENU_FILE_H
