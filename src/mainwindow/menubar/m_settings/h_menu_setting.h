//
// Created by Administrator on 25-7-5.
//

#ifndef H_MENY_INSERT_H
#define H_MENY_INSERT_H
#include <QMenu>
#include "const_def.h"

namespace HemyMenu
{
    class HMenuSetting final : public QMenu {
    public:
        explicit HMenuSetting(QWidget *parent = nullptr);
        ~HMenuSetting() override = default;
    private:
        void CreateMenuSettings();
    };
}


#endif //H_MENY_INSERT_H
