//
// Created by zhaoj on 25-7-6.
//

#ifndef CODING_CONVERT_H
#define CODING_CONVERT_H

#include "common.h"
#include "menu_base.h"


namespace HemyMenu
{
    class HemyCodingSubMenuCvt : public MenuBase
    {
        public:
            explicit HemyCodingSubMenuCvt(QWidget *parent = nullptr);
            ~HemyCodingSubMenuCvt() override = default;

        private:
            QAction* actionCodeCvtAnsi = nullptr;
            QAction* actionCodeCvtUtf8 = nullptr;
            QAction* actionCodeCvtUtf16LE = nullptr;
            QAction* actionCodeCvtUtf16BE = nullptr;
            QAction* actionCodeCvtBig5 = nullptr;
            QAction* actionCodeCvtBig5Hkscs = nullptr;
            QAction* actionCodeCvtGbk = nullptr;
            QAction* actionCodeCvtGbk2312 = nullptr;
            QAction* actionCodeCvtGbk18030 = nullptr;
            QAction* actionCodeCvtHex = nullptr;

            void CreateCodingSubMenuConvert();
    };
}




#endif //CODING_CONVERT_H
