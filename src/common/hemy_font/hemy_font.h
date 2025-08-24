//
// Created by zhaoj on 25-8-10.
//

#ifndef HEMY_FONT_H
#define HEMY_FONT_H
#include "special_font_dialog.h"

namespace HCommon
{
    class HemyFont: public QFont {
    public:
        explicit HemyFont();
        ~HemyFont();
        static HemyFont GetInst();
        QFont GetSystemFont();
        void SetAppDefaultFont(const QString& fontName, int pointSize);
        QFont GetAppDefaultFont();
        QString GetAppDefaultFontFamily();
        QFont GetAppStatusBarFont();

    private:
        QFont systemFont;
        QFont defaultFont;
        QFont statusBarFont;
        QStringList sysFontFamilies;
    };

}




#endif //HEMY_FONT_H
