//
// Created by Administrator on 25-7-5.
//

#include "menu_base.h"
#include <QMessageBox>
#include <QFile>
#include <QDebug>
#include <QDesktopServices>
#include <QUrl>
#include <QMessageBox>
#include <QProcess>
#include <QRegularExpression>

namespace HemyMenu {
    MenuBase::MenuBase(QWidget *parent): QMenu(parent) {

    }

    MenuBase::MenuBase(const QString &title, QWidget *parent): QMenu(title, parent) {
        setTitle(title);
    }

    QAction* MenuBase::createAction(const MenuItemAttr& menuItem) {
        QAction* action = addAction(menuItem.label);
        action->setObjectName(menuItem.obj_name);
        if (!(menuItem.shortcut.isEmpty() || menuItem.shortcut.length() == 0)) {
            action->setShortcut(menuItem.shortcut);
        }
        return action;
    }

    void MenuBase::ParserMenuItems(const QString &fileName, QList<MenuItem>& menuItems)
    {
        QDomElement xmlDom;
        openXmlWithDom(xmlDom, fileName);
        parserXmlElement(xmlDom, menuItems);
    }

    void MenuBase::openXmlWithDom(QDomElement &element, const QString &fileName)
    {
        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly)) {
            QMessageBox::critical(nullptr,
            tr("文件错误"),
            tr("读取 %1 文件失败，请确认文件是否存在").arg(fileName));
            return;
        }
        QDomDocument doc;
        if (const auto result = doc.setContent(&file, QDomDocument::ParseOption::Default);!result) {
            QMessageBox::critical(nullptr,
            tr("XML 解析错误"),
            tr("行: %1, 列: %2\n错误: %3").arg(result.errorLine).arg(result.errorColumn).arg(result.errorMessage));
            file.close();
            return;
        }

        file.close();

        // 获取根元素
        element = doc.documentElement();
        if (element.tagName() != "Menu") {
            QMessageBox::warning(nullptr,
                tr("XML 结构错误"),
                tr("根元素不是 'library'"));
            return;
        }
    }

    MenuItemType MenuBase::getMenuItemType(const QString &type)
    {
        if (type.toLower() == "menu") {
            return ITEM_MENU;
        } else if (type.toLower() == "action") {
            return ITEM_ACTION;
        } else if (type.toLower() == "separator") {
            return ITEM_SEPARATOR;
        }

        return ITEM_MENU;
    }

    void MenuBase::parserXmlElement(const QDomElement &root, QList<MenuItem>& menuItems) {
        const QDomNodeList menuNodes = root.childNodes();
        for (int i = 0; i < menuNodes.count(); i++) {
            // 只处理元素节点且标签名为 menuItem
            if (QDomNode childNode = menuNodes.item(i); childNode.isElement() && childNode.nodeName() == "menuItem") {
                QDomElement menuElement = childNode.toElement();
                MenuItem menuItem;
                MenuItemType itemType = getMenuItemType(menuElement.attribute("type"));
                // 解析主菜单项
                menuItem.objName = menuElement.firstChildElement("ObjName").text();
                menuItem.label = menuElement.firstChildElement("Label").text();
                menuItem.shortcut = menuElement.firstChildElement("ShortCut").text();
                menuItem.qmlFile = menuElement.firstChildElement("QmlFile").text();
                menuItem.iconPath = menuElement.firstChildElement("Icon").text();
                menuItem.url = menuElement.firstChildElement("Url").text();

                if (itemType == ITEM_MENU) {
                    menuItem.itemType = MenuItem::SubMenu;
                    parserXmlElement(menuElement, menuItem.subItems);
                } else if (itemType == ITEM_ACTION) {
                    menuItem.itemType = MenuItem::Action;
                } else {
                    menuItem.itemType = MenuItem::Separator;
                }

                menuItems.append(menuItem);
            }
        }
    }

    void MenuBase::buildMenuSystem(QMenu* menu, const QList<MenuItem>& menuItems, const MenuType itemType, const actionCallBack& actionCallback)
    {
        for (const MenuItem& item : menuItems) {
            switch (item.itemType) {
            case MenuItem::Separator: {
                    menu->addSeparator();
                    break;
                }
            case MenuItem::Action:
                {
                    QAction* action = menu->addAction(item.label);
                    action->setObjectName(item.objName);
                    if (!(item.iconPath.isEmpty() || item.iconPath.length() == 0)) {
                        action->setIcon(QIcon(item.iconPath));
                    }

                    if (!(item.shortcut.isEmpty() || item.shortcut.length() == 0)) {
                        action->setShortcut(QKeySequence(item.shortcut));
                    }

                    // 连接信号槽
                    connect(action, &QAction::triggered, this, [=]() {
                        //emit menuActionTriggered(itemType, item.objName);
                        if (actionCallback) {
                            actionCallback(item.menuId, item.objName);
                        }
                    });
                    break;
                }
            case MenuItem::SubMenu: {
                    QMenu* subMenu = menu->addMenu(item.label);
                    subMenu->setObjectName(item.objName);
                    buildMenuSystem(subMenu, item.subItems, itemType, actionCallback);
                    break;
                }
            default: {
                    qWarning() << "未知的菜单项类型:" << item.itemType;
                    break;
                }
            }
        }
    }

    void MenuBase::openWebPage(const QString &url) {
        // 验证URL格式
        QRegularExpression urlRegex(
            R"(^(https?|ftp)://[^\s/$.?#].[^\s]*$)",
            QRegularExpression::CaseInsensitiveOption
        );

        if (!urlRegex.match(url).hasMatch()) {
            QMessageBox::warning(nullptr, "Invalid URL",
                                 "The provided URL is invalid:\n" + url);
            return;
        }

        QUrl qurl(url);
        if (qurl.scheme().isEmpty()) {
            // 添加默认的http协议
            qurl = QUrl("http://" + url);
        }

        if (!qurl.isValid()) {
            QMessageBox::warning(nullptr, "Invalid URL",
                                 "The provided URL is invalid:\n" + url);
            return;
        }

        // 尝试打开URL
        if (!QDesktopServices::openUrl(qurl)) {
            // 尝试使用系统命令作为后备
#if defined(Q_OS_WIN)
            QProcess::startDetached("cmd", {"/c", "start", "", url});
#elif defined(Q_OS_MAC)
            QProcess::startDetached("open", {url});
#elif defined(Q_OS_LINUX)
            QProcess::startDetached("xdg-open", {url});
#endif

            QMessageBox::warning(nullptr, "Open Failed",
                                 "Could not open the URL:\n" + url);
        }
    }
}