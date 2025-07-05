//
// Created by Administrator on 25-7-4.
//
#include <QPainter>
#include "h_menu_bar.h"
#include "h_menu_file.h"
#include "h_menu_edit.h"
#include "h_menu_view.h"
#include "h_menu_coding.h"
#include "h_menu_insert.h"
#include "h_menu_setting.h"
#include "h_menu_tools.h"
#include "h_menu_plugins.h"
#include "h_menu_online_tools.h"
#include "h_menu_links.h"
#include "h_menu_help.h"
#include "common.h"
#include "default.h"

namespace HemyMenu {
    HMenuBar::HMenuBar(QWidget *parent): QMenuBar(parent) {
        setMenuBarSheetStyle();
        CreateHemyMenus();
    }

    void HMenuBar::CreateHemyMenus() {
        static const MenuCreator menus[] = {
            {&menuFile_,        [](QWidget *p) { return new HMenuFile(p); },       getMenuAttr(MenuItemType::MENU_FILE)},
            {&menuEdit_,        [](QWidget *p) { return new HMenuEdit(p); },       getMenuAttr(MenuItemType::MENU_EDIT)},
            {&menuView_,        [](QWidget *p) { return new HMenuView(p); },       getMenuAttr(MenuItemType::MENU_VIEW)},
            {&menuCoding_,      [](QWidget *p) { return new HMenuCoding(p); },     getMenuAttr(MenuItemType::MENU_CODING)},
            {&menuInsert_,      [](QWidget *p) { return new HMenuInsert(p); },     getMenuAttr(MenuItemType::MENU_INSERT)},
            {&menuSettings_,    [](QWidget *p) { return new HMenuSetting(p); },    getMenuAttr(MenuItemType::MENU_SETTING)},
            {&menuTools_,       [](QWidget *p) { return new HMenuTools(p); },      getMenuAttr(MenuItemType::MENU_TOOLS)},
            {&menuPlugins_,     [](QWidget *p) { return new HMenuPlugin(p); },     getMenuAttr(MenuItemType::MENU_PLUGIN)},
            {&menuOnlineTools_, [](QWidget *p) { return new HMenuOnlineTool(p); }, getMenuAttr(MenuItemType::MENU_ONLINE_TOOL)},
            {&menuLinks_,       [](QWidget *p) { return new HMenuLinks(p); },      getMenuAttr(MenuItemType::MENU_LINK)},
            {&menuHelp_,        [](QWidget *p) { return new HMenuHelp(p); },       getMenuAttr(MenuItemType::MENU_HELP)},
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