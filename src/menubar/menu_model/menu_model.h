//
// Created by zhaoj on 25-7-13.
//

#ifndef MENU_MODEL_H
#define MENU_MODEL_H
#include "menu_base.h"
#include "common.h"

namespace HemyMenu
{
    // 6. 模板菜单映射
    class HMenuModel final : public MenuBase {
    public:
        explicit HMenuModel(QWidget *parent = nullptr);
        ~HMenuModel() override = default;

        static void onModelMenuActionHandler(const MenuItemID& itemId, const QString& objName);
    private:
        void InitialModelMenuItems();
    };
}
#endif //MENU_MODEL_H
