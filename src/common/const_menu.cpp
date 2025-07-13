//
// Created by Administrator on 25-7-5.
//
#include "const_menu.h"

#include <utility>

static const std::unordered_map<MenuItemID, MenuItem>& fileMenuItemMap = {
    {MenuItemID::OBJ_NAME_FILE,},
}
// 1. 文件菜单映射
static const std::unordered_map<MenuItemID, MenuItem>& fileMenuMap = {
    {MenuItemID::OBJ_NAME_FILE, MenuItem{MenuItemID::OBJ_NAME_FILE, "MenuFile", "文件", "Alt+F"}},
    {MenuItemID::MENU_FILE, {"MenuFile", "文件(&F)", "Alt+F"}},
    {MenuItemID::M_FILE_NEW_File, {"actionNewFile", "新建文件", "Ctrl+N"}},
    {MenuItemID::M_FILE_NEW_DIR, {"actionNewDir", "新建文件夹", "Ctrl+D"}},
    {MenuItemID::M_FILE_OPEN_File, {"actionOpenFile", "打开文件", "Ctrl+Alt+N"}},
    {MenuItemID::M_FILE_OPEN_DIR, {"actionOpenDir", "打开文件夹", "Ctrl+Alt+D"}},
    {MenuItemID::M_FILE_SAVE, {"actionSave", "保存", "Ctrl+S"}},
    {MenuItemID::M_FILE_SAVE_AS, {"actionSaveAs", "另存为", "Ctrl+Shift+S"}},
    {MenuItemID::M_FILE_RELOAD, {"actionReloadFromDisk", "从磁盘重新加载", "Ctrl+Alt+Y"}},
    {MenuItemID::M_FILE_EXIT, {"actionExit", "退出", "Alt+F4"}},
    {MenuItemID::M_FILE_IMPORT, {"FileSubMenuImport", "从文件导入", ""}},
    {MenuItemID::M_FILE_IMPORT_WORD, {"FromWord", "从 Word 导入", ""}},
    {MenuItemID::M_FILE_IMPORT_HTML, {"FromHtml", "从 Html 导入", ""}},
    {MenuItemID::M_FILE_IMPORT_JSON, {"FromJson", "从 Json 导入", ""}},
    {MenuItemID::M_FILE_IMPORT_YAML, {"FromYaml", "从 Yaml 导入", ""}},
    {MenuItemID::M_FILE_IMPORT_XML, {"FromXml", "从 XML 导入", ""}},
    {MenuItemID::M_FILE_IMPORT_TXT, {"FromTxt", "从文本文件导入", ""}},
    {MenuItemID::M_FILE_EXPORT, {"FileSubMenuExport", "导出到文件", ""}},
    {MenuItemID::M_FILE_EXPORT_WORD, {"ToWord", "导出到 Word", ""}},
    {MenuItemID::M_FILE_EXPORT_JSON, {"ToJson", "导出到 Json", ""}},
    {MenuItemID::M_FILE_EXPORT_XML, {"ToXml", "导出到 XML", ""}},
    {MenuItemID::M_FILE_EXPORT_YAML, {"ToYaml", "导出到 Yaml", ""}},
    {MenuItemID::M_FILE_EXPORT_HTML, {"ToHtml", "导出到 Html", ""}},
    {MenuItemID::M_FILE_EXPORT_PDF, {"ToPdf", "导出到 Pdf", ""}}
};

