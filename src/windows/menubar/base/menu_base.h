//
// Created by Administrator on 25-7-5.
//

#ifndef MD_EDITOR_BY_QT_MENU_BASE_H
#define MD_EDITOR_BY_QT_MENU_BASE_H
#include <QDomDocument>
#include <QString>
#include <functional>
#include <utility>  // 包含 std::move
#include <QUrl>
#include <QMessageBox>
#include "common.h"

namespace HemyUI {
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

        void ParserMenuItems(const QString &fileName, QList<MenuItem>& menuItems);

        QAction* CreateAction(const MenuItemAttr& menuItem);
        static void openWebPage(const QString &url);

        // 回调类型定义
        using actionCallBack = std::function<void(const MenuItemID&, const QString&)>;
        using urlCallBack = std::function<void(const MenuItemID&, const QString&, const QString&)>;
        using qmlCallBack = std::function<void(const MenuItemID&, const QString&, const QString&)>;
        using extendedCallBack = std::function<void(const MenuItemID&, const QString&, const QString&, const QString&)>;
        template <typename Callback>
        void CreateMenu(QMenu* menu, const QList<MenuItem>& menuItems, const Callback& actionCallback) {
            // 设置安全字体
            QFont safeFont = HCommon::HemyFont::GetInst().GetAppDefaultFont();
            menu->setFont(safeFont);
            for (const auto& child : menuItems) {
                if (child.itemType == MenuItem::Separator) {
                    menu->addSeparator();
                } else if (child.itemType == MenuItem::SubMenu) {
                    QMenu* subMenu = menu->addMenu(child.label);
                    subMenu->setObjectName(child.objName);
                    CreateMenu(subMenu, child.subItems, actionCallback);
                } else {
                    QAction* action = menu->addAction(child.label);
                    if (!child.iconPath.isEmpty()) {
                        action->setIcon(QIcon(child.iconPath));
                    }

                    if (!child.shortcut.isEmpty()) {
                        action->setShortcut(QKeySequence(child.shortcut));
                    }
                    action->setObjectName(child.objName);
                    action->setFont(safeFont);
                    connect(action, &QAction::triggered, [=] {
                        // 根据回调函数的参数数量传递不同参数
                        if constexpr (std::is_invocable_v<Callback, MenuItemID, QString>) {
                            actionCallback(child.menuId, child.objName);
                        } else if constexpr (std::is_invocable_v<Callback, MenuItemID, QString, QString>) {
                            actionCallback(child.menuId, child.objName, child.url);
                        } else if constexpr (std::is_invocable_v<Callback, MenuItemID, QString, QString, QString>) {
                            actionCallback(child.menuId, child.objName, child.url, child.qmlFile);
                        } else {
                            static_assert(!sizeof(Callback), "Unsupported callback signature");
                        }
                    });
                }
            }
        }

    private:
        MenuItemType GetMenuItemType(const QString &type);
        void OpenXmlWithDom(QDomElement &element, const QString &fileName);
        void ParserXmlElement(const QDomElement &root, QList<MenuItem>& menuItems);

        void BuildMenuSystem(QMenu* menu, const QList<MenuItem>& menuItems, MenuType itemType, const actionCallBack& actionCallback);
    };
}

#endif //MD_EDITOR_BY_QT_MENU_BASE_H
