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
        HemyFileSubMenuExport *m_export_ = nullptr;;
        HemyFileSubMenuImport *m_import_ = nullptr;;
        QAction *actionNewFile = nullptr;;
        QAction *actionNewDir = nullptr;;
        QAction *actionOpenFile = nullptr;;
        QAction *actionOpenDir = nullptr;;
        QAction *actionSave = nullptr;;
        QAction *actionSaveAs = nullptr;;
        QAction *actionReloadDisk = nullptr;;
        QAction *actionExit = nullptr;;

        void CreateMenuFile();
    };
}



#endif //HEMY_MAIN_WIN_MENU_FILE_H
