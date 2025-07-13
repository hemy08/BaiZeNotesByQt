//
// Created by Administrator on 25-7-5.
//

#ifndef MD_EDITOR_BY_QT_CONST_MENU_H
#define MD_EDITOR_BY_QT_CONST_MENU_H
#include <QString>
#include <utility>
#include "common_base.h"

enum class MenuType
{
    MAIN,
    MENU_BEGIN,
    MENU_FILE,
    MENU_EDIT,
    MENU_VIEW,
    MENU_CODING,
    MENU_INSERT,
    MENU_MODEL,
    MENU_SETTING,
    MENU_TOOLS,
    MENU_PLUGIN,
    MENU_CUSTOM,
    MENU_ONLINE_TOOL,
    MENU_LINK,
    MENU_HELP,
    MENU_END,
    MENU_BUTT
};

enum class MenuItemID {
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
    OBJ_NAME_EDIT,
    MENU_EDIT,
    M_EDIT_UNDO,
    M_EDIT_REDO,
    M_EDIT_COPY,
    M_EDIT_CUT,
    M_EDIT_PASTE,
    M_EDIT_GO_LINE,
    M_EDIT_FIND_FILE,
    M_EDIT_REPLACE_FILE,
    M_EDIT_FIND_DIR,
    M_EDIT_REPLACE_DIR,


    // 视图菜单
    OBJ_NAME_VIEW,
    MENU_VIEW,
    M_VIEW_EDIT_MOD,
    M_VIEW_PREVIEW_MOD,
    M_VIEW_EDIT_PREVIEW,
    M_VIEW_SHOW_EXPLORER,
    M_VIEW_SHOW_TOC,
    M_VIEW_SHOW_LINE_NO,
    M_VIEW_SHOW_SPACE,
    M_VIEW_SHOW_LINE_BREAK,
    M_VIEW_SHOW_ALL,
    M_VIEW_FOLD_ALL,
    M_VIEW_EXPAND_ALL,
    M_VIEW_FOLD_CUR,
    M_VIEW_EXPAND_CUR,
    M_VIEW_FOLD,
    M_VIEW_FOLD_1,
    M_VIEW_FOLD_2,
    M_VIEW_FOLD_3,
    M_VIEW_FOLD_4,
    M_VIEW_FOLD_5,
    M_VIEW_FOLD_6,
    M_VIEW_EXPAND,
    M_VIEW_EXPAND_1,
    M_VIEW_EXPAND_2,
    M_VIEW_EXPAND_3,
    M_VIEW_EXPAND_4,
    M_VIEW_EXPAND_5,
    M_VIEW_EXPAND_6,

    // 文件编码菜单
    OBJ_NAME_CODING,
    MENU_CODING,
    M_CODING_OPEN,
    M_CODING_OPEN_ANSI,
    M_CODING_OPEN_UTF8,
    M_CODING_OPEN_UTF16LE,
    M_CODING_OPEN_UTF16BE,
    M_CODING_OPEN_GBK,
    M_CODING_OPEN_GB2312,
    M_CODING_OPEN_GB18030,
    M_CODING_OPEN_BG5,
    M_CODING_OPEN_BG5_HKSCS,
    M_CODING_OPEN_HEX,
    M_CODING_CONVERT,
    M_CODING_CVT_ANSI,
    M_CODING_CVT_UTF8,
    M_CODING_CVT_UTF16LE,
    M_CODING_CVT_UTF16BE,
    M_CODING_CVT_GBK,
    M_CODING_CVT_GB2312,
    M_CODING_CVT_GB18030,
    M_CODING_CVT_BG5,
    M_CODING_CVT_BG5_HKSCS,
    M_CODING_CVT_HEX,
    M_CODING_NOTIFY,

    // 插入菜单
    OBJ_NAME_INSERT,
    MENU_INSERT,
    M_INSERT_FONT,
    M_INSERT_KATEX,
    M_INSERT_MD_TABLE,
    M_INSERT_WEB_LINK,
    M_INSERT_TXT,
    M_INSERT_T_IMAGES,
    M_INSERT_T_CODEBLOCK,
    M_INSERT_T_MD_LIST,
    M_INSERT_T_UPDATE_TIME,
    M_INSERT_FROM_FILE,
    M_INSERT_F_TXT,
    M_INSERT_F_JSON,
    M_INSERT_F_INI,
    M_INSERT_F_YAML,
    M_INSERT_F_XML,
    M_INSERT_F_CSV,
    M_INSERT_F_XLS,

