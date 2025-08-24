//
// Created by Administrator on 25-7-5.
//
#include "const_menu.h"

#include <utility>

QList<MenuItem> getFileMenuItems(){
    return  {
        MenuItem(MenuItemID::M_FILE_NEW_FILE,"新建文件", "actionNewFile","Ctrl+N"),
        MenuItem(MenuItemID::M_FILE_NEW_FOLDER,"新建文件夹", "actionNewDir","Ctrl+D"),
        MenuItem(MenuItemID::M_FILE_OPEN_FILE,"打开文件", "actionOpenFile","Ctrl+Alt+N"),
        MenuItem(MenuItemID::M_FILE_OPEN_FOLDER,"打开文件夹", "actionOpenDir","Ctrl+Alt+D"),
        MenuItem(MenuItemID::MENU_BUTT, "", "", MenuItem::Separator),
        MenuItem(MenuItemID::M_FILE_IMPORT,"从文件导入", "FileSubMenuImport",{
            MenuItem(MenuItemID::M_FILE_IMPORT_WORD,"从 Word 导入", "FromWord",""),
            MenuItem(MenuItemID::M_FILE_IMPORT_HTML,"从 Html 导入","FromHtml",""),
            MenuItem(MenuItemID::M_FILE_IMPORT_JSON,"从 Json 导入", "FromJson",""),
            MenuItem(MenuItemID::M_FILE_IMPORT_YAML,"从 Yaml 导入", "FromYaml",""),
            MenuItem(MenuItemID::M_FILE_IMPORT_XML,"从 XML 导入", "FromXml",""),
            MenuItem(MenuItemID::M_FILE_IMPORT_TXT,"从文本文件导入", "FromTxt","")
        }),
        MenuItem(MenuItemID::M_FILE_EXPORT,"导出到文件", "FileSubMenuExport",{
            MenuItem(MenuItemID::M_FILE_EXPORT_WORD,"导出到 Word", "ToWord",""),
            MenuItem(MenuItemID::M_FILE_EXPORT_JSON,"导出到 Json", "ToJson",""),
            MenuItem(MenuItemID::M_FILE_EXPORT_XML,"导出到 XML", "ToXml",""),
            MenuItem(MenuItemID::M_FILE_EXPORT_YAML,"导出到 Yaml", "ToYaml",""),
            MenuItem(MenuItemID::M_FILE_EXPORT_HTML,"导出到 Html", "ToHtml",""),
            MenuItem(MenuItemID::M_FILE_EXPORT_PDF,"导出到 Pdf", "ToPdf","")
        }),
        MenuItem(MenuItemID::MENU_BUTT, "", "", MenuItem::Separator),
        MenuItem(MenuItemID::M_FILE_SAVE,"保存", "actionSave","Ctrl+S"),
        MenuItem(MenuItemID::M_FILE_SAVE_AS,"另存为", "actionSaveAs","Ctrl+Shift+S"),
        MenuItem(MenuItemID::M_FILE_RELOAD,"从磁盘重新加载", "actionReloadFromDisk","Ctrl+Alt+Y"),
        MenuItem(MenuItemID::MENU_BUTT, "", "", MenuItem::Separator),
        MenuItem(MenuItemID::M_FILE_EXIT,"退出", "actionExit","Alt+F4"),
    };
}

QList<MenuItem> getEditMenuItems()
{
    return  {
        MenuItem(MenuItemID::M_EDIT_UNDO, "撤销", "actionUndo", "Ctrl+Z"),
        MenuItem(MenuItemID::M_EDIT_REDO, "重做", "actionRedo", "Ctrl+Y"),
        MenuItem(MenuItemID::MENU_BUTT, "", "", MenuItem::Separator),
        MenuItem(MenuItemID::M_EDIT_COPY, "拷贝", "actionCopy", "Ctrl+C"),
        MenuItem(MenuItemID::M_EDIT_CUT, "剪切", "actionCut", "Ctrl+X"),
        MenuItem(MenuItemID::M_EDIT_PASTE, "粘贴", "actionPaste", "Ctrl+V"),
        MenuItem(MenuItemID::MENU_BUTT, "", "", MenuItem::Separator),
        MenuItem(MenuItemID::M_EDIT_FIND_FILE, "在文件中查找", "actionFind", "Ctrl+F"),
        MenuItem(MenuItemID::M_EDIT_REPLACE_FILE, "在文件中替换", "actionReplace", "Ctrl+R"),
        MenuItem(MenuItemID::M_EDIT_FIND_DIR, "在目录中查找", "actionFindDir", "Ctrl+Shift+F"),
        MenuItem(MenuItemID::M_EDIT_REPLACE_DIR, "在目录中替换", "actionReplaceDir", "Ctrl+Shift+R"),
        MenuItem(MenuItemID::MENU_BUTT, "", "", MenuItem::Separator),
        MenuItem(MenuItemID::M_EDIT_GO_LINE, "跳转到行", "actionGoToLine", "Alt+G"),
    };
}

