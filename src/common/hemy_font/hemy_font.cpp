//
// Created by zhaoj on 25-8-10.
//

#include "hemy_font.h"

namespace HCommon
{
#ifdef QT_DEBUG
    const QStringList defaultFontFamilies = {
        "Arial",           // 通用
        "Microsoft YaHei UI",
    };
#else
    const QStringList defaultFontFamilies = {
        "Segoe UI",        // Windows首选
        "Helvetica Neue",  // macOS
        "Arial",           // 通用
        "Microsoft YaHei", // 中文支持
        "Microsoft YaHei UI",
        "sans-serif"       // 最终回退
    };
#endif

    HemyFont::HemyFont()
    {
        // 获取系统默认字体
        systemFont = QFontDatabase::systemFont(QFontDatabase::GeneralFont);
        sysFontFamilies = systemFont.families();
        //systemFont.setFamilies(defaultFontFamilies); // 优先级顺序
        systemFont.setPointSize(12);
        systemFont.setBold(true);
    }

    HemyFont::~HemyFont()
    {
    }

    HemyFont HemyFont::GetInst()
    {
        HemyFont inst;
        return inst;
    }

    QFont HemyFont::GetSystemFont()
    {
        return systemFont;
    }

    void HemyFont::SetAppDefaultFont(const QString& fontName, int pointSize)
    {
        defaultFont = QFont(fontName, pointSize);
        defaultFont.setFamilies(defaultFontFamilies); // 优先级顺序
    }

    QFont HemyFont::GetAppDefaultFont()
    {
        defaultFont.setFamilies(defaultFontFamilies);
        defaultFont.setPointSize(12);
        defaultFont.setBold(true);
        return defaultFont;
    }

    QString HemyFont::GetAppDefaultFontFamily()
    {
        return defaultFont.family();
    }

    QFont HemyFont::GetAppStatusBarFont()
    {
        statusBarFont.setFamilies(defaultFontFamilies);
        statusBarFont.setPointSize(9);
        statusBarFont.setBold(false);
        return statusBarFont;
    }
}