// 2. 编辑菜单映射
static const std::unordered_map<MenuItemID, MenuItemAttr>& editMenuMap = {
    {MenuItemID::OBJ_NAME_EDIT, {"MenuEdit", "编辑(&E)", "Alt+E"}},
    {MenuItemID::MENU_EDIT, {"MenuEdit", "编辑(&E)", "Alt+E"}},
    {MenuItemID::M_EDIT_UNDO, {"actionUndo", "撤销", "Ctrl+Z"}},
    {MenuItemID::M_EDIT_REDO, {"actionRedo", "重做", "Ctrl+Y"}},
    {MenuItemID::M_EDIT_COPY, {"actionCopy", "拷贝", "Ctrl+C"}},
    {MenuItemID::M_EDIT_CUT, {"actionCut", "剪切", "Ctrl+X"}},
    {MenuItemID::M_EDIT_PASTE, {"actionPaste", "粘贴", "Ctrl+V"}},
    {MenuItemID::M_EDIT_FIND_FILE, {"actionFind", "在文件中查找", "Ctrl+F"}},
    {MenuItemID::M_EDIT_REPLACE_FILE, {"actionReplace", "在文件中替换", "Ctrl+R"}},
    {MenuItemID::M_EDIT_FIND_DIR, {"actionFindDir", "在目录中查找", "Ctrl+Shift+F"}},
    {MenuItemID::M_EDIT_REPLACE_DIR, {"actionReplaceDir", "在目录中替换", "Ctrl+Shift+R"}},
    {MenuItemID::M_EDIT_GO_LINE, {"actionGoToLine", "跳转到行", "Alt+G"}},
};

// 3. 视图菜单映射
static const std::unordered_map<MenuItemID, MenuItemAttr>& viewMenuMap = {
    {MenuItemID::OBJ_NAME_VIEW, {"MenuView", "视图(&V)", "Alt+V"}},
    {MenuItemID::MENU_VIEW, {"MenuView", "视图(&V)", "Alt+V"}},
    {MenuItemID::M_VIEW_EDIT_MOD, {"actionEditView", "编辑视图", "F9"}},
    {MenuItemID::M_VIEW_PREVIEW_MOD, {"actionPreview", "预览视图", "F10"}},
    {MenuItemID::M_VIEW_EDIT_PREVIEW, {"actionEditPreview", "编辑/预览视图", "F11"}},
    {MenuItemID::M_VIEW_SHOW_EXPLORER, {"actionDisplayExplorer", "显示/隐藏资源管理器", ""}},
    {MenuItemID::M_VIEW_SHOW_TOC, {"actionDisplayToc", "显示/隐藏大纲", ""}},
    {MenuItemID::M_VIEW_SHOW_LINE_NO, {"actionDisplayLineNo", "显示/隐藏行号", ""}},
    {MenuItemID::M_VIEW_SHOW_LINE_BREAK, {"actionDisplayLineBreak", "显示/隐藏换行", ""}},
    {MenuItemID::M_VIEW_SHOW_SPACE, {"actionDisplaySpace", "显示/隐藏空格", ""}},
    {MenuItemID::M_VIEW_SHOW_ALL, {"actionDisplayAllChart", "显示/隐藏所有符号", ""}},
    {MenuItemID::M_VIEW_EXPAND_ALL, {"actionExpandAll", "展开所有层次", "Alt+0"}},
    {MenuItemID::M_VIEW_FOLD_ALL, {"actionFoldAll", "折叠所有层次", "Alt+Shift+0"}},
    {MenuItemID::M_VIEW_EXPAND_CUR, {"actionExpandCurrent", "展开当前层次", "Ctrl+Alt+F"}},
    {MenuItemID::M_VIEW_FOLD_CUR, {"actionFoldCurrent", "折叠当前层次", "Ctrl+Alt+Shift+F"}},
    {MenuItemID::M_VIEW_FOLD, {"ViewSubMenuFold", "展开层次", ""}},
    {MenuItemID::M_VIEW_FOLD_1, {"actionFold_1", "1", "Alt+1"}},
    {MenuItemID::M_VIEW_FOLD_2, {"actionFold_2", "2", "Alt+2"}},
    {MenuItemID::M_VIEW_FOLD_3, {"actionFold_3", "3", "Alt+3"}},
    {MenuItemID::M_VIEW_FOLD_4, {"actionFold_4", "4", "Alt+4"}},
    {MenuItemID::M_VIEW_FOLD_5, {"actionFold_5", "5", "Alt+5"}},
    {MenuItemID::M_VIEW_FOLD_6, {"actionFold_6", "6", "Alt+6"}},
    {MenuItemID::M_VIEW_EXPAND, {"ViewSubMenuExpand", "折叠层次", ""}},
    {MenuItemID::M_VIEW_EXPAND_1, {"actionExpand_1", "1", "Alt+Shift+1"}},
    {MenuItemID::M_VIEW_EXPAND_2, {"actionExpand_2", "2", "Alt+Shift+2"}},
    {MenuItemID::M_VIEW_EXPAND_3, {"actionExpand_3", "3", "Alt+Shift+3"}},
    {MenuItemID::M_VIEW_EXPAND_4, {"actionExpand_4", "4", "Alt+Shift+4"}},
    {MenuItemID::M_VIEW_EXPAND_5, {"actionExpand_5", "5", "Alt+Shift+5"}},
    {MenuItemID::M_VIEW_EXPAND_6, {"actionExpand_6", "6", "Alt+Shift+6"}},
};

