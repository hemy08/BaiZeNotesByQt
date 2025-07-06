//
// Created by Administrator on 25-7-5.
//
#include "const_menu.h"

// 1. 文件菜单映射
static const std::unordered_map<MenuItemType, MenuItemAttr>& fileMenuMap = {
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
    {MenuItemType::M_FILE_IMPORT, {"FileSubMenuImport", "从文件导入", ""}},
    {MenuItemType::M_FILE_IMPORT_WORD, {"FromWord", "从 Word 导入", ""}},
    {MenuItemType::M_FILE_IMPORT_HTML, {"FromHtml", "从 Html 导入", ""}},
    {MenuItemType::M_FILE_IMPORT_JSON, {"FromJson", "从 Json 导入", ""}},
    {MenuItemType::M_FILE_IMPORT_YAML, {"FromYaml", "从 Yaml 导入", ""}},
    {MenuItemType::M_FILE_IMPORT_XML, {"FromXml", "从 XML 导入", ""}},
    {MenuItemType::M_FILE_IMPORT_TXT, {"FromTxt", "从文本文件导入", ""}},
    {MenuItemType::M_FILE_EXPORT, {"FileSubMenuExport", "导出到文件", ""}},
    {MenuItemType::M_FILE_EXPORT_WORD, {"ToWord", "导出到 Word", ""}},
    {MenuItemType::M_FILE_EXPORT_JSON, {"ToJson", "导出到 Json", ""}},
    {MenuItemType::M_FILE_EXPORT_XML, {"ToXml", "导出到 XML", ""}},
    {MenuItemType::M_FILE_EXPORT_YAML, {"ToYaml", "导出到 Yaml", ""}},
    {MenuItemType::M_FILE_EXPORT_HTML, {"ToHtml", "导出到 Html", ""}},
    {MenuItemType::M_FILE_EXPORT_PDF, {"ToPdf", "导出到 Pdf", ""}}
};

// 2. 编辑菜单映射
static const std::unordered_map<MenuItemType, MenuItemAttr>& editMenuMap = {
    {MenuItemType::OBJ_NAME_EDIT, {"MenuEdit", "编辑(&E)", "Alt+E"}},
    {MenuItemType::MENU_EDIT, {"MenuEdit", "编辑(&E)", "Alt+E"}},
    {MenuItemType::M_EDIT_UNDO, {"ActionUndo", "撤销", "Ctrl+Z"}},
    {MenuItemType::M_EDIT_REDO, {"ActionRedo", "重做", "Ctrl+Y"}},
    {MenuItemType::M_EDIT_COPY, {"ActionCopy", "拷贝", "Ctrl+C"}},
    {MenuItemType::M_EDIT_CUT, {"ActionCut", "剪切", "Ctrl+X"}},
    {MenuItemType::M_EDIT_PASTE, {"ActionPaste", "粘贴", "Ctrl+V"}},
    {MenuItemType::M_EDIT_FIND_FILE, {"ActionFind", "在文件中查找", "Ctrl+F"}},
    {MenuItemType::M_EDIT_REPLACE_FILE, {"ActionReplace", "在文件中替换", "Ctrl+R"}},
    {MenuItemType::M_EDIT_FIND_DIR, {"ActionFindDir", "在目录中查找", "Ctrl+Shift+F"}},
    {MenuItemType::M_EDIT_REPLACE_DIR, {"ActionReplaceDir", "在目录中替换", "Ctrl+Shift+R"}},
    {MenuItemType::M_EDIT_GO_LINE, {"ActionGoToLine", "跳转到行", "Alt+G"}},
};