QList<MenuItem> getViewMenuItems()
{
    return  {
        MenuItem(MenuItemID::M_VIEW_EDIT_MOD, "编辑视图", "actionEditView", "F9"),
        MenuItem(MenuItemID::M_VIEW_PREVIEW_MOD, "预览视图", "actionPreview", "F10"),
        MenuItem(MenuItemID::M_VIEW_EDIT_PREVIEW, "编辑/预览视图", "actionEditPreview", "F11"),
        MenuItem(MenuItemID::MENU_BUTT, "", "", MenuItem::Separator),
        MenuItem(MenuItemID::M_VIEW_SHOW_EXPLORER, "显示/隐藏资源管理器", "actionDisplayExplorer", ""),
        MenuItem(MenuItemID::M_VIEW_SHOW_TOC, "显示/隐藏大纲", "actionDisplayToc", ""),
        MenuItem(MenuItemID::M_VIEW_SHOW_LINE_NO, "显示/隐藏行号", "actionDisplayLineNo", ""),
        MenuItem(MenuItemID::M_VIEW_SHOW_LINE_BREAK, "显示/隐藏换行", "actionDisplayLineBreak", ""),
        MenuItem(MenuItemID::M_VIEW_SHOW_SPACE, "显示/隐藏空格", "actionDisplaySpace", ""),
        MenuItem(MenuItemID::M_VIEW_SHOW_ALL, "显示/隐藏所有符号", "actionDisplayAllChart", ""),
        MenuItem(MenuItemID::MENU_BUTT, "", "", MenuItem::Separator),
        MenuItem(MenuItemID::M_VIEW_EXPAND_ALL, "展开所有层次", "actionExpandAll", "Alt+0"),
        MenuItem(MenuItemID::M_VIEW_FOLD_ALL, "折叠所有层次", "actionFoldAll", "Alt+Shift+0"),
        MenuItem(MenuItemID::M_VIEW_EXPAND_CUR, "展开当前层次", "actionExpandCurrent", "Ctrl+Alt+F"),
        MenuItem(MenuItemID::M_VIEW_FOLD_CUR, "折叠当前层次", "actionFoldCurrent", "Ctrl+Alt+Shift+F"),
        MenuItem(MenuItemID::MENU_BUTT, "", "", MenuItem::Separator),
        MenuItem(MenuItemID::M_VIEW_FOLD, "展开层次", "ViewSubMenuFold", {
            MenuItem(MenuItemID::M_VIEW_FOLD_1, "1", "actionFold_1", "Alt+1"),
            MenuItem(MenuItemID::M_VIEW_FOLD_2, "2", "actionFold_2", "Alt+2"),
            MenuItem(MenuItemID::M_VIEW_FOLD_3, "3", "actionFold_3", "Alt+3"),
            MenuItem(MenuItemID::M_VIEW_FOLD_4, "4", "actionFold_4", "Alt+4"),
            MenuItem(MenuItemID::M_VIEW_FOLD_5, "5", "actionFold_5", "Alt+5"),
            MenuItem(MenuItemID::M_VIEW_FOLD_6, "6", "actionFold_6", "Alt+6"),
        }),
        MenuItem(MenuItemID::M_VIEW_EXPAND, "折叠层次", "ViewSubMenuExpand", {
            MenuItem(MenuItemID::M_VIEW_EXPAND_1, "1", "actionExpand_1", "Alt+Shift+1"),
            MenuItem(MenuItemID::M_VIEW_EXPAND_2, "2", "actionExpand_2", "Alt+Shift+2"),
            MenuItem(MenuItemID::M_VIEW_EXPAND_3, "3", "actionExpand_3", "Alt+Shift+3"),
            MenuItem(MenuItemID::M_VIEW_EXPAND_4, "4", "actionExpand_4", "Alt+Shift+4"),
            MenuItem(MenuItemID::M_VIEW_EXPAND_5, "5", "actionExpand_5", "Alt+Shift+5"),
            MenuItem(MenuItemID::M_VIEW_EXPAND_6, "6", "actionExpand_6", "Alt+Shift+6"),
        }),
    };
}

