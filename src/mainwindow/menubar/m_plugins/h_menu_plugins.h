//
// Created by Administrator on 25-7-5.
//

#ifndef HEMY_MAIN_WIN_MENU_PLUGINS_H
#define HEMY_MAIN_WIN_MENU_PLUGINS_H
#include <QMenu>
#include "const_def.h"

namespace HemyMenu
{
    class HMenuPlugin final : public QMenu {
    public:
        explicit HMenuPlugin(QWidget *parent = nullptr);
        ~HMenuPlugin() override = default;
    private:
        void CreateMenuPlugin();
    };
}


#endif //HEMY_MAIN_WIN_MENU_PLUGINS_H
