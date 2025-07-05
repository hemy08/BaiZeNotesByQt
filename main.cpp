#include <QApplication>
#include <QPushButton>
#include "hmain_window.h"
#include "const_def.h"
#include "qt_style.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    // 设置应用程序属性
    QApplication::setApplicationName(ConstMainWin::TITLE);
    QApplication::setApplicationDisplayName("HemyEdit");
    QApplication::setWindowIcon(QIcon(":/icons/app_icon.png")); // 如果有图标

    HemyUi::HMainWindow w;
    w.ShowWindow();
    return QApplication::exec();
}