QList<MenuItem> getCodingMenuItems()
{
    return  {
        MenuItem(MenuItemID::M_CODING_OPEN, "使用......编码打开", "actionEditView", {
            MenuItem(MenuItemID::M_CODING_OPEN_ANSI, "ANSI", "actionPreview", ""),
            MenuItem(MenuItemID::M_CODING_OPEN_UTF8, "UTF-8", "actionEditPreview", ""),
            MenuItem(MenuItemID::M_CODING_OPEN_UTF16LE, "UTF-16 Little Endian", "actionDisplayExplorer", ""),
            MenuItem(MenuItemID::M_CODING_OPEN_UTF16BE, "UTF-16 Big Endian", "actionDisplayToc", ""),
            MenuItem(MenuItemID::M_CODING_OPEN_BG5, "Big5(繁体中文)", "actionDisplayLineNo", ""),
            MenuItem(MenuItemID::M_CODING_OPEN_BG5_HKSCS, "Big5-HKSCS(繁体中文)", "actionDisplayLineBreak", ""),
            MenuItem(MenuItemID::M_CODING_OPEN_GBK, "GBK(简体中文)", "actionDisplaySpace", ""),
            MenuItem(MenuItemID::M_CODING_OPEN_GB2312, "GBK2312(简体中文)", "actionDisplayAllChart", ""),
            MenuItem(MenuItemID::M_CODING_OPEN_GB18030, "GBK18030(简体中文)", "actionExpandAll", ""),
            MenuItem(MenuItemID::M_CODING_OPEN_HEX, "Hex(十六进制)", "actionFoldAll", ""),
        }),
        MenuItem(MenuItemID::M_CODING_CONVERT, "转为......编码", "actionExpandCurrent", {
            MenuItem(MenuItemID::M_CODING_CVT_ANSI, "ANSI", "actionFoldCurrent", ""),
            MenuItem(MenuItemID::M_CODING_CVT_UTF8, "UTF-8", "ViewSubMenuFold", ""),
            MenuItem(MenuItemID::M_CODING_CVT_UTF16LE, "UTF-16 Little Endian", "actionFold_1", ""),
            MenuItem(MenuItemID::M_CODING_CVT_UTF16BE, "UTF-16 Big Endian", "actionFold_2", ""),
            MenuItem(MenuItemID::M_CODING_CVT_BG5, "Big5(繁体中文)", "actionFold_3", ""),
            MenuItem(MenuItemID::M_CODING_CVT_BG5_HKSCS, "Big5-HKSCS(繁体中文)", "actionFold_4", ""),
            MenuItem(MenuItemID::M_CODING_CVT_GBK, "GBK(简体中文)", "actionFold_5", ""),
            MenuItem(MenuItemID::M_CODING_CVT_GB2312, "GBK2312(简体中文)", "actionFold_6", ""),
            MenuItem(MenuItemID::M_CODING_CVT_GB18030, "GBK18030(简体中文)", "ViewSubMenuExpand", ""),
            MenuItem(MenuItemID::M_CODING_CVT_HEX, "Hex(十六进制)", "actionExpand_1", ""),
        }),
        MenuItem(MenuItemID::M_CODING_NOTIFY, "注意：请勿直接编辑乱码文件", "actionExpand_6", ""),
    };
}

