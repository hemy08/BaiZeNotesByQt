//
// Created by zhaoj on 25-7-9.
//

#ifndef HEMY_MENU_H
#define HEMY_MENU_H
#include "menu_base.h"
#include "common.h"

namespace HemyMenu
{
    // 9. 插件菜单映射
    class HMenuPlugin final : public MenuBase {
    public:
        explicit HMenuPlugin(QWidget *parent = nullptr);
        ~HMenuPlugin() override = default;
    private:
        void InitialMenuItems();
    };

    // 10. 自定义工具菜单映射
    class HMenuCustom final : public MenuBase {
    public:
        explicit HMenuCustom(QWidget *parent = nullptr);
        ~HMenuCustom() override = default;
    private:

        void InitialMenuItems();
    };

    // 11. 在线工具菜单映射
    class HMenuOnlineTool final : public MenuBase {
    public:
        explicit HMenuOnlineTool(QWidget *parent = nullptr);
        ~HMenuOnlineTool() override = default;
    private:
        void InitialMenuItems();
    };

    // 12. 链接菜单映射
    class HMenuLinks final : public MenuBase {
    public:
        explicit HMenuLinks(QWidget *parent = nullptr);
        ~HMenuLinks() override = default;
    private:
        void InitialMenuItems();
    };

    // 13. 帮助菜单映射
    class HMenuHelp final : public MenuBase {
    public:
        explicit HMenuHelp(QWidget *parent = nullptr);
        ~HMenuHelp() override = default;
    private:
        void InitialMenuItems();
    };
}

#endif //HEMY_MENU_H
