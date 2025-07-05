//
// Created by Administrator on 25-7-5.
//

#ifndef HEMY_MAIN_WIN_MENU_HELP_H
#define HEMY_MAIN_WIN_MENU_HELP_H
#include <QMenu>
#include "const_def.h"

namespace HemyMenu
{
    class HMenuHelp final : public QMenu {
    public:
        explicit HMenuHelp(QWidget *parent = nullptr);
        ~HMenuHelp() override = default;
    private:
        void CreateMenuHelp();
    };
}


#endif //HEMY_MAIN_WIN_MENU_HELP_H
