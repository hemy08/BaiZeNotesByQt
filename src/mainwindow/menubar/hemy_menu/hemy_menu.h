//
// Created by zhaoj on 25-7-9.
//

#ifndef HEMY_MENU_H
#define HEMY_MENU_H
#include "menu_base.h"
#include "common.h"

namespace HemyMenu
{
    // 1. 文件菜单映射
    class HMenuFile final : public MenuBase {
    public:
        explicit HMenuFile(QWidget *parent = nullptr);
        ~HMenuFile() override = default;
    private:
        void CreateMenuFile();
    };

    // 2. 编辑菜单映射
    class HMenuEdit final : public MenuBase {
    public:
        explicit HMenuEdit(QWidget *parent = nullptr);
        ~HMenuEdit() override = default;
    private:
        void CreateMenuEdit();
    };

    // 3. 视图菜单映射
    class HMenuView final : public MenuBase {
    public:
        explicit HMenuView(QWidget *parent = nullptr);
        ~HMenuView() override = default;
    private:
        void CreateMenuView();
    };

    // 4. 编码菜单映射
    class HMenuCoding final : public MenuBase {
    public:
        explicit HMenuCoding(QWidget *parent = nullptr);
        ~HMenuCoding() override = default;
    private:
        void CreateMenuCoding();
    };

    // 5. 插入菜单映射
    class HMenuInsert final : public MenuBase {
    public:
        explicit HMenuInsert(QWidget *parent = nullptr);
        ~HMenuInsert() override = default;
    private:
        void CreateMenuInsert();
    };

    // 6. 模板菜单映射
    class HMenuModel final : public MenuBase {
    public:
        explicit HMenuModel(QWidget *parent = nullptr);
        ~HMenuModel() override = default;
    private:
        void CreateMenuModel();
    };

    // 7. 设置菜单映射
    class HMenuSetting final : public MenuBase {
    public:
        explicit HMenuSetting(QWidget *parent = nullptr);
        ~HMenuSetting() override = default;
    private:
        void CreateMenuSettings();
    };

    // 8. 工具菜单映射
    class HMenuTools final : public MenuBase {
    public:
        explicit HMenuTools(QWidget *parent = nullptr);
        ~HMenuTools() override = default;
    private:
        void CreateMenuTools();
    };

    // 9. 插件菜单映射
    class HMenuPlugin final : public MenuBase {
    public:
        explicit HMenuPlugin(QWidget *parent = nullptr);
        ~HMenuPlugin() override = default;
    private:
        void CreateMenuPlugin();
    };

    // 10. 自定义工具菜单映射
    class HMenuCustom final : public MenuBase {
    public:
        explicit HMenuCustom(QWidget *parent = nullptr);
        ~HMenuCustom() override = default;
    private:

        void CreateMenuCustom();
    };

    // 11. 在线工具菜单映射
    class HMenuOnlineTool final : public MenuBase {
    public:
        explicit HMenuOnlineTool(QWidget *parent = nullptr);
        ~HMenuOnlineTool() override = default;
    private:
        void CreateMenuOnlineTool();
    };

    // 12. 链接菜单映射
    class HMenuLinks final : public MenuBase {
    public:
        explicit HMenuLinks(QWidget *parent = nullptr);
        ~HMenuLinks() override = default;
    private:
        void CreateMenuLinks();
    };

    // 13. 帮助菜单映射
    class HMenuHelp final : public MenuBase {
    public:
        explicit HMenuHelp(QWidget *parent = nullptr);
        ~HMenuHelp() override = default;
    private:
        void CreateMenuHelp();
    };
}

#endif //HEMY_MENU_H
