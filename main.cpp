#include <iostream>
#include <QApplication>
#include <QFile>
#include <QtCore5Compat/QTextCodec>
#include "hmain_window.h"
#include "common.h"
#include "gui_comm_def.h"

#ifdef _WIN32
    #include <windows.h>
#endif

int main(int argc, char* argv[])
{
    // 日志控制台显示
#ifdef _WIN32
    SetConsoleOutputCP(65001); // 设置控制台输出编码为UTF-8
    if (AttachConsole(ATTACH_PARENT_PROCESS) || AllocConsole()) {
        freopen("CONOUT$", "w", stdout);
        freopen("CONOUT$", "w", stderr);
        std::ios::sync_with_stdio();
    }
#endif
    qputenv("QT_USE_DIRECTWRITE", "0");  // 禁用DirectWrite

    HEMY_API::Logger::getInstance().initialize("run.log", LogLevel::LOG_DEBUG, true);
    QApplication app(argc, argv);
    // 设置全局UTF-8编码
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    // 设置应用程序属性
    QApplication::setApplicationName(HEMY_GUI::APP_NAME);
    QApplication::setApplicationDisplayName(HEMY_GUI::MAIN_WINDOW_TITLE);
    QApplication::setWindowIcon(QIcon(":/icons/app_icon.png"));

    // 加载QSS样式表
    QFile styleFile(":/style/default_black.css");  // 使用资源系统
    // QFile styleFile("path/to/style.qss"); // 或直接路径
    if (styleFile.open(QIODevice::ReadOnly)) {
        QString styleSheet = styleFile.readAll();
        app.setStyleSheet(styleSheet); // 全局应用
        styleFile.close();
    }


    HemyUI::HMainWindow::GetInst()->Initial();
    const auto w = HemyUI::HMainWindow::GetInst();
    w->show();
    return QApplication::exec();
}
