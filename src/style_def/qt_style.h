//
// Created by Administrator on 25-7-4.
//

#ifndef QT_STYLE_H
#define QT_STYLE_H
#include <QString>
#include <QStringList>
#include <QStyleFactory>

namespace HemyStyle
{
    // - 跨平台现代风格
    // - 在Windows、macOS和Linux上外观一致
    // - 支持自定义调色板
    const QString QT_STYLE_Fusion = "Fusion";
    // 原生Windows风格（Windows 10/11）,自动适配不同 Windows 版本（XP, Vista, 7, 10, 11）
    const QString QT_STYLE_Window = "Window";
    // Windows XP 经典风格, 蓝色主题和圆角按钮
    const QString QT_STYLE_WinXP = "WindowsXP";
    // Windows Vista风格
    const QString QT_STYLE_WinVista = "WindowsVista";
    // 原生macOS风格（仅macOS可用）
    const QString QT_STYLE_MacOS = "macOS";
    const QString QT_STYLE_Macintosh = "Macintosh";
    // Linux GTK+风格（需要GTK+环境）
    const QString QT_STYLE_GTK = "GTK+";
    // KDE Plasma桌面默认风格
    const QString QT_STYLE_Breeze = "Breeze";
    // KDE Plasma传统风格
    const QString QT_STYLE_Oxygen = "Oxygen";
    // 可高度定制的Qt风格（需安装）
    const QString QT_STYLE_QtCurve = "QtCurve";
    // 传统Unix Common Desktop Environment风格
    const QString QT_STYLE_CDE = "CDE";
    // 传统Motif风格（Unix）
    const QString QT_STYLE_Motif = "Motif";
    // KDE 3 默认风格, 轻微 3D 效果
    const QString QT_STYLE_Plastique = "Plastique";
    // 简约 GTK 风格， 类似 GNOME 2 界面
    const QString QT_STYLE_Cleanlooks = "Cleanlooks";


    inline QStringList styles = QStyleFactory::keys();
}
#endif //QT_STYLE_H
