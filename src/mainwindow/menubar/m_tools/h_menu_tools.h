//
// Created by Administrator on 25-7-5.
//

#ifndef HEMY_MAIN_WIN_MENU_TOOLS_H
#define HEMY_MAIN_WIN_MENU_TOOLS_H
#include <QMenu>
#include "menu_base.h"
#include "common.h"

namespace HemyMenu
{
    class HMenuTools final : public MenuBase {
    public:
        explicit HMenuTools(QWidget *parent = nullptr);
        ~HMenuTools() override = default;
    private:
        void CreateMenuTools();
    };
}

#endif //HEMY_MAIN_WIN_MENU_TOOLS_H
