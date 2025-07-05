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
        // 添加编辑菜单项
        QAction* undoAction = addAction(tr("&Undo"));
        QAction* redoAction = addAction(tr("&Redo"));
        addSeparator();
        QAction* cutAction = addAction(tr("Cu&t"));
        QAction* copyAction = addAction(tr("&Copy"));
        QAction* pasteAction = addAction(tr("&Paste"));
    }
}