//
// Created by zhaoj on 25-7-6.
//

#ifndef VIEW_EXPAND_H
#define VIEW_EXPAND_H
#include <QMenu>
#include "common.h"
#include "menu_base.h"


namespace HemyMenu
{
    class HemyViewSubMenuExpand : public MenuBase
    {
        Q_OBJECT
    public:
        explicit HemyViewSubMenuExpand(QWidget *parent = nullptr);
        ~HemyViewSubMenuExpand() override = default;

    private:
        QAction *actionExpand1 = nullptr;
        QAction *actionExpand2 = nullptr;
        QAction *actionExpand3 = nullptr;
        QAction *actionExpand4 = nullptr;
        QAction *actionExpand5 = nullptr;
        QAction *actionExpand6 = nullptr;
        void CreateViewSubMenuExpand();
    };
}


#endif //VIEW_EXPAND_H
