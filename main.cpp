#include <QApplication>
#include <QPushButton>
#include "hmain_window.h"
#include "common.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    // 设置应用程序属性
    QApplication::setApplicationName(WIN_TITLE);
    QApplication::setApplicationDisplayName("HemyEdit");
    QApplication::setWindowIcon(QIcon(":/icons/app_icon.png")); // 如果有图标

    HemyUI::HMainWindow w;
    w.ShowWindow();
    return QApplication::exec();
}
