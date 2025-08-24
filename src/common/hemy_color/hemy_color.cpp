//
// Created by zhaoj on 25-8-10.
//

#include "hemy_color.h"

#include "hemy_font.h"

namespace HCommon {
    HemColor::HemColor()
    {
        // 获取应用程序默认调色板
        QPalette palette = QApplication::palette();
        // 获取窗口背景色
        QColor windowColor = palette.color(QPalette::Window);
        // 获取文本颜色
        QColor textColor = palette.color(QPalette::WindowText);
        // 获取高亮颜色（如选中项的背景色）
        QColor highlightColor = palette.color(QPalette::Highlight);
    }

    HemColor::~HemColor()
    {
    }

    HemColor HemColor::GetInst()
    {
        HemColor instance;
        return instance;
    }

    QColor HemColor::GetWindowsColor() const
    {
        return windowColor;
    }

    QColor HemColor::GetTextColor() const
    {
        return textColor;
    }

    QColor HemColor::GetHighLightColor() const
    {
        return highlightColor;
    }

    void HemColor::SetAppDefaultBackGroundColor(QRgb rgb)
    {
        backGroundColor.setRgb(rgb);
    }

    QColor HemColor::GetAppDefaultBackGroundColor()
    {
        return backGroundColor;
    }

    QPalette HemColor::GetAppDefaultBackGroundPalette()
    {
        backGroundPalette = QApplication::palette();
        backGroundPalette.setColor(QPalette::Window, backGroundColor);
        return backGroundPalette;
    }

    void HemColor::SetAppDefaultColor(QRgb rgb)
    {
        defaultColor.setRgb(rgb);
    }

    QColor HemColor::GetAppDefaultColor()
    {
        return defaultColor;
    }

    QColor HemColor::GetAppStatusBarDefaultColor(QRgb rgb)
    {
        defaultStatusBarColor.setRgb(rgb);
        return defaultStatusBarColor;
    }
} // HColor