// 4. 编码菜单映射
static const std::unordered_map<MenuItemID, MenuItemAttr>& codingMenuMap = {
    {MenuItemID::OBJ_NAME_CODING, {"MenuCoding", "文件编码(&C)", "Alt+C"}},
    {MenuItemID::MENU_CODING, {"MenuCoding", "文件编码(&C)", "Alt+C"}},
    {MenuItemID::M_CODING_OPEN, {"CodingSubMenuOpen", "使用......编码打开", ""}},
    {MenuItemID::M_CODING_OPEN_ANSI, {"actionCodingOpenAnsi", "ANSI", ""}},
    {MenuItemID::M_CODING_OPEN_UTF8, {"actionCodingOpenUtf8", "UTF-8", ""}},
    {MenuItemID::M_CODING_OPEN_UTF16LE, {"actionCodingOpenUtf16LE", "UTF-16 Little Endian", ""}},
    {MenuItemID::M_CODING_OPEN_UTF16BE, {"actionCodingOpenUtf16BE", "UTF-16 Big Endian", ""}},
    {MenuItemID::M_CODING_OPEN_BG5, {"actionCodingOpenBig5", "Big5(繁体中文)", ""}},
    {MenuItemID::M_CODING_OPEN_BG5_HKSCS, {"actionCodingOpenBig5Hkscs", "Big5-HKSCS(繁体中文)", ""}},
    {MenuItemID::M_CODING_OPEN_GBK, {"actionCodingOpenGbk", "GBK(简体中文)", ""}},
    {MenuItemID::M_CODING_OPEN_GB2312, {"actionCodingOpenGbk2313", "GBK2312(简体中文)", ""}},
    {MenuItemID::M_CODING_OPEN_GB18030, {"actionCodingOpenGbk18030", "GBK18030(简体中文)", ""}},
    {MenuItemID::M_CODING_OPEN_HEX, {"actionCodingOpenHex", "Hex(十六进制)", ""}},
    {MenuItemID::M_CODING_CONVERT, {"CodingSubMenuConvert", "转为......编码", ""}},
    {MenuItemID::M_CODING_CVT_ANSI, {"actionCodingCvtAnsi", "ANSI", ""}},
    {MenuItemID::M_CODING_CVT_UTF8, {"actionCodingCvtUtf8", "UTF-8", ""}},
    {MenuItemID::M_CODING_CVT_UTF16LE, {"actionCodingCvtUtf16LE", "UTF-16 Little Endian", ""}},
    {MenuItemID::M_CODING_CVT_UTF16BE, {"actionCodingCvtUtf16BE", "UTF-16 Big Endian", ""}},
    {MenuItemID::M_CODING_CVT_BG5, {"actionCodingCvtBig5", "Big5(繁体中文)", ""}},
    {MenuItemID::M_CODING_CVT_BG5_HKSCS, {"actionCodingCvtBig5Hkscs", "Big5-HKSCS(繁体中文)", ""}},
    {MenuItemID::M_CODING_CVT_GBK, {"actionCodingCvtGbk", "GBK(简体中文)", ""}},
    {MenuItemID::M_CODING_CVT_GB2312, {"actionCodingCvtGbk2313", "GBK2312(简体中文)", ""}},
    {MenuItemID::M_CODING_CVT_GB18030, {"actionCodingCvtGbk18030", "GBK18030(简体中文)", ""}},
    {MenuItemID::M_CODING_CVT_HEX, {"actionCodingCvtHex", "Hex(十六进制)", ""}},
    {MenuItemID::M_CODING_NOTIFY, {"actionCodingNotify", "注意：请勿直接编辑乱码文件", ""}},
};

