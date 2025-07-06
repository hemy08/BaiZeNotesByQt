//
// Created by zhaoj on 25-7-6.
//

#ifndef VIEW_FOLD_H
#define VIEW_FOLD_H
#include <QMenu>
#include "common.h"
#include "menu_base.h"

namespace HemyMenu
{
    class HemyViewSubMenuFold : public MenuBase
    {
        Q_OBJECT
    public:
        explicit HemyViewSubMenuFold(QWidget *parent = nullptr);
        ~HemyViewSubMenuFold() override = default;

    private:
        QAction *actionFold1 = nullptr;
        QAction *actionFold2 = nullptr;
        QAction *actionFold3 = nullptr;
        QAction *actionFold4 = nullptr;
        QAction *actionFold5 = nullptr;
        QAction *actionFold6 = nullptr;
        void CreateViewSubMenuFold();
    };

}

#endif //VIEW_FOLD_H
