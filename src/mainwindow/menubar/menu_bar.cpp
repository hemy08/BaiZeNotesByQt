//
// Created by Administrator on 25-7-4.
//
#include <QPainter>
#include "menu_bar.h"
#include "hemy_menu.h"
#include "common.h"
#include "default.h"

namespace HemyMenu {
    HMenuBar::HMenuBar(QWidget *parent): QMenuBar(parent) {
        setMenuBarSheetStyle();
        CreateHemyMenus();
    }

    void HMenuBar::CreateHemyMenus() {
        static const MenuCreator menus[] = {
            {&menuFile_, [](QWidget *p) { return new HMenuFile(p); }, getMenuAttr(SubMenuType::MENU_FILE)},
            {&menuEdit_, [](QWidget *p) { return new HMenuEdit(p); }, getMenuAttr(SubMenuType::MENU_EDIT)},
            {&menuView_, [](QWidget *p) { return new HMenuView(p); }, getMenuAttr(SubMenuType::MENU_VIEW)},
            {&menuCoding_, [](QWidget *p) { return new HMenuCoding(p); }, getMenuAttr(SubMenuType::MENU_CODING)},
            {&menuInsert_, [](QWidget *p) { return new HMenuInsert(p); }, getMenuAttr(SubMenuType::MENU_INSERT)},
            {&menuModel_, [](QWidget *p) { return new HMenuModel(p); }, getMenuAttr(SubMenuType::MENU_MODEL)},
            {&menuSettings_, [](QWidget *p) { return new HMenuSetting(p); }, getMenuAttr(SubMenuType::MENU_SETTING)},
            {&menuTools_, [](QWidget *p) { return new HMenuTools(p); }, getMenuAttr(SubMenuType::MENU_TOOLS)},
            {&menuPlugins_, [](QWidget *p) { return new HMenuPlugin(p); }, getMenuAttr(SubMenuType::MENU_PLUGIN)},
            {&menuCustom_, [](QWidget *p) { return new HMenuCustom(p); }, getMenuAttr(SubMenuType::MENU_CUSTOM_TOOLS)},
            {&menuOnlineTools_, [](QWidget *p) { return new HMenuOnlineTool(p); }, getMenuAttr(SubMenuType::MENU_ONLINE_TOOL)},
            {&menuLinks_, [](QWidget *p) { return new HMenuLinks(p); }, getMenuAttr(SubMenuType::MENU_LINK)},
            {&menuHelp_, [](QWidget *p) { return new HMenuHelp(p); }, getMenuAttr(SubMenuType::MENU_HELP)},
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