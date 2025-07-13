//
// Created by zhaoj on 25-7-13.
//

#ifndef MENU_PLUGIN_H
#define MENU_PLUGIN_H
#include "menu_base.h"
#include "common.h"

namespace HemyMenu
{
    // 9. 插件菜单映射
    class HMenuPlugin final : public MenuBase {
    public:
        explicit HMenuPlugin(QWidget *parent = nullptr);
        ~HMenuPlugin() override = default;

        static void onPluginMenuActionHandler(const MenuItemID& itemId, const QString& objName, const QString& url);
    private:
        void InitialPluginMenuItems();
    };
}
#endif //MENU_PLUGIN_H