// 5. 插入菜单映射
static const std::unordered_map<MenuItemID, MenuItemAttr>& insertMenuMap = {
    {MenuItemID::OBJ_NAME_INSERT, {"MenuInsert", "插入(&I)", "Alt+I"}},
    {MenuItemID::MENU_INSERT, {"MenuInsert", "插入(&I)", "Alt+I"}},
    {MenuItemID::M_INSERT_FONT, {"actionInsFonts", "特殊字体", ""}},
    {MenuItemID::M_INSERT_KATEX, {"actionInsKatex", "Katex公式", ""}},
    {MenuItemID::M_INSERT_MD_TABLE, {"actionInsMdTable", "Markdown表格", ""}},
    {MenuItemID::M_INSERT_WEB_LINK, {"actionInsWebLink", "网页链接", ""}},
    {MenuItemID::M_INSERT_TXT, {"InsSubMenuTxt", "文本", ""}},
    {MenuItemID::M_INSERT_T_IMAGES, {"actionInsImages", "图片链接", ""}},
    {MenuItemID::M_INSERT_T_CODEBLOCK, {"actionInsCodeBlock", "折叠代码块", ""}},
    {MenuItemID::M_INSERT_T_MD_LIST, {"actionInsMdList", "有序列表", ""}},
    {MenuItemID::M_INSERT_T_UPDATE_TIME, {"actionInsUpdateTime", "更新时间", ""}},
    {MenuItemID::M_INSERT_FROM_FILE, {"InsSubMenuFromFile", "来自文件", ""}},
    {MenuItemID::M_INSERT_F_TXT, {"actionInsFromTxt", "*.txt;*.log", ""}},
    {MenuItemID::M_INSERT_F_JSON, {"actionInsFromJson", "*.json", ""}},
    {MenuItemID::M_INSERT_F_INI, {"actionInsFromIni", "*.ini", ""}},
    {MenuItemID::M_INSERT_F_YAML, {"actionInsFromYaml", "*.yaml;*.yml", ""}},
    {MenuItemID::M_INSERT_F_XML, {"actionInsFromXml", "*.xml", ""}},
    {MenuItemID::M_INSERT_F_CSV, {"actionInsFromCsv", "*.csv", ""}},
    {MenuItemID::M_INSERT_F_XLS, {"actionInsFromXls", "*.xls;*.xlsx", ""}},
};

