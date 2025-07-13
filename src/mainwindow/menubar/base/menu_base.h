//
// Created by Administrator on 25-7-5.
//

#ifndef MD_EDITOR_BY_QT_MENU_BASE_H
#define MD_EDITOR_BY_QT_MENU_BASE_H
#include <QMenu>
#include <QFile>
#include <QDomDocument>
#include "common.h"

namespace HemyMenu {
    enum MenuItemType { ITEM_MENU, ITEM_ACTION, ITEM_SEPARATOR };
    struct MenuItem {
        QString objName;
        QString label;
        MenuItemType type;
        QString shortcut;
        QString qmlFile; // QML 文件路径
        QString iconPath; // 图标路径
        QString url; // 图标路径
        bool enabled = true; // 是否启用
        QList<MenuItem> subItems;
    };

    class MenuBase : public QMenu {
    public:
        explicit MenuBase(QWidget *parent = nullptr);
        explicit MenuBase(const QString &title, QWidget *parent = nullptr);
        ~MenuBase() override = default;

        QAction* createAction(const MenuItemAttr& menuItem);
        static void ParserMenuItems(const QString &fileName, QList<MenuItem>& menuItems);
        static void openXmlWithDom(QDomElement &element, const QString &fileName);
        static void parserXmlElement(const QDomElement &root, QList<MenuItem>& menuItems);
        static void buildMenuSystem(QMenu* menu, const QList<MenuItem>& menuItems);
    private:
        static MenuItemType getMenuItemType(const QString &type);

    };
}

#endif //MD_EDITOR_BY_QT_MENU_BASE_H
