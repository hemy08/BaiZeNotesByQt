//
// Created by zhaoj on 25-8-10.
//

#ifndef HEMY_COLOR_H
#define HEMY_COLOR_H
#include <QColor>
#include <QPalette>

namespace HCommon {

    class HemColor: public QColor {
    public:
        explicit HemColor();
        ~HemColor();
        static HemColor GetInst();
        QColor GetWindowsColor() const;
        QColor GetTextColor() const;
        QColor GetHighLightColor() const;
        void SetAppDefaultBackGroundColor(QRgb rgb);
        QColor GetAppDefaultBackGroundColor();
        QPalette GetAppDefaultBackGroundPalette();
        void SetAppDefaultColor(QRgb rgb);
        QColor GetAppDefaultColor();
        QColor GetAppStatusBarDefaultColor(QRgb rgb);

    private:
        // 获取窗口背景色
        QColor windowColor;
        // 获取文本颜色
        QColor textColor;
        // 获取高亮颜色（如选中项的背景色）
        QColor highlightColor;
        QColor defaultColor;
        QColor backGroundColor;
        QPalette backGroundPalette;
        QColor defaultStatusBarColor;
    };

} // HColor

#endif //HEMY_COLOR_H
