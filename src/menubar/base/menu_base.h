//
// Created by Administrator on 25-7-5.
//

#ifndef MD_EDITOR_BY_QT_MENU_BASE_H
#define MD_EDITOR_BY_QT_MENU_BASE_H
#include <QMenu>
#include <QFile>
#include <QDomDocument>
#include "common.h"
#include <QString>
#include <QList>
#include <functional>
#include <utility>  // 包含 std::move

namespace HemyMenu {
    enum MenuItemType
    {
        ITEM_MENU,
        ITEM_ACTION,
        ITEM_SEPARATOR,
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
        using MActionCallBack = std::function<void(const MenuItemID&, const QString&)>;
        void createMenu(QMenu* menu,  const QList<MenuItem>& menuItems, const MActionCallBack& actionCallback);
        void buildMenuSystem(QMenu* menu, const QList<MenuItem>& menuItems, MenuType itemType, const MActionCallBack& actionCallback);

    signals:
        void menuActionTriggered(MenuType itemType, const QString& objName);

    private:
        static MenuItemType getMenuItemType(const QString &type);

    };
}

#endif //MD_EDITOR_BY_QT_MENU_BASE_H