QList<MenuItem> getInsertMenuItems()
{
    return  {
        MenuItem(MenuItemID::M_INSERT_FONT, "特殊字体", "actionInsFonts", ""),
        MenuItem(MenuItemID::M_INSERT_KATEX, "Katex公式", "actionInsKatex", ""),
        MenuItem(MenuItemID::M_INSERT_MD_TABLE, "Markdown表格", "actionInsMdTable", ""),
        MenuItem(MenuItemID::M_INSERT_WEB_LINK, "网页链接", "actionInsWebLink", ""),
        MenuItem(MenuItemID::MENU_BUTT, "", "", MenuItem::Separator),
        MenuItem(MenuItemID::M_INSERT_TXT, "文本", "InsSubMenuTxt", {
            MenuItem(MenuItemID::M_INSERT_T_IMAGES, "图片链接", "actionInsImages", ""),
            MenuItem(MenuItemID::M_INSERT_T_CODEBLOCK, "折叠代码块", "actionInsCodeBlock", ""),
            MenuItem(MenuItemID::M_INSERT_T_MD_LIST, "有序列表", "actionInsMdList", ""),
            MenuItem(MenuItemID::M_INSERT_T_UPDATE_TIME, "更新时间", "actionInsUpdateTime", ""),
        }),
        MenuItem(MenuItemID::M_INSERT_FROM_FILE, "来自文件", "InsSubMenuFromFile", {
            MenuItem(MenuItemID::M_INSERT_F_TXT, "*.txt;*.log", "actionInsFromTxt", ""),
            MenuItem(MenuItemID::M_INSERT_F_JSON, "*.json", "actionInsFromJson", ""),
            MenuItem(MenuItemID::M_INSERT_F_INI, "*.ini", "actionInsFromIni", ""),
            MenuItem(MenuItemID::M_INSERT_F_YAML, "*.yaml;*.yml", "actionInsFromYaml", ""),
            MenuItem(MenuItemID::M_INSERT_F_XML, "*.xml", "actionInsFromXml", ""),
            MenuItem(MenuItemID::M_INSERT_F_CSV, "*.csv", "actionInsFromCsv", ""),
            MenuItem(MenuItemID::M_INSERT_F_XLS, "*.xls;*.xlsx", "actionInsFromXls", ""),
        }),
    };
}

