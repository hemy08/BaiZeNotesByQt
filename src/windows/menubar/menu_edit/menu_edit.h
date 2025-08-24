//
// Created by zhaoj on 25-7-13.
//

#ifndef MENU_EDIT_H
#define MENU_EDIT_H
#include "menu_base.h"
#include "common.h"

namespace HemyUI
{
    // 2. 编辑菜单映射
    class HMenuEdit final : public MenuBase {
    public:
        explicit HMenuEdit(QWidget *parent = nullptr);
        ~HMenuEdit() override = default;

    private:
        void InitialMenuItems();
        void MenuActionHandle(const MenuItemID& itemId, const QString& objName);
    };
}
#endif //MENU_EDIT_H
