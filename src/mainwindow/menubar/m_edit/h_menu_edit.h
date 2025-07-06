//
// Created by Administrator on 25-7-5.
//

#ifndef HEMY_MAIN_WIN_MENU_EDIT_H
#define HEMY_MAIN_WIN_MENU_EDIT_H
#include <QMenu>
#include "menu_base.h"
#include "common.h"

namespace HemyMenu
{
    class HMenuEdit final : public MenuBase {
    public:
        explicit HMenuEdit(QWidget *parent = nullptr);
        ~HMenuEdit() override = default;
    private:
        QAction* actionRedo = nullptr;
        QAction* actionUndo = nullptr;
        QAction* actionCopy = nullptr;
        QAction* actionCut = nullptr;
        QAction* actionPaste = nullptr;
        QAction* actionGoLine = nullptr;
        QAction* actionFind = nullptr;
        QAction* actionReplace = nullptr;
        QAction* actionFindDir = nullptr;
        QAction* actionReplaceDir = nullptr;

        void CreateMenuEdit();
    };
}



#endif //HEMY_MAIN_WIN_MENU_EDIT_H