// 6. 模板菜单映射
static const std::unordered_map<MenuItemID, MenuItemAttr>& modelMenuMap = {
    // 设置菜单
    {MenuItemID::OBJ_NAME_MODEL, {"MenuModel", "模板(&M)", "Alt+M"}},
    {MenuItemID::MENU_MODEL, {"MenuModel", "模板(&M)", "Alt+M"}},
    {MenuItemID::M_MODEL_MATERIAL, {"ModelSubMenuMaterial", "Material模块", ""}},
    {MenuItemID::M_MODEL_M_ADMONITION, {"actionModelAdmonition", "Admonition", ""}},
    {MenuItemID::M_MODEL_WRITE_MODEL, {"ModelSubMenuWriteModel", "写作模板", ""}},
    {MenuItemID::M_MODEL_W_LEETCODE, {"actionModelWLeetCode", "力扣解题模板", ""}},
    {MenuItemID::M_MODEL_W_QUESTION, {"actionModelWQuestion", "问题处理模板", ""}},
    {MenuItemID::M_MODEL_W_COVER, {"actionModelWCover", "文章封面", ""}},
    {MenuItemID::M_MODEL_W_PAPER, {"actionModelWPaper", "论文模板", ""}},
    // Mermaid绘图
    {MenuItemID::M_MODEL_MERMAID, {"ModelSubMenuMermaid", "Mermaid绘图", ""}},
    {MenuItemID::M_MODEL_ME_BASE, {"actionModelMermaidBase", "基础框架", ""}},
    {MenuItemID::M_MODEL_ME_FLOWCHAT, {"actionModelMermaidFlowChat", "流程图", ""}},
    {MenuItemID::M_MODEL_ME_SEQUENCE, {"actionModelMermaidSequence", "时序图", ""}},
    {MenuItemID::M_MODEL_ME_CLASS, {"actionModelMermaidClass", "类图", ""}},
    {MenuItemID::M_MODEL_ME_STATE, {"actionModelMermaidState", "状态图", ""}},
    {MenuItemID::M_MODEL_ME_ENTITY, {"actionModelMermaidEntity", "实体关系图", ""}},
    {MenuItemID::M_MODEL_ME_USER_JOURNEY, {"actionModelMermaidUserJourney", "用户旅程图", ""}},
    {MenuItemID::M_MODEL_ME_GANTT, {"actionModelMermaidGantt", "甘特图", ""}},
    {MenuItemID::M_MODEL_ME_PIE, {"actionModelMermaidPie", "饼图", ""}},
    {MenuItemID::M_MODEL_ME_QUADRANT, {"actionModelMermaidQuadrant", "象限图", ""}},
    {MenuItemID::M_MODEL_ME_REQUIREMENT, {"actionModelMermaidRequirement", "需求图", ""}},
    {MenuItemID::M_MODEL_ME_GIT, {"actionModelMermaidGit", "GitGraph(Git)图", ""}},
    {MenuItemID::M_MODEL_ME_C4, {"actionModelMermaidC4", "C4图", ""}},
    {MenuItemID::M_MODEL_ME_MINDMAP, {"actionModelMermaidMindmap", "思维导图", ""}},
    {MenuItemID::M_MODEL_ME_TIMELINE, {"actionModelMermaidTimeLine", "时间线图", ""}},
    {MenuItemID::M_MODEL_ME_ZEN_UML, {"actionModelMermaidZenUml", "ZenUML", ""}},
    {MenuItemID::M_MODEL_ME_SANKEY, {"actionModelMermaidSanKey", "桑基图", ""}},
    {MenuItemID::M_MODEL_ME_XY_CHART, {"actionModelMermaidXYChart", "XY图", ""}},
    {MenuItemID::M_MODEL_ME_BLOCK, {"actionModelMermaidBlock", "框图", ""}},
    {MenuItemID::M_MODEL_ME_PACKET, {"actionModelMermaidPacket", "数据包图", ""}},
    {MenuItemID::M_MODEL_ME_KANBAN, {"actionModelMermaidKanBan", "看板图", ""}},
    {MenuItemID::M_MODEL_ME_ARCHITECTURE, {"actionModelMermaidArchitecture", "架构图", ""}},
    {MenuItemID::M_MODEL_ME_RADAR, {"actionModelMermaidRadar", "雷达图", ""}},
    {MenuItemID::M_MODEL_ME_TREEMAP, {"actionModelMermaidTreeMap", "树形图", ""}},

    // PlantUML绘图
    {MenuItemID::M_MODEL_PLANTUML, {"ModelSubMenuPlantUml", "PlantUml绘图", ""}},
    {MenuItemID::M_MODEL_PL_BASE, {"actionModelPltUmlBase", "基础框架", ""}},
    {MenuItemID::M_MODEL_PL_SEQUENCE, {"actionModelPltUmlSequence", "序列图", ""}},
    {MenuItemID::M_MODEL_PL_USE_CASE, {"actionModelPltUmlUseCase", "用例图", ""}},
    {MenuItemID::M_MODEL_PL_CLASS, {"actionModelPltUmlClass", "类图", ""}},
    {MenuItemID::M_MODEL_PL_ACTIVITY, {"actionModelPltUmlActivity", "活动图", ""}},
    {MenuItemID::M_MODEL_PL_COMP, {"actionModelPltUmlComponent", "组件图", ""}},
    {MenuItemID::M_MODEL_PL_STATE, {"actionModelPltUmlState", "状态图", ""}},
    {MenuItemID::M_MODEL_PL_OBJECT, {"actionModelPltUmlObject", "对象图", ""}},
    {MenuItemID::M_MODEL_PL_DEPLOY, {"actionModelPltUmlDeploy", "部署图", ""}},
    {MenuItemID::M_MODEL_PL_TIMING, {"actionModelPltUmlTiming", "定时图", ""}},
    {MenuItemID::M_MODEL_PL_REGEX, {"actionModelPltUmlRegex", "Regex图表", ""}},
    {MenuItemID::M_MODEL_PL_NWDIAG, {"actionModelPltUmlNWDiag", "使用nwdiag的网络图", ""}},
    {MenuItemID::M_MODEL_PL_SALT, {"actionModelPltUmlSlat", "Salt (Wireframe)", ""}},
    {MenuItemID::M_MODEL_PL_ARCHI_MATE, {"actionModelPltUmlArchiMate", "架构图", ""}},
    {MenuItemID::M_MODEL_PL_GANTT, {"actionModelPltUmlGantt", "甘特图", ""}},
    {MenuItemID::M_MODEL_PL_CHRONOLOGY, {"actionModelPltUmlChronology", "时序图", ""}},
    {MenuItemID::M_MODEL_PL_MINDMAP, {"actionModelPltUmlMindmap", "思维导图", ""}},
    {MenuItemID::M_MODEL_PL_WBS, {"actionModelPltUmlWBS", "WBS 图表", ""}},
    {MenuItemID::M_MODEL_PL_EBNF, {"actionModelPltUmlEBNF", "EBNF图表", ""}},
    {MenuItemID::M_MODEL_PL_JSON, {"actionModelPltUmlJson", "JSON数据", ""}},
    {MenuItemID::M_MODEL_PL_YAML, {"actionModelPltUmlYaml", "YAML数据", ""}},
    {MenuItemID::M_MODEL_PL_SDL, {"actionModelPltUmlSdl", "规范和描述语言(SDL)", ""}},
    {MenuItemID::M_MODEL_PL_ASCII_MATH, {"actionModelPltUmlAsciiMath", "AsciiMath", ""}},
    {MenuItemID::M_MODEL_PL_DITAA, {"actionModelPltUmlDitaa", "Ditaa图表", ""}},
    {MenuItemID::M_MODEL_PL_ENTITY, {"actionModelPltUmlEntity", "实体关系图", ""}},
    {MenuItemID::M_MODEL_PL_INFO_ENG, {"actionModelPltUmlInfoEng", "信息工程图", ""}},
    {MenuItemID::M_MODEL_CUSTOM_MODEL, {"actionModelCustomModel", "自定义模板", ""}},
    {MenuItemID::M_MODEL_CUSTOM_MANAGE, {"actionModelCustomMange", "自定义模板管理", ""}},
};

