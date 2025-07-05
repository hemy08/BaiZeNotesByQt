//
// Created by Administrator on 25-7-5.
//
#include "const_menu.h"

MenuItemAttr getMenuAttr(MenuItemType type) {
    static const std::unordered_map<MenuItemType, MenuItemAttr> map = {
            {MenuItemType::OBJ_NAME_FILE, {"MenuFile", "文件", "Alt+F"}},


            {MenuItemType::MENU_FILE, {"MenuFile", "文件(&F)", "Alt+F"}},
            {MenuItemType::M_FILE_NEW_File, {"ActionNewFile", "新建文件", "Ctrl+N"}},
            {MenuItemType::M_FILE_NEW_DIR, {"ActionNewDir", "新建文件夹", "Ctrl+D"}},
            {MenuItemType::M_FILE_OPEN_File, {"ActionOpenFile", "打开文件", "Ctrl+Alt+N"}},
            {MenuItemType::M_FILE_OPEN_DIR, {"ActionOpenDir", "打开文件夹", "Ctrl+Alt+D"}},
            {MenuItemType::M_FILE_SAVE, {"ActionSave", "保存", "Ctrl+S"}},
            {MenuItemType::M_FILE_SAVE_AS, {"ActionSaveAs", "另存为", "Ctrl+Shift+S"}},
            {MenuItemType::M_FILE_RELOAD, {"ActionReloadFromDisk", "从磁盘重新加载", "Ctrl+Alt+Y"}},
            {MenuItemType::M_FILE_EXIT, {"ActionExit", "退出", "Alt+F4"}},
            {MenuItemType::M_FILE_IMPORT, {"FileSubMenuImport", "导入", ""}},
            {MenuItemType::M_FILE_IMPORT_WORD, {"FromWord", "从 Word 导入", ""}},
            {MenuItemType::M_FILE_IMPORT_HTML, {"FromHtml", "从 Html 导入", ""}},
            {MenuItemType::M_FILE_IMPORT_JSON, {"FromJson", "从 Json 导入", ""}},
            {MenuItemType::M_FILE_IMPORT_YAML, {"FromYaml", "从 Yaml 导入", ""}},
            {MenuItemType::M_FILE_IMPORT_XML, {"FromXml", "从 XML 导入", ""}},
            {MenuItemType::M_FILE_IMPORT_TXT, {"FromTxt", "从文本文件导入", ""}},
            {MenuItemType::M_FILE_EXPORT, {"FileSubMenuExport", "导出", ""}},
            {MenuItemType::M_FILE_EXPORT_WORD, {"ToWord", "导出到 Word", ""}},
            {MenuItemType::M_FILE_EXPORT_JSON, {"ToJson", "导出到 Json", ""}},
            {MenuItemType::M_FILE_EXPORT_XML, {"ToXml", "导出到 XML", ""}},
            {MenuItemType::M_FILE_EXPORT_YAML, {"ToYaml", "导出到 Yaml", ""}},
            {MenuItemType::M_FILE_EXPORT_HTML, {"ToHtml", "导出到 Html", ""}},
            {MenuItemType::M_FILE_EXPORT_PDF, {"ToPdf", "导出到 Pdf", ""}},


            {MenuItemType::MENU_EDIT, {"MenuEdit", "编辑(&E)", "Alt+E"}},
            {MenuItemType::MENU_VIEW, {"MenuView", "视图(&V)", "Alt+V"}},
            {MenuItemType::MENU_CODING, {"MenuCoding", "文件编码(&C)", "Alt+C"}},
            {MenuItemType::MENU_INSERT, {"MenuInsert", "插入(&I)", "Alt+I"}},
            {MenuItemType::MENU_SETTING, {"MenuSetting", "设置(&S)", "Alt+S"}},
            {MenuItemType::MENU_TOOLS, {"MenuTools", "工具(&T)", "Alt+T"}},
            {MenuItemType::MENU_PLUGIN, {"MenuPlugins", "插件(&P)", "Alt+P"}},
            {MenuItemType::MENU_ONLINE_TOOL, {"MenuOnlineTool", "在线工具(&O)", "Alt+O"}},
            {MenuItemType::MENU_LINK, {"MenuLinks", "链接(&L)", "Alt+L"}},
            {MenuItemType::MENU_HELP, {"MenuHelp", "帮助(&H)", "Alt+H"}},
    };
    return map.at(type);
}