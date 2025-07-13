//
// Created by Administrator on 25-7-4.
//
#include <QPainter>
#include "menu_bar.h"
#include "hemy_menu.h"
#include "common.h"
#include "default.h"
#include "menu_file.h"
#include "menu_edit.h"
#include "menu_view.h"
#include "menu_coding.h"
#include "menu_insert.h"
#include "menu_model.h"
#include "menu_setting.h"
#include "menu_tools.h"
#include "menu_plugin.h"
#include "menu_help.h"

namespace HemyMenu {
    HMenuBar::HMenuBar(QWidget *parent): QMenuBar(parent) {
        setMenuBarSheetStyle();
        CreateHemyMenus();
    }

    void HMenuBar::CreateHemyMenus() {
        static const MenuCreator menus[] = {
            {&menuFile_, [](QWidget *p) { return new HMenuFile(p); }, getMenuAttr(MenuItemID::MENU_FILE)},
            {&menuEdit_, [](QWidget *p) { return new HMenuEdit(p); }, getMenuAttr(MenuItemID::MENU_EDIT)},
            {&menuView_, [](QWidget *p) { return new HMenuView(p); }, getMenuAttr(MenuItemID::MENU_VIEW)},
            {&menuCoding_, [](QWidget *p) { return new HMenuCoding(p); }, getMenuAttr(MenuItemID::MENU_CODING)},
            {&menuInsert_, [](QWidget *p) { return new HMenuInsert(p); }, getMenuAttr(MenuItemID::MENU_INSERT)},
            {&menuModel_, [](QWidget *p) { return new HMenuModel(p); }, getMenuAttr(MenuItemID::MENU_MODEL)},
            {&menuSettings_, [](QWidget *p) { return new HMenuSetting(p); }, getMenuAttr(MenuItemID::MENU_SETTING)},
            {&menuTools_, [](QWidget *p) { return new HMenuTools(p); }, getMenuAttr(MenuItemID::MENU_TOOLS)},
            {&menuPlugins_, [](QWidget *p) { return new HMenuPlugin(p); }, getMenuAttr(MenuItemID::MENU_PLUGIN)},
            {&menuCustom_, [](QWidget *p) { return new HMenuCustom(p); }, getMenuAttr(MenuItemID::MENU_CUSTOM_TOOLS)},
            {&menuOnlineTools_, [](QWidget *p) { return new HMenuOnlineTool(p); }, getMenuAttr(MenuItemID::MENU_ONLINE_TOOL)},
            {&menuLinks_, [](QWidget *p) { return new HMenuLinks(p); }, getMenuAttr(MenuItemID::MENU_LINK)},
            {&menuHelp_, [](QWidget *p) { return new HMenuHelp(p); }, getMenuAttr(MenuItemID::MENU_HELP)},
        };
        // 循环创建并添加菜单
        for (const auto& info : menus) {
            *info.target = info.create(this);
            (*info.target)->setTitle(info.attr.label); // 设置标题
            addMenu(*info.target);
        }
    }

    void HMenuBar::setMenuBarSheetStyle()
    {
        setObjectName("CustomMenuBar");
        setStyleSheet(HemyStyle::DefaultBlack_MenuBar);
        setLayoutDirection(Qt::LeftToRight);
        // 确保菜单栏占据整个宽度
        setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    }

    void HMenuBar::paintEvent(QPaintEvent *e)
    {
        // 然后绘制菜单项
        QMenuBar::paintEvent(e);
    }
} // HMENU