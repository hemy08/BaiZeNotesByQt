//
// Created by zhaoj on 25-8-10.
//

#ifndef COMM_DEF_H
#define COMM_DEF_H
#include <qmargins.h>
#include <QString>

namespace HEMY_GUI
{
    inline static const QString APP_NAME = "白泽笔记";
    inline static const QString MAIN_WINDOW_TITLE = "白泽笔记 -- Markdown Editor Powered By Qt Widgets";
    inline static const QString MAIN_WINDOW_OBJ_NAME = "HMainWindow";
    inline static constexpr uint32_t MAIN_WINDOW_DEFAULT_WIDTH = 1440;
    inline static constexpr uint32_t MAIN_WINDOW_DEFAULT_HEIGHT = 960;

    inline static constexpr uint32_t ZERO_SPLITER_WIDTH = 0;
    inline static constexpr uint32_t MAIN_SPLITER_WIDTH = 3;
    inline static constexpr uint32_t WORKBENCH_SPLITER_WIDTH = 1;
    inline static constexpr uint32_t EDITOR_PREVIEW_SPLITER_WIDTH = 1;

    inline static constexpr uint32_t ZERO_SPACING = 0;
    inline static constexpr QMargins ZERO_MARGINS = QMargins(0, 0, 0, 0);

    inline static constexpr uint32_t SIDEBAR_WIDTH_MIN = 50;
    inline static constexpr uint32_t SIDEBAR_WIDTH_MAX = 50;
    inline static constexpr uint32_t SIDEBAR_SPACING = 10;
    inline static constexpr QMargins SIDEBAR_MARGINS = QMargins(8, 20, 2, 20);

    inline static constexpr uint32_t EXPLORER_WIDTH_MIN = 250;
    inline static constexpr uint32_t EXPLORER_WIDTH_MAX = 900;
    inline static constexpr QMargins EXPLORER_MARGINS = QMargins(10, 20, 10, 20);

    inline static constexpr uint32_t WORKBENCH_WIDTH_MIN = 500;
    inline static constexpr uint32_t WORKBENCH_WIDTH_MAX = 1200;
    inline static constexpr uint32_t WORKBENCH_SPACING = 2;
    inline static constexpr QMargins WORKBENCH_MARGINS = QMargins(5, 2, 5, 2);

    inline static constexpr uint32_t WORKBENCH_MENU_HEIGHT = 50;

    inline static constexpr QMargins EDITOR_PREVIEW_MARGINS = QMargins(0, 0, 0, 0);

    inline static const QString MSG_TYPE_SUCCESS = "成功";
    inline static const QString MSG_TYPE_ERROR = "错误";
    inline static const QString MSG_TYPE_WARNING = "警告";

    namespace DIALOG::FILE
    {
        inline static const QString TITLE = "新建文件";
        inline static const QString NAME = "文件名";
        inline static const QString ALREADY_EXIST = "文件已经存在!";
        inline static const QString CREATE_SUCCESS = "文件创建成功!";
        inline static const QString CREATE_FAILED = "文件创建失败!";
        inline static const QString OPEN = "打开文件/文件列表";
        inline static const QString ALL_FILE = "所有文件(*)";
        inline static const QString SELECT = "选中文件：\n";
        inline static const QString SELECTED = "选定的文件";
    }

    namespace DIALOG::FOLDER
    {
        inline static const QString TITLE = "新建文件夹";
        inline static const QString NAME = "文件夹名称";
        inline static const QString ALREADY_EXIST = "文件夹已经存在!";
        inline static const QString CREATE_SUCCESS = "文件夹创建成功!";
        inline static const QString CREATE_FAILED = "文件夹创建失败!";
        inline static const QString SELECT = "选中文件夹：\n%1";
        inline static const QString SELECTED = "选定的文件夹";
    }

    namespace ERR_STR
    {
        inline static const QString ERR_FILE_ALREADY_EXIST = "文件已经存在!";
        inline static const QString ERR_FILE_CREATE_SUCCESS = "文件创建成功!";
        inline static const QString ERR_FILE_CREATE_FAILED = "文件创建失败!";
        inline static const QString ERR_FILE_NAME_EMPTY = "文件名为空!";
        inline static const QString ERR_FOLDER_ALREADY_EXIST = "文件夹已经存在!";
        inline static const QString ERR_FOLDER_CREATE_SUCCESS = "文件夹创建成功!";
        inline static const QString ERR_FOLDER_CREATE_FAILED = "文件夹创建失败!";
        inline static const QString ERR_FOLDER_NAME_EMPTY = "文件夹名称为空!";
    }
}




#endif //COMM_DEF_H