// 3. 视图菜单映射
static const std::unordered_map<MenuItemType, MenuItemAttr>& viewMenuMap = {
    {MenuItemType::OBJ_NAME_VIEW, {"MenuView", "视图(&V)", "Alt+V"}},
    {MenuItemType::MENU_VIEW, {"MenuView", "视图(&V)", "Alt+V"}},
    {MenuItemType::M_VIEW_EDIT_MOD, {"Action", "编辑视图", "F9"}},
    {MenuItemType::M_VIEW_PREVIEW_MOD, {"Action", "预览视图", "F10"}},
    {MenuItemType::M_VIEW_EDIT_PREVIEW, {"Action", "编辑/预览视图", "F11"}},
    {MenuItemType::M_VIEW_SHOW_EXPLORER, {"Action", "显示/隐藏资源管理器", ""}},
    {MenuItemType::M_VIEW_SHOW_TOC, {"Action", "显示/隐藏大纲", ""}},
    {MenuItemType::M_VIEW_SHOW_LINE_NO, {"Action", "显示/隐藏行号", ""}},
    {MenuItemType::M_VIEW_SHOW_LINE_BREAK, {"Action", "显示/隐藏换行", ""}},
    {MenuItemType::M_VIEW_SHOW_SPACE, {"Action", "显示/隐藏空格", ""}},
    {MenuItemType::M_VIEW_SHOW_ALL, {"Action", "显示/隐藏所有符号", ""}},
    {MenuItemType::M_VIEW_FOLD_ALL, {"Action", "展开所有层次", "Alt+0"}},
    {MenuItemType::M_VIEW_EXPAND_ALL, {"Action", "折叠所有层次", "Alt+Shift+0"}},
    {MenuItemType::M_VIEW_FOLD_CUR, {"Action", "展开当前层次", "Ctrl+Alt+F"}},
    {MenuItemType::M_VIEW_EXPAND_CUR, {"Action", "折叠当前层次", "Ctrl+Alt+Shift+F"}},
    {MenuItemType::M_VIEW_FOLD, {"ViewSubMenuFold", "展开层次", ""}},
    {MenuItemType::M_VIEW_FOLD_1, {"Action", "1", "Alt+1"}},
    {MenuItemType::M_VIEW_FOLD_2, {"Action", "2", "Alt+2"}},
    {MenuItemType::M_VIEW_FOLD_3, {"Action", "3", "Alt+3"}},
    {MenuItemType::M_VIEW_FOLD_4, {"Action", "4", "Alt+4"}},
    {MenuItemType::M_VIEW_FOLD_5, {"Action", "5", "Alt+5"}},
    {MenuItemType::M_VIEW_FOLD_6, {"Action", "6", "Alt+6"}},
    {MenuItemType::M_VIEW_EXPAND, {"ViewSubMenuExpand", "折叠层次", ""}},
    {MenuItemType::M_VIEW_EXPAND_1, {"Action", "1", "Alt+Shift+1"}},
    {MenuItemType::M_VIEW_EXPAND_2, {"Action", "2", "Alt+Shift+2"}},
    {MenuItemType::M_VIEW_EXPAND_3, {"Action", "3", "Alt+Shift+3"}},
    {MenuItemType::M_VIEW_EXPAND_4, {"Action", "4", "Alt+Shift+4"}},
    {MenuItemType::M_VIEW_EXPAND_5, {"Action", "5", "Alt+Shift+5"}},
    {MenuItemType::M_VIEW_EXPAND_6, {"Action", "6", "Alt+Shift+6"}},
};

