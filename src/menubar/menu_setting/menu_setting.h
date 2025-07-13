//
// Created by zhaoj on 25-7-13.
//

#ifndef MENU_SETTING_H
#define MENU_SETTING_H
#include "menu_base.h"
#include "common.h"

namespace HemyMenu
{
    // 7. 设置菜单映射
    class HMenuSetting final : public MenuBase {
    public:
        explicit HMenuSetting(QWidget *parent = nullptr);
        ~HMenuSetting() override = default;

        static void onSettingMenuActionHandler(const MenuItemID& itemId, const QString& objName);
    private:
        void InitialSettingMenuItems();
    };
}
#endif //MENU_SETTING_H
