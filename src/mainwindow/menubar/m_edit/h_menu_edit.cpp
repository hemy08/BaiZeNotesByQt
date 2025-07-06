//
// Created by Administrator on 25-7-5.
//

#include "h_menu_edit.h"

namespace HemyMenu
{
    HMenuEdit::HMenuEdit(QWidget *parent): MenuBase(parent) {
        CreateMenuEdit();

    }
    void HMenuEdit::CreateMenuEdit()
    {
        actionRedo = createAction(getMenuItemAttr(MenuItem::MENU_EDIT, MenuItemType::M_EDIT_REDO));
        actionUndo = createAction(getMenuItemAttr(MenuItem::MENU_EDIT, MenuItemType::M_EDIT_UNDO));
        addSeparator();

        actionCopy = createAction(getMenuItemAttr(MenuItem::MENU_EDIT, MenuItemType::M_EDIT_COPY));
        actionCut = createAction(getMenuItemAttr(MenuItem::MENU_EDIT, MenuItemType::M_EDIT_COPY));
        actionPaste = createAction(getMenuItemAttr(MenuItem::MENU_EDIT, MenuItemType::M_EDIT_PASTE));
        addSeparator();

        actionGoLine = createAction(getMenuItemAttr(MenuItem::MENU_EDIT, MenuItemType::M_EDIT_GO_LINE));
        addSeparator();
        // 保存
        actionFind = createAction(getMenuItemAttr(MenuItem::MENU_EDIT, MenuItemType::M_EDIT_FIND_FILE));
        actionReplace = createAction(getMenuItemAttr(MenuItem::MENU_EDIT, MenuItemType::M_EDIT_REPLACE_FILE));
        actionFindDir = createAction(getMenuItemAttr(MenuItem::MENU_EDIT, MenuItemType::M_EDIT_FIND_DIR));
        actionReplaceDir = createAction(getMenuItemAttr(MenuItem::MENU_EDIT, MenuItemType::M_EDIT_REPLACE_DIR));
    }
}