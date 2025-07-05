//
// Created by Administrator on 25-7-5.
//

#ifndef HEMY_MAIN_WIN_MENU_INSERT_H
#define HEMY_MAIN_WIN_MENU_INSERT_H
#include <QMenu>
#include "menu_base.h"
#include "common.h"

namespace HemyMenu
{
    class HMenuInsert final : public MenuBase {
    public:
        explicit HMenuInsert(QWidget *parent = nullptr);
        ~HMenuInsert() override = default;
    private:
        void CreateMenuInsert();
    };
}



#endif //HEMY_MAIN_WIN_MENU_INSERT_H
