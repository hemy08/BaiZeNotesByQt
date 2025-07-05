//
// Created by Administrator on 25-6-29.
//

#ifndef CONST_DEF_H
#define CONST_DEF_H
#include <QString>

namespace ConstMainWin
{
    const QString TITLE = "Hemy Markdown Editor Developed Based on Qt Framework";
    const QString OBJ_NAME = "HMainWindow";
    constexpr uint32_t MAIN_DEFAULT_WIDTH = 1440;
    constexpr uint32_t MAIN_DEFAULT_HEIGHT = 960;
}

namespace ConstMenuBar
{
    const QString OBJ_NAME = "CustomMenuBar";
    const QString MENU_FILE = "文件";
    const QString MENU_EDIT = "编辑";
    const QString MENU_VIEW = "视图";
    const QString MENU_CODING = "文件编码";
    const QString MENU_INSERT = "插入";
    const QString MENU_SETTING = "设置";
    const QString MENU_TOOLS = "工具";
    const QString MENU_PLUGIN = "插件";
    const QString MENU_ONLINE_TOOL = "在线工具";
    const QString MENU_LINK = "链接";
    const QString MENU_HELP = "帮助";
}

namespace ConstMenuFile
{
    struct MenuItemAttr {
        const QString obj_name;
        const QString label;
        const QString shortcut;
    };
    const QString OBJ_NAME_FILE = "MenuFile";

    MenuItemAttr MENU_FILE = {"MenuFile", "文件", "Alt+F"};
    MenuItemAttr NEW_File = {"ActionNewFile", "新建文件", "Ctrl+N"};
    MenuItemAttr NEW_DIR = {"ActionNewDir", "新建文件夹", "Ctrl+D"};
    MenuItemAttr OPEN_File = {"ActionOpenFile", "打开文件", "Ctrl+Alt+N"};
    MenuItemAttr OPEN_DIR = {"ActionOpenDir", "打开文件夹", "Ctrl+Alt+D"};
    MenuItemAttr SAVE = {"ActionSave", "保存", "Ctrl+S"};
    MenuItemAttr SAVE_AS = {"ActionSaveAs", "另存为", "Ctrl+Shift+S"};
    MenuItemAttr RELOAD = {"ActionReloadFromDisk", "从磁盘重新加载", "Ctrl+Alt+Y"};
    MenuItemAttr EXIT = {"ActionExit", "退出", "Alt+F4"};
    MenuItemAttr IMPORT = {"FileSubMenuImport", "导入", ""};
    MenuItemAttr IMPORT_WORD = {"FromWord", "从 Word 导入", ""};
    MenuItemAttr IMPORT_HTML = {"FromHtml", "从 Html 导入", ""};
    MenuItemAttr IMPORT_JSON = {"FromJson", "从 Json 导入", ""};
    MenuItemAttr IMPORT_YAML = {"FromYaml", "从 Word 导入", ""};
    MenuItemAttr IMPORT_XML = {"FromXml", "从 XML 导入", ""};
    MenuItemAttr IMPORT_TXT = {"FromTxt", "从文本文件导入", ""};
    MenuItemAttr EXPORT = {"FileSubMenuExport", "导出", ""};
    MenuItemAttr EXPORT_WORD = {"ToWord", "导出到 Word", ""};
    MenuItemAttr EXPORT_JSON = {"ToJson", "导出到 Json", ""};
    MenuItemAttr EXPORT_XML = {"ToXml", "导出到 XML", ""};
    MenuItemAttr EXPORT_YAML = {"ToYaml", "导出到 Yaml", ""};
    MenuItemAttr EXPORT_HTML = {"ToHtml", "导出到 Html", ""};
    MenuItemAttr EXPORT_PDF = {"ToPdf", "导出到 Pdf", ""};
    MenuItemAttr EXPORT_TXT = {"ToTxt", "导出到 Txt", ""};
}

#endif //CONST_DEF_H