// 7. 设置菜单映射
static const std::unordered_map<MenuItemID, MenuItemAttr>& settingMenuMap = {
    // 设置菜单
    {MenuItemID::OBJ_NAME_SETTING, {"MenuSetting", "设置(&S)", "Alt+S"}},
    {MenuItemID::MENU_SETTING, {"MenuSetting", "设置(&S)", "Alt+S"}},
    {MenuItemID::M_SETTING_SYSTEM, {"actionSettingSystem", "系统设置", ""}},
    {MenuItemID::M_SETTING_THEME, {"actionSettingTheme", "主题设置", ""}},
    {MenuItemID::M_SETTING_QUICK, {"actionSettingQuickLink", "快速链接设置", ""}},
    {MenuItemID::M_SETTING_EDITOR, {"actionSettingEditor", "编辑器设置", ""}},
    {MenuItemID::M_SETTING_MD_PARSE, {"actionSettingMdParse", "Markdown解析设置", ""}},
    {MenuItemID::M_SETTING_SHORTCUT, {"actionSettingShortCut", "快捷键设置", ""}},
};

// 8. 工具菜单映射
static const std::unordered_map<MenuItemID, MenuItemAttr>& toolsMenuMap = {
    // 工具菜单
    {MenuItemID::OBJ_NAME_TOOLS, {"MenuTools", "工具(&T)", "Alt+T"}},
    {MenuItemID::MENU_TOOLS, {"MenuTools", "工具(&T)", "Alt+T"}},
    {MenuItemID::M_TOOL_MERMAID, {"actionToolMermaid", "Mermaid绘图", ""}},
    {MenuItemID::M_TOOL_PLANTUML, {"actionToolPlantUML", "PlantUML绘图", ""}},
    {MenuItemID::M_TOOL_EXECL, {"actionToolExecl", "表格制作", ""}},
    {MenuItemID::M_TOOL_DRAW, {"actionToolDraw", "绘图制作", ""}},
    {MenuItemID::M_TOOL_KATEX, {"actionToolKatex", "编辑数学公式", ""}},
};

