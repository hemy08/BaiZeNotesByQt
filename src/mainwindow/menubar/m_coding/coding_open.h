//
// Created by zhaoj on 25-7-6.
//

#ifndef CODING_OPEN_H
#define CODING_OPEN_H
#include "common.h"
#include "menu_base.h"


#include "common.h"
#include "menu_base.h"


namespace HemyMenu
{
    class HemyCodingSubMenuOpen : public MenuBase
    {
    public:
        explicit HemyCodingSubMenuOpen(QWidget *parent = nullptr);
        ~HemyCodingSubMenuOpen() override = default;

    private:
        QAction* actionCodeOpenAnsi = nullptr;
        QAction* actionCodeOpenUtf8 = nullptr;
        QAction* actionCodeOpenUtf16LE = nullptr;
        QAction* actionCodeOpenUtf16BE = nullptr;
        QAction* actionCodeOpenBig5 = nullptr;
        QAction* actionCodeOpenBig5Hkscs = nullptr;
        QAction* actionCodeOpenGbk = nullptr;
        QAction* actionCodeOpenGbk2312 = nullptr;
        QAction* actionCodeOpenGbk18030 = nullptr;
        QAction* actionCodeOpenHex = nullptr;

        void CreateCodingSubMenuOpen();
    };
}


#endif //CODING_OPEN_H