// 4. 编码菜单映射
static const std::unordered_map<MenuItemType, MenuItemAttr>& codingMenuMap = {
    {MenuItemType::OBJ_NAME_CODING, {"MenuCoding", "文件编码(&C)", "Alt+C"}},
    {MenuItemType::MENU_CODING, {"MenuCoding", "文件编码(&C)", "Alt+C"}},
    {MenuItemType::M_CODING_OPEN, {"CodingSubMenuOpen", "使用......编码打开", ""}},
    {MenuItemType::M_CODING_OPEN_ANSI, {"ActionCodingOpenAnsi", "ANSI", ""}},
    {MenuItemType::M_CODING_OPEN_UTF8, {"ActionCodingOpenUtf8", "UTF-8", ""}},
    {MenuItemType::M_CODING_OPEN_UTF16LE, {"ActionCodingOpenUtf16LE", "UTF-16 Little Endian", ""}},
    {MenuItemType::M_CODING_OPEN_UTF16BE, {"ActionCodingOpenUtf16BE", "UTF-16 Big Endian", ""}},
    {MenuItemType::M_CODING_OPEN_BG5, {"ActionCodingOpenBig5", "Big5(繁体中文)", ""}},
    {MenuItemType::M_CODING_OPEN_BG5_HKSCS, {"ActionCodingOpenBig5Hkscs", "Big5-HKSCS(繁体中文)", ""}},
    {MenuItemType::M_CODING_OPEN_GBK, {"ActionCodingOpenGbk", "GBK(简体中文)", ""}},
    {MenuItemType::M_CODING_OPEN_GB2312, {"ActionCodingOpenGbk2313", "GBK2312(简体中文)", ""}},
    {MenuItemType::M_CODING_OPEN_GB18030, {"ActionCodingOpenGbk18030", "GBK18030(简体中文)", ""}},
    {MenuItemType::M_CODING_OPEN_HEX, {"ActionCodingOpenHex", "Hex(十六进制)", ""}},
    {MenuItemType::M_CODING_CONVERT, {"CodingSubMenuConvert", "转为......编码", ""}},
    {MenuItemType::M_CODING_CVT_ANSI, {"ActionCodingCvtAnsi", "ANSI", ""}},
    {MenuItemType::M_CODING_CVT_UTF8, {"ActionCodingCvtUtf8", "UTF-8", ""}},
    {MenuItemType::M_CODING_CVT_UTF16LE, {"ActionCodingCvtUtf16LE", "UTF-16 Little Endian", ""}},
    {MenuItemType::M_CODING_CVT_UTF16BE, {"ActionCodingCvtUtf16BE", "UTF-16 Big Endian", ""}},
    {MenuItemType::M_CODING_CVT_BG5, {"ActionCodingCvtBig5", "Big5(繁体中文)", ""}},
    {MenuItemType::M_CODING_CVT_BG5_HKSCS, {"ActionCodingCvtBig5Hkscs", "Big5-HKSCS(繁体中文)", ""}},
    {MenuItemType::M_CODING_CVT_GBK, {"ActionCodingCvtGbk", "GBK(简体中文)", ""}},
    {MenuItemType::M_CODING_CVT_GB2312, {"ActionCodingCvtGbk2313", "GBK2312(简体中文)", ""}},
    {MenuItemType::M_CODING_CVT_GB18030, {"ActionCodingCvtGbk18030", "GBK18030(简体中文)", ""}},
    {MenuItemType::M_CODING_CVT_HEX, {"ActionCodingCvtHex", "Hex(十六进制)", ""}},
    {MenuItemType::M_CODING_NOTIFY, {"ActionCodingNotify", "注意：请勿直接编辑乱码文件", ""}},
};

// 5. 插入菜单映射
static const std::unordered_map<MenuItemType, MenuItemAttr>& insertMenuMap = {
    {MenuItemType::OBJ_NAME_INSERT, {"MenuInsert", "插入(&I)", "Alt+I"}},
    {MenuItemType::MENU_INSERT, {"MenuInsert", "插入(&I)", "Alt+I"}},
};

// 6. 设置菜单映射
static const std::unordered_map<MenuItemType, MenuItemAttr>& settingMenuMap = {
    // 设置菜单
    {MenuItemType::OBJ_NAME_SETTING, {"MenuSetting", "设置(&S)", "Alt+S"}},
    {MenuItemType::MENU_SETTING, {"MenuSetting", "设置(&S)", "Alt+S"}},
};

// 7. 工具菜单映射
static const std::unordered_map<MenuItemType, MenuItemAttr>& toolsMenuMap = {
    // 工具菜单
    {MenuItemType::OBJ_NAME_TOOLS, {"MenuTools", "工具(&T)", "Alt+T"}},
    {MenuItemType::MENU_TOOLS, {"MenuTools", "工具(&T)", "Alt+T"}},
};

// 8. 插件菜单映射
static const std::unordered_map<MenuItemType, MenuItemAttr>& pluginMenuMap = {
    // 插件菜单
    {MenuItemType::OBJ_NAME_PLUGIN, {"MenuPlugins", "插件(&P)", "Alt+P"}},
    {MenuItemType::MENU_PLUGIN, {"MenuPlugins", "插件(&P)", "Alt+P"}},
};

// 9. 在线工具菜单映射
static const std::unordered_map<MenuItemType, MenuItemAttr>& onlineToolMenuMap = {
    // 在线工具菜单
    {MenuItemType::OBJ_NAME_ONLINE_TOOL, {"MenuOnlineTool", "在线工具(&O)", "Alt+O"}},
    {MenuItemType::MENU_ONLINE_TOOL, {"MenuOnlineTool", "在线工具(&O)", "Alt+O"}},
};

