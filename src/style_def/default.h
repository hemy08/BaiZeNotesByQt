//
// Created by Administrator on 25-7-4.
//

#ifndef DEFAULT_H
#define DEFAULT_H
#include <QString>

namespace HemyStyle
{
    const QString DefaultBlack_MainWindow = R"(
            /* 主窗口样式 */
            #HMainWindow {
                background-color: #2D2D30;
                font-family: 'Segoe UI';
                font-size: 12pt;
            }
        )";

    const QString DefaultBlack_MenuBar = R"(
            /* 自定义菜单栏样式 */
            #CustomMenuBar {
                background-color: #333337;
                color: white;
                padding: 0;
                border-bottom: 2px solid #00B7FF;  /* 与菜单栏边框一致 */
                height: 28px;
                font-family: 'Segoe UI';
                font-size: 12pt; /* 减小字体大小 */
            }

            #CustomMenuBar::item {
                background: transparent;
                padding: 0px 10px;
                margin: 0 4px; /* 减小水平内边距 */
                border-radius: 4px;
                min-width: 60px;  /* 设置最小宽度 */
                text-align: center; /* 文本居中 */
                line-height: 30px; /* 垂直居中 */
            }

            #CustomMenuBar::item:selected {
                background: #3F3F46;
            }

            /* 确保菜单项均匀分布 */
            #CustomMenuBar::item:first {
                margin-left: 10px;
            }

            #CustomMenuBar::item:last {
                margin-right: 10px;
            }
            #CustomMenuBar::item:pressed {
                background: #007ACC;
            }

            /* 菜单样式 */
            QMenu {
                background-color: #252526; /* 更深的背景色 */
                color: #CCCCCC;
                border: 1px solid #3F3F46;
                padding: 6px 0;
                font-family: 'Segoe UI';
                font-size: 12pt;
            }

            QMenu::item {
                padding: 6px 40px 6px 30px;
                min-height: 24px;
            }

            QMenu::item:selected {
                background-color: #094771;
                color: white;
            }

            QMenu::separator {
                height: 1px;
                background-color: #3F3F46;
                margin: 6px 0;
            }
        )";

    const QString DefaultBlack_StatusBar = R"(
            /* 状态栏样式 */
            QStatusBar {
                background-color: #007ACC;
                color: white;
                font-family: 'Segoe UI';
                font-size: 9pt;
                min-height: 24px;
            }
        )";
}

#endif //DEFAULT_H
