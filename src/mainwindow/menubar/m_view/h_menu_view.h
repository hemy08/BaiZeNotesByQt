//
// Created by Administrator on 25-7-5.
//

#ifndef HEMY_MAIN_WIN_MENU_VIEW_H
#define HEMY_MAIN_WIN_MENU_VIEW_H
#include <QMenu>
#include "menu_base.h"
#include "common.h"

namespace HemyMenu
{
    class HMenuView final : public MenuBase {
    public:
        explicit HMenuView(QWidget *parent = nullptr);
        ~HMenuView() override = default;
    private:
        void CreateMenuView();
    };
}


#endif //HEMY_MAIN_WIN_MENU_VIEW_H
