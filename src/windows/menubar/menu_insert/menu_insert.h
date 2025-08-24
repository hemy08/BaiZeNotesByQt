//
// Created by zhaoj on 25-7-13.
//

#ifndef MENU_INSERT_H
#define MENU_INSERT_H
#include "menu_base.h"
#include "common.h"

namespace HemyUI
{
    // 5. 插入菜单映射
    class HMenuInsert final : public MenuBase {
    public:
        explicit HMenuInsert(QWidget *parent = nullptr);
        ~HMenuInsert() override = default;

    private:
        void InitialMenuItems();
        void MenuActionHandle(const MenuItemID& itemId, const QString& objName);
        void SpecialFontDialog();
        void KatexDialog();
    };
}
#endif //MENU_INSERT_H
