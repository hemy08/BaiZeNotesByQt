//
// Created by zhaoj on 25-7-13.
//

#ifndef MENU_VIEW_H
#define MENU_VIEW_H
#include "menu_base.h"
#include "common.h"

namespace HemyMenu
{
    // 2. 编辑菜单映射
    class HMenuView final : public MenuBase {
    public:
        explicit HMenuView(QWidget *parent = nullptr);
        ~HMenuView() override = default;

        static void onViewMenuActionHandler(const MenuItemID& itemId, const QString& objName);
    private:
        void InitialViewMenuItems();
    };
}
#endif //MENU_VIEW_H
