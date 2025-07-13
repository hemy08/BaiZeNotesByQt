//
// Created by zhaoj on 25-7-13.
//

#ifndef MENU_FILE_H
#define MENU_FILE_H
#include "menu_base.h"
#include "common.h"

namespace HemyMenu
{
    // 1. 文件菜单映射
    class HMenuFile final : public MenuBase {
    public:
        explicit HMenuFile(QWidget *parent = nullptr);
        ~HMenuFile() override = default;
        static void onFileMenuActionHandler(const MenuItemID& itemId, const QString& objName);
        static void onFileMenuImportAction(const MenuItemID& itemId, const QString& objName);
        static void onFileMenuExportAction(const MenuItemID& itemId, const QString& objName);

    private:
        void InitialFileMenuItems();
    };


}

#endif //MENU_FILE_H