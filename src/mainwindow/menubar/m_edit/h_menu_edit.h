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
        void CreateMenuEdit();
    };
}



#endif //HEMY_MAIN_WIN_MENU_EDIT_H
