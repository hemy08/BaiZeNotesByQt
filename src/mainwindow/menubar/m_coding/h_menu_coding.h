//
// Created by Administrator on 25-7-5.
//

#ifndef HEMY_MAIN_WIN_MENU_CODE_H
#define HEMY_MAIN_WIN_MENU_CODE_H
#include <QMenu>
#include "menu_base.h"
#include "common.h"

namespace HemyMenu {
    class HMenuCoding final : public MenuBase {
    public:
        explicit HMenuCoding(QWidget *parent = nullptr);
        ~HMenuCoding() override = default;

    private:
        void CreateMenuCoding();
    };
}



#endif //HEMY_MAIN_WIN_MENU_CODE_H
