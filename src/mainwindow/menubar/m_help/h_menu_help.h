//
// Created by Administrator on 25-7-5.
//

#ifndef HEMY_MAIN_WIN_MENU_HELP_H
#define HEMY_MAIN_WIN_MENU_HELP_H
#include <QMenu>
#include "menu_base.h"
#include "common.h"

namespace HemyMenu
{
    class HMenuHelp final : public MenuBase {
    public:
        explicit HMenuHelp(QWidget *parent = nullptr);
        ~HMenuHelp() override = default;
    private:
        void CreateMenuHelp();
    };
}


#endif //HEMY_MAIN_WIN_MENU_HELP_H