QList<MenuItem> getModelMenuItems()
{
    return  {
        MenuItem(MenuItemID::M_MODEL_MATERIAL, "Material模块", "ModelSubMenuMaterial", {
            MenuItem(MenuItemID::M_MODEL_M_ADMONITION, "Admonition", "actionModelAdmonition", ""),
        }),
        MenuItem(MenuItemID::M_MODEL_MERMAID, "Mermaid绘图", "ModelSubMenuMermaid", {
            MenuItem(MenuItemID::M_MODEL_ME_BASE, "基础框架", "actionModelMermaidBase", ""),
            MenuItem(MenuItemID::M_MODEL_ME_FLOWCHAT, "流程图", "actionModelMermaidFlowChat", ""),
            MenuItem(MenuItemID::M_MODEL_ME_SEQUENCE, "时序图", "actionModelMermaidSequence", ""),
            MenuItem(MenuItemID::M_MODEL_ME_CLASS, "类图", "actionModelMermaidClass", ""),
            MenuItem(MenuItemID::M_MODEL_ME_STATE, "状态图", "actionModelMermaidState", ""),
            MenuItem(MenuItemID::M_MODEL_ME_ENTITY, "实体关系图", "actionModelMermaidEntity", ""),
            MenuItem(MenuItemID::M_MODEL_ME_USER_JOURNEY, "用户旅程图", "actionModelMermaidUserJourney", ""),
            MenuItem(MenuItemID::M_MODEL_ME_GANTT, "甘特图", "actionModelMermaidGantt", ""),
            MenuItem(MenuItemID::M_MODEL_ME_PIE, "饼图", "actionModelMermaidPie", ""),
            MenuItem(MenuItemID::M_MODEL_ME_QUADRANT, "象限图", "actionModelMermaidQuadrant", ""),
            MenuItem(MenuItemID::M_MODEL_ME_REQUIREMENT, "需求图", "actionModelMermaidRequirement", ""),
            MenuItem(MenuItemID::M_MODEL_ME_GIT, "GitGraph(Git)图", "actionModelMermaidGit", ""),
            MenuItem(MenuItemID::M_MODEL_ME_C4, "C4图", "actionModelMermaidC4", ""),
            MenuItem(MenuItemID::M_MODEL_ME_MINDMAP, "思维导图", "actionModelMermaidMindmap", ""),
            MenuItem(MenuItemID::M_MODEL_ME_TIMELINE, "时间线图", "actionModelMermaidTimeLine", ""),
            MenuItem(MenuItemID::M_MODEL_ME_ZEN_UML, "ZenUML", "actionModelMermaidZenUml", ""),
            MenuItem(MenuItemID::M_MODEL_ME_SANKEY, "桑基图", "actionModelMermaidSanKey", ""),
            MenuItem(MenuItemID::M_MODEL_ME_XY_CHART, "XY图", "actionModelMermaidXYChart", ""),
            MenuItem(MenuItemID::M_MODEL_ME_BLOCK, "框图", "actionModelMermaidBlock", ""),
            MenuItem(MenuItemID::M_MODEL_ME_PACKET, "数据包图", "actionModelMermaidPacket", ""),
            MenuItem(MenuItemID::M_MODEL_ME_KANBAN, "看板图", "actionModelMermaidKanBan", ""),
            MenuItem(MenuItemID::M_MODEL_ME_ARCHITECTURE, "架构图", "actionModelMermaidArchitecture", ""),
            MenuItem(MenuItemID::M_MODEL_ME_RADAR, "雷达图", "actionModelMermaidRadar", ""),
            MenuItem(MenuItemID::M_MODEL_ME_TREEMAP, "树形图", "actionModelMermaidTreeMap", ""),
        }),
        MenuItem(MenuItemID::M_MODEL_PLANTUML, "PlantUml绘图", "ModelSubMenuPlantUml", {
            MenuItem(MenuItemID::M_MODEL_PL_BASE, "基础框架", "actionModelPltUmlBase", ""),
            MenuItem(MenuItemID::M_MODEL_PL_SEQUENCE, "序列图", "actionModelPltUmlSequence", ""),
            MenuItem(MenuItemID::M_MODEL_PL_USE_CASE, "用例图", "actionModelPltUmlUseCase", ""),
            MenuItem(MenuItemID::M_MODEL_PL_CLASS, "类图", "actionModelPltUmlClass", ""),
            MenuItem(MenuItemID::M_MODEL_PL_ACTIVITY, "活动图", "actionModelPltUmlActivity", ""),
            MenuItem(MenuItemID::M_MODEL_PL_COMP, "组件图", "actionModelPltUmlComponent", ""),
            MenuItem(MenuItemID::M_MODEL_PL_STATE, "状态图", "actionModelPltUmlState", ""),
            MenuItem(MenuItemID::M_MODEL_PL_OBJECT, "对象图", "actionModelPltUmlObject", ""),
            MenuItem(MenuItemID::M_MODEL_PL_DEPLOY, "部署图", "actionModelPltUmlDeploy", ""),
            MenuItem(MenuItemID::M_MODEL_PL_TIMING, "定时图", "actionModelPltUmlTiming", ""),
            MenuItem(MenuItemID::M_MODEL_PL_REGEX, "Regex图表", "actionModelPltUmlRegex", ""),
            MenuItem(MenuItemID::M_MODEL_PL_NWDIAG, "使用nwdiag的网络图", "actionModelPltUmlNWDiag", ""),
            MenuItem(MenuItemID::M_MODEL_PL_SALT, "Salt (Wireframe)", "actionModelPltUmlSlat", ""),
            MenuItem(MenuItemID::M_MODEL_PL_ARCHI_MATE, "架构图", "actionModelPltUmlArchiMate", ""),
            MenuItem(MenuItemID::M_MODEL_PL_GANTT, "甘特图", "actionModelPltUmlGantt", ""),
            MenuItem(MenuItemID::M_MODEL_PL_CHRONOLOGY, "时序图", "actionModelPltUmlChronology", ""),
            MenuItem(MenuItemID::M_MODEL_PL_MINDMAP, "思维导图", "actionModelPltUmlMindmap", ""),
            MenuItem(MenuItemID::M_MODEL_PL_WBS, "WBS 图表", "actionModelPltUmlWBS", ""),
            MenuItem(MenuItemID::M_MODEL_PL_EBNF, "EBNF图表", "actionModelPltUmlEBNF", ""),
            MenuItem(MenuItemID::M_MODEL_PL_JSON, "JSON数据", "actionModelPltUmlJson", ""),
            MenuItem(MenuItemID::M_MODEL_PL_YAML, "YAML数据", "actionModelPltUmlYaml", ""),
            MenuItem(MenuItemID::M_MODEL_PL_SDL, "规范和描述语言(SDL)", "actionModelPltUmlSdl", ""),
            MenuItem(MenuItemID::M_MODEL_PL_ASCII_MATH, "AsciiMath", "actionModelPltUmlAsciiMath", ""),
            MenuItem(MenuItemID::M_MODEL_PL_DITAA, "Ditaa图表", "actionModelPltUmlDitaa", ""),
            MenuItem(MenuItemID::M_MODEL_PL_ENTITY, "实体关系图", "actionModelPltUmlEntity", ""),
            MenuItem(MenuItemID::M_MODEL_PL_INFO_ENG, "信息工程图", "actionModelPltUmlInfoEng", ""),
        }),
        MenuItem(MenuItemID::MENU_BUTT, "", "", MenuItem::Separator),
        MenuItem(MenuItemID::M_MODEL_WRITE_MODEL, "写作模板", "ModelSubMenuWriteModel", {
            MenuItem(MenuItemID::M_MODEL_W_LEETCODE, "力扣解题模板", "actionModelWLeetCode", ""),
            MenuItem(MenuItemID::M_MODEL_W_QUESTION, "问题处理模板", "actionModelWQuestion", ""),
            MenuItem(MenuItemID::M_MODEL_W_COVER, "文章封面", "actionModelWCover", ""),
            MenuItem(MenuItemID::M_MODEL_W_PAPER, "论文模板", "actionModelWPaper", ""),
        }),
        MenuItem(MenuItemID::MENU_BUTT, "", "", MenuItem::Separator),
        MenuItem(MenuItemID::M_MODEL_CUSTOM_MODEL, "自定义模板", "actionModelCustomModel", ""),
        MenuItem(MenuItemID::M_MODEL_CUSTOM_MANAGE, "自定义模板管理", "actionModelCustomMange", ""),
    };
}

