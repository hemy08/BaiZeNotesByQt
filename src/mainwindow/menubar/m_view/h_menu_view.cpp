//
// Created by Administrator on 25-7-5.
//

#include "h_menu_view.h"


namespace HemyMenu
{
    HMenuView::HMenuView(QWidget *parent): MenuBase(parent) {
        CreateMenuView();

    }
    void HMenuView::CreateMenuView()
    {
        actionEditModel = createAction(getMenuItemAttr(MenuItem::MENU_VIEW, MenuItemType::M_VIEW_EDIT_MOD));
        actionPreviewModel = createAction(getMenuItemAttr(MenuItem::MENU_VIEW, MenuItemType::M_VIEW_PREVIEW_MOD));
        actionEditPreview = createAction(getMenuItemAttr(MenuItem::MENU_VIEW, MenuItemType::M_VIEW_EDIT_PREVIEW));
        addSeparator();

        actionShowExplorer = createAction(getMenuItemAttr(MenuItem::MENU_VIEW, MenuItemType::M_VIEW_SHOW_EXPLORER));
        actionShowToc = createAction(getMenuItemAttr(MenuItem::MENU_VIEW, MenuItemType::M_VIEW_SHOW_TOC));
        actionShowLineNo = createAction(getMenuItemAttr(MenuItem::MENU_VIEW, MenuItemType::M_VIEW_SHOW_LINE_NO));
        actionShowLineBreak = createAction(getMenuItemAttr(MenuItem::MENU_VIEW, MenuItemType::M_VIEW_SHOW_LINE_BREAK));
        actionShowSpace = createAction(getMenuItemAttr(MenuItem::MENU_VIEW, MenuItemType::M_VIEW_SHOW_SPACE));
        actionShowAll = createAction(getMenuItemAttr(MenuItem::MENU_VIEW, MenuItemType::M_VIEW_SHOW_ALL));
        addSeparator();

        actionFoldAll = createAction(getMenuItemAttr(MenuItem::MENU_VIEW, MenuItemType::M_VIEW_FOLD_ALL));
        actionExpandAll = createAction(getMenuItemAttr(MenuItem::MENU_VIEW, MenuItemType::M_VIEW_EXPAND_ALL));
        actionFoldCur = createAction(getMenuItemAttr(MenuItem::MENU_VIEW, MenuItemType::M_VIEW_FOLD_CUR));
        actionExpandCur = createAction(getMenuItemAttr(MenuItem::MENU_VIEW, MenuItemType::M_VIEW_EXPAND_CUR));
        // 导入导出
        m_fold_ = new HemyViewSubMenuFold(this);
        addMenu(m_fold_);
        m_expand_ = new HemyViewSubMenuExpand(this);
        addMenu(m_expand_);
    }
}