    // 模板菜单
    OBJ_NAME_MODEL,
    MENU_MODEL,
    M_MODEL_CUSTOM_MODEL,
    M_MODEL_CUSTOM_MANAGE,
    M_MODEL_WRITE_MODEL,
    M_MODEL_W_LEETCODE,
    M_MODEL_W_QUESTION,
    M_MODEL_W_COVER,
    M_MODEL_W_PAPER,
    M_MODEL_MATERIAL,
    M_MODEL_M_ADMONITION,
    M_MODEL_MERMAID,
    M_MODEL_ME_BASE,
    M_MODEL_ME_FLOWCHAT,
    M_MODEL_ME_SEQUENCE,
    M_MODEL_ME_CLASS,
    M_MODEL_ME_STATE,
    M_MODEL_ME_ENTITY,
    M_MODEL_ME_USER_JOURNEY,
    M_MODEL_ME_GANTT,
    M_MODEL_ME_PIE,
    M_MODEL_ME_QUADRANT,
    M_MODEL_ME_REQUIREMENT,
    M_MODEL_ME_GIT,
    M_MODEL_ME_C4,
    M_MODEL_ME_MINDMAP,
    M_MODEL_ME_TIMELINE,
    M_MODEL_ME_ZEN_UML,
    M_MODEL_ME_SANKEY,
    M_MODEL_ME_XY_CHART,
    M_MODEL_ME_BLOCK,
    M_MODEL_ME_PACKET,
    M_MODEL_ME_KANBAN,
    M_MODEL_ME_ARCHITECTURE,
    M_MODEL_ME_RADAR,
    M_MODEL_ME_TREEMAP,
    // PlantUML
    M_MODEL_PLANTUML,
    M_MODEL_PL_BASE,
    M_MODEL_PL_SEQUENCE,
    M_MODEL_PL_USE_CASE,
    M_MODEL_PL_CLASS,
    M_MODEL_PL_ACTIVITY,
    M_MODEL_PL_COMP,
    M_MODEL_PL_STATE,
    M_MODEL_PL_OBJECT,
    M_MODEL_PL_DEPLOY,
    M_MODEL_PL_TIMING,
    M_MODEL_PL_REGEX,
    M_MODEL_PL_NWDIAG,
    M_MODEL_PL_SALT,
    M_MODEL_PL_ARCHI_MATE,
    M_MODEL_PL_GANTT,
    M_MODEL_PL_CHRONOLOGY,
    M_MODEL_PL_MINDMAP,
    M_MODEL_PL_WBS,
    M_MODEL_PL_EBNF,
    M_MODEL_PL_JSON,
    M_MODEL_PL_YAML,
    M_MODEL_PL_SDL,
    M_MODEL_PL_ASCII_MATH,
    M_MODEL_PL_DITAA,
    M_MODEL_PL_ENTITY,
    M_MODEL_PL_INFO_ENG,

    // 设置菜单
    OBJ_NAME_SETTING,
    MENU_SETTING,
    M_SETTING_SYSTEM,
    M_SETTING_THEME,
    M_SETTING_QUICK,
    M_SETTING_EDITOR,
    M_SETTING_MD_PARSE,
    M_SETTING_SHORTCUT,

    // 工具菜单
    OBJ_NAME_TOOLS,
    MENU_TOOLS,
    M_TOOL_KATEX,
    M_TOOL_MERMAID,
    M_TOOL_PLANTUML,
    M_TOOL_DRAW,
    M_TOOL_EXECL,

    // 插件菜单
    OBJ_NAME_PLUGIN,
    MENU_PLUGIN,
    M_PLUGIN_ED_,
    M_PLUGIN_ED_,
    M_PLUGIN_ED_,
    M_PLUGIN_ED_,
    M_PLUGIN_ED_,
    M_PLUGIN_ED_,
    M_PLUGIN_ED_,
    M_PLUGIN_ED_,
    M_PLUGIN_CV_,
    M_PLUGIN_CV_,
    M_PLUGIN_CV_,
    M_PLUGIN_CV_,
    M_PLUGIN_CV_,
    M_PLUGIN_CV_,
    M_PLUGIN_CV_,
    M_PLUGIN_CV_,
    M_PLUGIN_CV_,
    M_PLUGIN_CV_,
    M_PLUGIN_CV_,
    M_PLUGIN_CV_,
    M_PLUGIN_FM_,
    M_PLUGIN_FM_,
    M_PLUGIN_FM_,
    M_PLUGIN_FM_,
    M_PLUGIN_FM_,
    M_PLUGIN_NC_,
    M_PLUGIN_NC_,
    M_PLUGIN_NC_,
    M_PLUGIN_NC_,
    M_PLUGIN_NC_,
    M_PLUGIN_NC_,
    M_PLUGIN_NC_,
    M_PLUGIN_IC_,
    M_PLUGIN_IC_,
    M_PLUGIN_IC_,
    M_PLUGIN_IC_,
    M_PLUGIN_IC_,
    M_PLUGIN_IC_,
    M_PLUGIN_IC_,
    M_PLUGIN_IC_,
    M_PLUGIN_IC_,