QList<MenuItem> getSettingMenuItems()
{
    return  {
        MenuItem(MenuItemID::M_SETTING_SYSTEM, "系统设置", "actionSettingSystem", ""),
        MenuItem(MenuItemID::M_SETTING_THEME, "主题设置", "actionSettingTheme", ""),
        MenuItem(MenuItemID::M_SETTING_QUICK, "快速链接设置", "actionSettingQuickLink", ""),
        MenuItem(MenuItemID::M_SETTING_EDITOR, "编辑器设置", "actionSettingEditor", ""),
        MenuItem(MenuItemID::M_SETTING_MD_PARSE, "Markdown解析设置", "actionSettingMdParse", ""),
        MenuItem(MenuItemID::M_SETTING_SHORTCUT, "快捷键设置", "actionSettingShortCut", ""),
    };
}

QList<MenuItem> getToolsMenuItems()
{
    return  {
        MenuItem(MenuItemID::M_TOOL_MERMAID, "Mermaid绘图", "actionToolMermaid", ""),
        MenuItem(MenuItemID::M_TOOL_PLANTUML, "PlantUML绘图", "actionToolPlantUML", ""),
        MenuItem(MenuItemID::M_TOOL_EXECL, "表格制作", "actionToolExecl", ""),
        MenuItem(MenuItemID::M_TOOL_DRAW, "绘图制作", "actionToolDraw", ""),
        MenuItem(MenuItemID::M_TOOL_KATEX, "编辑数学公式", "actionToolKatex", ""),
    };
}