// 9. 插件菜单映射
static const std::unordered_map<MenuItemID, MenuItemAttr>& pluginMenuMap = {
    // 插件菜单
    {MenuItemID::OBJ_NAME_PLUGIN, {"MenuPlugins", "插件(&P)", "Alt+P"}},
    {MenuItemID::MENU_PLUGIN, {"MenuPlugins", "插件(&P)", "Alt+P"}},
};

// 10. 插件菜单映射
static const std::unordered_map<MenuItemID, MenuItemAttr>& customMenuMap = {
    // 插件菜单
    {MenuItemID::OBJ_NAME_CUSTOM, {"MenuCustomTools", "自定义工具(&P)", "Alt+A"}},
    {MenuItemID::MENU_CUSTOM_TOOLS, {"MenuCustomTools", "自定义工具(&P)", "Alt+A"}},
};

// 11. 在线工具菜单映射
static const std::unordered_map<MenuItemID, MenuItemAttr>& onlineToolMenuMap = {
    // 在线工具菜单
    {MenuItemID::OBJ_NAME_ONLINE_TOOL, {"MenuOnlineTool", "在线工具(&O)", "Alt+O"}},
    {MenuItemID::MENU_ONLINE_TOOL, {"MenuOnlineTool", "在线工具(&O)", "Alt+O"}},
};

// 12. 链接菜单映射
static const std::unordered_map<MenuItemID, MenuItemAttr>& linkMenuMap = {
    // 链接菜单
    {MenuItemID::OBJ_NAME_LINK, {"MenuLinks", "链接(&L)", "Alt+L"}},
    {MenuItemID::MENU_LINK, {"MenuLinks", "链接(&L)", "Alt+L"}},
};

// 13. 帮助菜单映射
static const std::unordered_map<MenuItemID, MenuItemAttr>& helpMenuMap = {
    // 帮助菜单
    {MenuItemID::OBJ_NAME_HELP, {"MenuHelp", "帮助(&H)", "Alt+H"}},
    {MenuItemID::MENU_HELP, {"MenuHelp", "帮助(&H)", "Alt+H"}},
    {MenuItemID::M_HELP_RELEASE, {"actionHelpRelease", "版本发布", ""}},
    {MenuItemID::M_HELP_SHORTCUT, {"actionHelpShortKey", "键盘快捷方式", ""}},
    {MenuItemID::M_HELP_DOCS, {"actionHelpDocs", "使用文档", ""}},
    {MenuItemID::M_HELP_ISSUE, {"actionHelpIssue", "提交创意/意见", ""}},
    {MenuItemID::M_HELP_ABORT, {"actionHelpAbort", "关于", ""}},
    {MenuItemID::M_HELP_HOMEPAGE, {"actionHelpHomePage", "主页", ""}},
    {MenuItemID::M_HELP_THANKS, {"actionHelpThanks", "致谢", ""}},
    {MenuItemID::M_HELP_UPDATE, {"actionHelpUpdate", "检查更新", ""}},
    {MenuItemID::M_HELP_CONTACT_US, {"actionHelpContactUs", "联系我们", ""}},
    {MenuItemID::M_HELP_OPEN_SRC, {"actionHelpOpenSource", "开源软件", ""}},
};

// 13. 帮助菜单映射
static const std::unordered_map<MenuItemID, MenuItemAttr>& otherMenuMap = {
    // 帮助菜单
    {MenuItemID::OBJ_NAME_HELP, {"MenuHelp", "帮助(&H)", "Alt+H"}},
    {MenuItemID::MENU_HELP, {"MenuHelp", "帮助(&H)", "Alt+H"}},
};