    // 插件菜单
    OBJ_NAME_CUSTOM,
    MENU_CUSTOM_TOOLS,

    // 在线工具菜单
    OBJ_NAME_ONLINE_TOOL,
    MENU_ONLINE_TOOL,

    // 链接菜单
    OBJ_NAME_LINK,
    MENU_LINK,

    // 帮助菜单
    OBJ_NAME_HELP,
    MENU_HELP,
    M_HELP_RELEASE,
    M_HELP_SHORTCUT,
    M_HELP_DOCS,
    M_HELP_ISSUE,
    M_HELP_ABORT,
    M_HELP_HOMEPAGE,
    M_HELP_THANKS,
    M_HELP_UPDATE,
    M_HELP_CONTACT_US,
    M_HELP_OPEN_SRC,

    //
    MENU_BUTT
};

struct MenuItem {
    enum ItemType {
        Action,     // 可操作菜单项
        Separator,  // 分隔符
        SubMenu     // 子菜单
    };

    QString label = "";
    QString objName = "";
    QString shortcut = "";
    ItemType itemType = Action;  // 使用枚举类型替代布尔值
    MenuItemID menuId = MenuItemID::MENU_BUTT;
    QString qmlFile = "";        // QML 文件路径
    QString iconPath = "";       // 图标路径
    QString url = "";            // URL
    bool enabled = true;         // 是否启用
    QList<MenuItem> subItems;    // 子菜单项

    // 基础构造函数（必需参数）
    MenuItem(const MenuItemID menuId, QString label, QString  objName)
        : label(std::move(label)), objName(std::move(objName)),menuId(menuId)
    {}

    // 带类型的构造函数
    MenuItem(const MenuItemID menuId, QString label,QString objName, const ItemType type)
        : label(std::move(label)),objName(std::move(objName)),itemType(type),menuId(menuId)
    {}

    // 带快捷键的构造函数
    MenuItem(const MenuItemID menuId, QString label,QString objName, QString shortcut)
        : label(std::move(label)),objName(std::move(objName)),shortcut(std::move(shortcut)),menuId(menuId)
    {}

    // 带子菜单的构造函数
    MenuItem(const MenuItemID menuId, QString label,QString objName, QList<MenuItem> items)
        : label(std::move(label)),objName(std::move(objName)),itemType(SubMenu), menuId(menuId),subItems(std::move(items))
    {}

    // 带URL的构造函数
    MenuItem(const MenuItemID menuId, QString label,QString objName, const ItemType type, QString url_addr)
        : label(std::move(label)), objName(std::move(objName)), itemType(type), menuId(menuId),url(std::move(url_addr))
    {}

    // 完整参数构造函数（所有可选参数）
    MenuItem(const MenuItemID menuId, QString label,QString objName, ItemType type,
             QString shortcut, QString qml, QString icon,
             QString url_addr, const bool enabled,
             const std::function<void()>& callback,
             QList<MenuItem> items)
        : label(std::move(label)),
          objName(std::move(objName)),
          shortcut(std::move(shortcut)),
          itemType(type),
          menuId(menuId),
          qmlFile(std::move(qml)),
          iconPath(std::move(icon)),
          url(std::move(url_addr)),
          enabled(enabled),
          subItems(std::move(items))
    {}

    // 默认构造函数
    MenuItem() = default;

    // 分隔符的便捷构造函数（静态工厂方法）
    static MenuItem createSeparator() {
        return MenuItem(MenuItemID::MENU_BUTT, "", "", Separator);
    }

    // 重载 == 运算符
    bool operator == (const MenuItem& other) const {
        return objName == other.objName &&
               label == other.label &&
               itemType == other.itemType &&
               shortcut == other.shortcut &&
               qmlFile == other.qmlFile &&
               iconPath == other.iconPath &&
               url == other.url &&
               enabled == other.enabled &&
               menuId == other.menuId &&
               subItems == other.subItems;
    }

    // 重载 != 运算符
    bool operator!=(const MenuItem& other) const {
        return !(*this == other);
    }
};

MenuItemAttr getMenuItemAttr(MenuType item, MenuItemID type);
MenuItemAttr getMenuAttr(MenuItemID type);
QString getMenuLabel(MenuItemID type);
QString getMenuShortcut(MenuItemID type);
MenuItem createMenuItem(MenuType item, MenuItemID type);
MenuItem createMenuItems(MenuType item, MenuItemID type, const QList<MenuItem>& menuItems);


#endif //MD_EDITOR_BY_QT_CONST_MENU_H
