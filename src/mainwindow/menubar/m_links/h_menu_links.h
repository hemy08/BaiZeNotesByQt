//
// Created by Administrator on 25-7-5.
//

#ifndef HEMY_MAIN_WIN_MENU_LINKS_H
#define HEMY_MAIN_WIN_MENU_LINKS_H
#include <QMenu>
#include "const_def.h"

namespace HemyMenu
{
    class HMenuLinks final : public QMenu {
    public:
        explicit HMenuLinks(QWidget *parent = nullptr);
        ~HMenuLinks() override = default;
    private:
        void CreateMenuLinks();
    };
}



#endif //HEMY_MAIN_WIN_MENU_LINKS_H
