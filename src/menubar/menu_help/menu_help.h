//
// Created by zhaoj on 25-7-13.
//

#ifndef MENU_HELP_H
#define MENU_HELP_H
#include "menu_base.h"
#include "common.h"

namespace HemyMenu
{
    // 13. 帮助菜单映射
    class HMenuHelp final : public MenuBase {
    public:
        explicit HMenuHelp(QWidget *parent = nullptr);
        ~HMenuHelp() override = default;

        static void onHelpMenuActionHandler(const MenuItemID& itemId, const QString& objName);
    private:
        void InitialHelpMenuItems();
    };
}
#endif //MENU_HELP_H
