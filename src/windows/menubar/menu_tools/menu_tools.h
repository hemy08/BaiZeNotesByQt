//
// Created by zhaoj on 25-7-13.
//

#ifndef MENU_TOOLS_H
#define MENU_TOOLS_H
#include "menu_base.h"
#include "common.h"

namespace HemyUI
{
    // 8. 工具菜单映射
    class HMenuTools final : public MenuBase {
    public:
        explicit HMenuTools(QWidget *parent = nullptr);
        ~HMenuTools() override = default;

    private:
        void InitialMenuItems();
        void MenuActionHandle(const MenuItemID& itemId, const QString& objName);
    };
}
#endif //MENU_TOOLS_H
