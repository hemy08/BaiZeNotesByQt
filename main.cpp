#include <iostream>
#include <QApplication>
#include <QFile>
#include <QPushButton>
#include <QMessageBox>
#include "hmain_window.h"
#include "common.h"

#ifdef _WIN32
    #include <windows.h>
#endif

int main(int argc, char* argv[])
{
#ifdef _WIN32
    FreeConsole();   // 隐藏控制台窗口
#endif

    QApplication app(argc, argv);
    // 设置应用程序属性
    QApplication::setApplicationName(WIN_TITLE);
    QApplication::setApplicationDisplayName("HemyEdit");
    QApplication::setWindowIcon(QIcon(":/icons/app_icon.png")); // 如果有图标

    HemyUI::HMainWindow w;
    w.ShowWindow();
    return QApplication::exec();
}
