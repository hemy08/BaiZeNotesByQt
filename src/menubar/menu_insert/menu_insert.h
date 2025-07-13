//
// Created by zhaoj on 25-7-13.
//

#ifndef MENU_INSERT_H
#define MENU_INSERT_H
#include "menu_base.h"
#include "common.h"

namespace HemyMenu
{
    // 5. 插入菜单映射
    class HMenuInsert final : public MenuBase {
    public:
        explicit HMenuInsert(QWidget *parent = nullptr);
        ~HMenuInsert() override = default;

        static void onInsertMenuActionHandler(const MenuItemID& itemId, const QString& objName);
    private:
        void InitialInsertMenuItems();
    };
}
#endif //MENU_INSERT_H