// 10. 链接菜单映射
static const std::unordered_map<MenuItemType, MenuItemAttr>& linkMenuMap = {
    // 链接菜单
    {MenuItemType::OBJ_NAME_LINK, {"MenuLinks", "链接(&L)", "Alt+L"}},
    {MenuItemType::MENU_LINK, {"MenuLinks", "链接(&L)", "Alt+L"}},
};

// 11. 帮助菜单映射
static const std::unordered_map<MenuItemType, MenuItemAttr>& helpMenuMap = {
    // 帮助菜单
    {MenuItemType::OBJ_NAME_HELP, {"MenuHelp", "帮助(&H)", "Alt+H"}},
    {MenuItemType::MENU_HELP, {"MenuHelp", "帮助(&H)", "Alt+H"}},
};

// 11. 帮助菜单映射
static const std::unordered_map<MenuItemType, MenuItemAttr>& otherMenuMap = {
    // 帮助菜单
    {MenuItemType::OBJ_NAME_HELP, {"MenuHelp", "帮助(&H)", "Alt+H"}},
    {MenuItemType::MENU_HELP, {"MenuHelp", "帮助(&H)", "Alt+H"}},
};

const std::unordered_map<MenuItemType, MenuItemAttr>& getMenuMap(const MenuItemType type) {
    // Determine which group the type belongs to
    if (type >= MenuItemType::OBJ_NAME_FILE && type < MenuItemType::OBJ_NAME_EDIT) return fileMenuMap;
    if (type >= MenuItemType::OBJ_NAME_EDIT && type < MenuItemType::OBJ_NAME_VIEW) return editMenuMap;
    if (type >= MenuItemType::OBJ_NAME_VIEW && type < MenuItemType::OBJ_NAME_CODING) return viewMenuMap;
    if (type >= MenuItemType::OBJ_NAME_CODING && type < MenuItemType::OBJ_NAME_INSERT) return codingMenuMap;
    if (type >= MenuItemType::OBJ_NAME_INSERT && type < MenuItemType::OBJ_NAME_SETTING) return insertMenuMap;
    if (type >= MenuItemType::OBJ_NAME_SETTING && type < MenuItemType::OBJ_NAME_TOOLS) return settingMenuMap;
    if (type >= MenuItemType::OBJ_NAME_TOOLS && type < MenuItemType::OBJ_NAME_PLUGIN) return toolsMenuMap;
    if (type >= MenuItemType::OBJ_NAME_PLUGIN && type < MenuItemType::OBJ_NAME_ONLINE_TOOL) return pluginMenuMap;
    if (type >= MenuItemType::OBJ_NAME_ONLINE_TOOL && type < MenuItemType::OBJ_NAME_LINK) return onlineToolMenuMap;
    if (type >= MenuItemType::OBJ_NAME_LINK && type < MenuItemType::OBJ_NAME_HELP) return linkMenuMap;
    if (type >= MenuItemType::OBJ_NAME_HELP && type < MenuItemType::MENU_HELP) return helpMenuMap;
    return otherMenuMap;
}

MenuItemAttr getMenuAttr(MenuItemType type) {
    // 统一查找逻辑 (按菜单分组顺序查找)
    auto  maps = getMenuMap(type);

    return maps.at(type);
}

static const std::unordered_map<MenuItemType, MenuItemAttr> menuMaps[] = {
    fileMenuMap,
    editMenuMap,
    viewMenuMap,
    codingMenuMap,
    insertMenuMap,
    settingMenuMap,
    toolsMenuMap,
    pluginMenuMap,
    onlineToolMenuMap,
    linkMenuMap,
    helpMenuMap
};

MenuItemAttr getMenuItemAttr(const MenuItem item, MenuItemType type) {
    // 定义默认返回值（避免重复构造）
    static const MenuItemAttr kDefaultAttr{};

    // 检查是否在有效范围内
    if (item <= MenuItem::MENU_BEGIN || item >= MenuItem::MENU_END) {
        const auto it = otherMenuMap.find(type);
        return it != otherMenuMap.end() ? it->second : kDefaultAttr;
    }

    // 计算索引（确保无符号运算）
    const size_t index = static_cast<size_t>(item) -
                         static_cast<size_t>(MenuItem::MENU_BEGIN) - 1;

    // 获取对应菜单的映射
    const auto& menuMap = menuMaps[index];

    // 查找类型属性
    const auto it = menuMap.find(type);
    return it != menuMap.end() ? it->second : kDefaultAttr;
}
