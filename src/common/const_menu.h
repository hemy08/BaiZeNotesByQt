//
// Created by Administrator on 25-7-5.
//

#ifndef MD_EDITOR_BY_QT_CONST_MENU_H
#define MD_EDITOR_BY_QT_CONST_MENU_H
#include <QString>
#include "common_base.h"

enum class MenuItemType {
    MENU_NONE,
    OBJ_NAME_MENU_BAR,
    // 文件菜单
    OBJ_NAME_FILE,
    MENU_FILE,
    M_FILE_NEW_File,
    M_FILE_NEW_DIR,
    M_FILE_OPEN_File,
    M_FILE_OPEN_DIR,
    M_FILE_SAVE,
    M_FILE_SAVE_AS,
    M_FILE_RELOAD,
    M_FILE_EXIT,
    M_FILE_IMPORT,
    M_FILE_IMPORT_WORD,
    M_FILE_IMPORT_HTML,
    M_FILE_IMPORT_JSON,
    M_FILE_IMPORT_YAML,
    M_FILE_IMPORT_XML,
    M_FILE_IMPORT_TXT,
    M_FILE_EXPORT,
    M_FILE_EXPORT_WORD,
    M_FILE_EXPORT_JSON,
    M_FILE_EXPORT_XML,
    M_FILE_EXPORT_YAML,
    M_FILE_EXPORT_HTML,
    M_FILE_EXPORT_PDF,

    // 编辑菜单
    MENU_EDIT,
    // 视图菜单
    MENU_VIEW,
    // 文件编码菜单
    MENU_CODING,
    // 插入菜单
    MENU_INSERT,
    // 设置菜单
    MENU_SETTING,
    // 工具菜单
    MENU_TOOLS,
    // 插件菜单
    MENU_PLUGIN,
    // 在线工具菜单
    MENU_ONLINE_TOOL,
    // 链接菜单
    MENU_LINK,
    // 帮助菜单
    MENU_HELP
};

MenuItemAttr getMenuAttr(MenuItemType type);
QString getMenuLabel(MenuItemType type);
QString getMenuShortcut(MenuItemType type);
/*
namespace CONST_MENU{
    class BAR {
    public:
        inline static const QString OBJ_NAME = "CustomMenuBar";
        inline static MenuItemAttr MENU_FILE = {"MenuFile", "文件(&F)", "Alt+F"};
        inline static MenuItemAttr MENU_EDIT = {"MenuEdit", "编辑(&E)", "Alt+E"};
        inline static MenuItemAttr MENU_VIEW = {"MenuView", "视图(&V)", "Alt+V"};
        inline static MenuItemAttr MENU_CODING = {"MenuCoding", "文件编码(&C)", "Alt+C"};
        inline static MenuItemAttr MENU_INSERT = {"MenuInsert", "插入(&I)", "Alt+I"};
        inline static MenuItemAttr MENU_SETTING = {"MenuSetting", "设置(&S)", "Alt+S"};
        inline static MenuItemAttr MENU_TOOLS = {"MenuTools", "工具(&T)", "Alt+T"};
        inline static MenuItemAttr MENU_PLUGIN = {"MenuPlugins", "插件(&P)", "Alt+P"};
        inline static MenuItemAttr MENU_ONLINE_TOOL = {"MenuOnlineTool", "在线工具(&O)", "Alt+O"};
        inline static MenuItemAttr MENU_LINK = {"MenuLinks", "链接(&L)", "Alt+L"};
        inline static MenuItemAttr MENU_HELP = {"MenuHelp", "帮助(&H)", "Alt+H"};

    };
};

namespace CONST_MENU {
    class FILE {
    public:
        inline static const QString OBJ_NAME_FILE = "MenuFile";
        inline static MenuItemAttr MENU_FILE;
        inline static MenuItemAttr NEW_File = {"ActionNewFile", "新建文件", "Ctrl+N"};
        inline static MenuItemAttr NEW_DIR = {"ActionNewDir", "新建文件夹", "Ctrl+D"};
        inline static MenuItemAttr OPEN_File = {"ActionOpenFile", "打开文件", "Ctrl+Alt+N"};
        inline static MenuItemAttr OPEN_DIR = {"ActionOpenDir", "打开文件夹", "Ctrl+Alt+D"};
        inline static MenuItemAttr SAVE = {"ActionSave", "保存", "Ctrl+S"};
        inline static MenuItemAttr SAVE_AS = {"ActionSaveAs", "另存为", "Ctrl+Shift+S"};
        inline static MenuItemAttr RELOAD = {"ActionReloadFromDisk", "从磁盘重新加载", "Ctrl+Alt+Y"};
        inline static MenuItemAttr EXIT = {"ActionExit", "退出", "Alt+F4"};
        inline static MenuItemAttr IMPORT = {"FileSubMenuImport", "导入", ""};
        inline static MenuItemAttr IMPORT_WORD = {"FromWord", "从 Word 导入", ""};
        inline static MenuItemAttr IMPORT_HTML = {"FromHtml", "从 Html 导入", ""};
        inline static MenuItemAttr IMPORT_JSON = {"FromJson", "从 Json 导入", ""};
        inline static MenuItemAttr IMPORT_YAML = {"FromYaml", "从 Yaml 导入", ""};
        inline static MenuItemAttr IMPORT_XML = {"FromXml", "从 XML 导入", ""};
        inline static MenuItemAttr IMPORT_TXT = {"FromTxt", "从文本文件导入", ""};
        inline static MenuItemAttr EXPORT = {"FileSubMenuExport", "导出", ""};
        inline static MenuItemAttr EXPORT_WORD = {"ToWord", "导出到 Word", ""};
        inline static MenuItemAttr EXPORT_JSON = {"ToJson", "导出到 Json", ""};
        inline static MenuItemAttr EXPORT_XML = {"ToXml", "导出到 XML", ""};
        inline static MenuItemAttr EXPORT_YAML = {"ToYaml", "导出到 Yaml", ""};
        inline static MenuItemAttr EXPORT_HTML = {"ToHtml", "导出到 Html", ""};
        inline static MenuItemAttr EXPORT_PDF = {"ToPdf", "导出到 Pdf", ""};
    };
};*/

#endif //MD_EDITOR_BY_QT_CONST_MENU_H
