//
// Created by zhaoj on 25-7-13.
//

#ifndef MENU_VIEW_H
#define MENU_VIEW_H
#include "menu_base.h"
#include "common.h"

namespace HemyUI
{
    // 2. 编辑菜单映射
    class HMenuView final : public MenuBase {
    public:
        explicit HMenuView(QWidget *parent = nullptr);
        ~HMenuView() override = default;

    private:
        void InitialMenuItems();
        void MenuActionHandle(const MenuItemID& itemId, const QString& objName);
    };
}
#endif //MENU_VIEW_H