QList<MenuItem> getHelpMenuItems()
{
    return  {
        MenuItem(MenuItemID::M_HELP_RELEASE, "版本发布", "actionHelpRelease", ""),
        MenuItem(MenuItemID::M_HELP_SHORTCUT, "键盘快捷方式", "actionHelpShortKey", ""),
        MenuItem(MenuItemID::MENU_BUTT, "", "", MenuItem::Separator),
        MenuItem(MenuItemID::M_HELP_DOCS, "使用文档", "actionHelpDocs", ""),
        MenuItem(MenuItemID::M_HELP_ISSUE, "提交创意/意见", "actionHelpIssue", ""),
        MenuItem(MenuItemID::MENU_BUTT, "", "", MenuItem::Separator),
        MenuItem(MenuItemID::M_HELP_ABORT, "关于", "actionHelpAbort", ""),
        MenuItem(MenuItemID::M_HELP_HOMEPAGE, "主页", "actionHelpHomePage", ""),
        MenuItem(MenuItemID::M_HELP_THANKS, "致谢", "actionHelpThanks", ""),
        MenuItem(MenuItemID::M_HELP_UPDATE, "检查更新", "actionHelpUpdate", ""),
        MenuItem(MenuItemID::MENU_BUTT, "", "", MenuItem::Separator),
        MenuItem(MenuItemID::M_HELP_CONTACT_US, "联系我们", "actionHelpContactUs", ""),
        MenuItem(MenuItemID::M_HELP_OPEN_SRC, "开源软件", "actionHelpOpenSource", ""),
    };
}

static const std::unordered_map<MenuItemID, MenuItemAttr>& menuBarMap = {
    {MenuItemID::MENU_FILE, {"MenuFile", "文件(&F)", "Alt+F"}},

    // 2. 编辑菜单映射
    {MenuItemID::MENU_EDIT, {"MenuEdit", "编辑(&E)", "Alt+E"}},

    // 3. 视图菜单映射
    {MenuItemID::MENU_VIEW, {"MenuView", "视图(&V)", "Alt+V"}},

    // 4. 编码菜单映射
    {MenuItemID::MENU_CODING, {"MenuCoding", "文件编码(&C)", "Alt+C"}},

    // 5. 插入菜单映射
    {MenuItemID::MENU_INSERT, {"MenuInsert", "插入(&I)", "Alt+I"}},

    // 6. 模板菜单映射
    {MenuItemID::MENU_MODEL, {"MenuModel", "模板(&M)", "Alt+M"}},

    // 7. 设置菜单映射
    {MenuItemID::MENU_SETTING, {"MenuSetting", "设置(&S)", "Alt+S"}},

    // 8. 工具菜单映射
    {MenuItemID::MENU_TOOLS, {"MenuTools", "工具(&T)", "Alt+T"}},

    // 9. 插件菜单映射
    {MenuItemID::MENU_PLUGIN, {"MenuPlugins", "插件(&P)", "Alt+P"}},

    // 10. 插件菜单映射
    {MenuItemID::MENU_CUSTOM_TOOLS, {"MenuCustomTools", "自定义工具(&P)", "Alt+A"}},

    // 11. 在线工具菜单映射
    {MenuItemID::MENU_ONLINE_TOOL, {"MenuOnlineTool", "在线工具(&O)", "Alt+O"}},

    // 12. 链接菜单映射
    {MenuItemID::MENU_LINK, {"MenuLinks", "链接(&L)", "Alt+L"}},

    // 13. 帮助菜单映射
    {MenuItemID::MENU_HELP, {"MenuHelp", "帮助(&H)", "Alt+H"}},
};

// 13. 帮助菜单映射
static const std::unordered_map<MenuItemID, MenuItemAttr>& otherMenuMap = {
    // 帮助菜单
    {MenuItemID::OBJ_NAME_HELP, {"MenuHelp", "帮助(&H)", "Alt+H"}},
    {MenuItemID::MENU_HELP, {"MenuHelp", "帮助(&H)", "Alt+H"}},
};

MenuItemAttr getMenuAttr(MenuItemID type) {
    return menuBarMap.at(type);
}

QList<MenuItem> GetMenuItems(const MenuType type)
{
    switch (type)
    {
        case MenuType::MENU_FILE:
            return getFileMenuItems();
        case MenuType::MENU_EDIT:
            return getEditMenuItems();
        case MenuType::MENU_VIEW:
            return getViewMenuItems();
        case MenuType::MENU_CODING:
            return getCodingMenuItems();
        case MenuType::MENU_INSERT:
            return getInsertMenuItems();
        case MenuType::MENU_MODEL:
            return getModelMenuItems();
        case MenuType::MENU_SETTING:
            return getSettingMenuItems();
        case MenuType::MENU_TOOLS:
            return getToolsMenuItems();
        case MenuType::MENU_HELP:
            return getHelpMenuItems();
        default:
            return {};
    }
}