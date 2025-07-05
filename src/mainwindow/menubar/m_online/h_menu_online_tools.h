//
// Created by Administrator on 25-7-5.
//

#ifndef HEMY_MAIN_WIN_MENU_ONLINE_TOOLS_H
#define HEMY_MAIN_WIN_MENU_ONLINE_TOOLS_H
#include <QMenu>
#include "menu_base.h"
#include "common.h"

namespace HemyMenu
{
    class HMenuOnlineTool final : public MenuBase {
    public:
        explicit HMenuOnlineTool(QWidget *parent = nullptr);
        ~HMenuOnlineTool() override = default;
    private:
        void CreateMenuOnlineTool();
    };
}

#endif //HEMY_MAIN_WIN_MENU_ONLINE_TOOLS_H
