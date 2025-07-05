//
// Created by Administrator on 25-7-5.
//

#ifndef H_MENY_INSERT_H
#define H_MENY_INSERT_H
#include <QMenu>
#include "menu_base.h"
#include "common.h"

namespace HemyMenu
{
    class HMenuSetting final : public MenuBase {
    public:
        explicit HMenuSetting(QWidget *parent = nullptr);
        ~HMenuSetting() override = default;
    private:
        void CreateMenuSettings();
    };
}


#endif //H_MENY_INSERT_H
