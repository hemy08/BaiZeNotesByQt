//
// Created by zhaoj on 25-7-13.
//

#ifndef MENU_CODING_H
#define MENU_CODING_H
#include "menu_base.h"
#include "common.h"

namespace HemyMenu
{
    // 4. 编码菜单映射
    class HMenuCoding final : public MenuBase {
    public:
        explicit HMenuCoding(QWidget *parent = nullptr);
        ~HMenuCoding() override = default;

        static void onCodingMenuActionHandler(const MenuItemID& itemId, const QString& objName);
    private:
        void InitialCodingMenuItems();
    };
}

#endif //MENU_CODING_H
