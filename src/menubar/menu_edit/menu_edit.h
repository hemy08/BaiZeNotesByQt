//
// Created by zhaoj on 25-7-13.
//

#ifndef MENU_EDIT_H
#define MENU_EDIT_H
#include "menu_base.h"
#include "common.h"

namespace HemyMenu
{
    // 2. 编辑菜单映射
    class HMenuEdit final : public MenuBase {
    public:
        explicit HMenuEdit(QWidget *parent = nullptr);
        ~HMenuEdit() override = default;

        static void onEditMenuActionHandler(const MenuItemID& itemId, const QString& objName);
    private:
        void InitialEditMenuItems();
    };
}
#endif //MENU_EDIT_H
