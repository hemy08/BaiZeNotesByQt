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
#include "default.h"


namespace HemyMenu {
    struct MenuCreator {
        QMenu** varPtr;
        std::function<QMenu*()> create;
        QString title;
    };

    HMenuBar::HMenuBar(QWidget *parent): QMenuBar(parent) {
        setMenuBarSheetStyle();
        CreateHemyMenus();
    }

    void HMenuBar::CreateHemyMenus() {
        const QList<MenuCreator> creators = {
            { &menuFile_,[this]{ return new HMenuFile(this); },ConstMenuBar::MENU_FILE },
            { &menuEdit_,[this]{ return new HMenuEdit(this); },ConstMenuBar::MENU_EDIT},
            { &menuView_,[this]{ return new HMenuView(this); },ConstMenuBar::MENU_VIEW },
            { &menuCoding_,[this]{ return new HMenuCoding(this); },ConstMenuBar::MENU_CODING },
            { &menuInsert_,[this]{ return new HMenuInsert(this); },ConstMenuBar::MENU_INSERT },
            { &menuSettings_,[this]{ return new HMenuSetting(this); },ConstMenuBar::MENU_SETTING },
            { &menuTools_,[this]{ return new HMenuTools(this); },ConstMenuBar::MENU_TOOLS },
            { &menuPlugins_,[this]{ return new HMenuPlugin(this); },ConstMenuBar::MENU_PLUGIN },
            { &menuOnlineTools_,[this]{ return new HMenuOnlineTool(this); },ConstMenuBar::MENU_ONLINE_TOOL },
            { &menuLinks_,[this]{ return new HMenuLinks(this); },ConstMenuBar::MENU_LINK },
            { &menuHelp_,[this]{ return new HMenuHelp(this); },ConstMenuBar::MENU_HELP },
        };

        // 循环创建并添加菜单
        for (const auto& creator : creators) {
            *creator.varPtr = creator.create();
            (*creator.varPtr)->setTitle(creator.title); // 设置标题
            addMenu(*creator.varPtr);
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