const std::unordered_map<MenuItemID, MenuItemAttr>& getMenuMap(const MenuItemID type) {
    // Determine which group the type belongs to
    if (type >= MenuItemID::OBJ_NAME_FILE && type < MenuItemID::OBJ_NAME_EDIT) return fileMenuMap;
    if (type >= MenuItemID::OBJ_NAME_EDIT && type < MenuItemID::OBJ_NAME_VIEW) return editMenuMap;
    if (type >= MenuItemID::OBJ_NAME_VIEW && type < MenuItemID::OBJ_NAME_CODING) return viewMenuMap;
    if (type >= MenuItemID::OBJ_NAME_CODING && type < MenuItemID::OBJ_NAME_INSERT) return codingMenuMap;
    if (type >= MenuItemID::OBJ_NAME_INSERT && type < MenuItemID::OBJ_NAME_MODEL) return insertMenuMap;
    if (type >= MenuItemID::OBJ_NAME_MODEL && type < MenuItemID::OBJ_NAME_SETTING) return modelMenuMap;
    if (type >= MenuItemID::OBJ_NAME_SETTING && type < MenuItemID::OBJ_NAME_TOOLS) return settingMenuMap;
    if (type >= MenuItemID::OBJ_NAME_TOOLS && type < MenuItemID::OBJ_NAME_PLUGIN) return toolsMenuMap;
    if (type >= MenuItemID::OBJ_NAME_PLUGIN && type < MenuItemID::OBJ_NAME_CUSTOM) return pluginMenuMap;
    if (type >= MenuItemID::OBJ_NAME_CUSTOM && type < MenuItemID::OBJ_NAME_ONLINE_TOOL) return customMenuMap;
    if (type >= MenuItemID::OBJ_NAME_ONLINE_TOOL && type < MenuItemID::OBJ_NAME_LINK) return onlineToolMenuMap;
    if (type >= MenuItemID::OBJ_NAME_LINK && type < MenuItemID::OBJ_NAME_HELP) return linkMenuMap;
    if (type >= MenuItemID::OBJ_NAME_HELP && type < MenuItemID::MENU_HELP) return helpMenuMap;
    return otherMenuMap;
}

MenuItemAttr getMenuAttr(MenuItemID type) {
    // 统一查找逻辑 (按菜单分组顺序查找)
    auto  maps = getMenuMap(type);

    return maps.at(type);
}

static const std::unordered_map<MenuItemID, MenuItemAttr> menuMaps[] = {
    fileMenuMap,
    editMenuMap,
    viewMenuMap,
    codingMenuMap,
    insertMenuMap,
    modelMenuMap,
    settingMenuMap,
    toolsMenuMap,
    pluginMenuMap,
    customMenuMap,
    onlineToolMenuMap,
    linkMenuMap,
    helpMenuMap
};

MenuItemAttr getMenuItemAttr(const MenuType item, MenuItemID type) {
    // 定义默认返回值（避免重复构造）
    static const MenuItemAttr kDefaultAttr{};

    // 检查是否在有效范围内
    if (item <= MenuType::MENU_BEGIN || item >= MenuType::MENU_END) {
        const auto it = otherMenuMap.find(type);
        return it != otherMenuMap.end() ? it->second : kDefaultAttr;
    }

    // 计算索引（确保无符号运算）
    const size_t index = static_cast<size_t>(item) -
                         static_cast<size_t>(MenuType::MENU_BEGIN) - 1;

    // 获取对应菜单的映射
    const auto& menuMap = menuMaps[index];

    // 查找类型属性
    const auto it = menuMap.find(type);
    return it != menuMap.end() ? it->second : kDefaultAttr;
}

MenuItem createMenuItem(const MenuType item, const MenuItemID type)
{
    const MenuItemAttr attr = getMenuItemAttr(item, type);
    return MenuItem{type, attr.label, attr.obj_name, attr.shortcut};
}

MenuItem createMenuItems(const MenuType item, const MenuItemID type, const QList<MenuItem>& menuItems)
{
    const MenuItemAttr attr = getMenuItemAttr(item, type);
    return MenuItem{type, attr.label, attr.obj_name, menuItems};
}