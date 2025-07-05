//
// Created by Administrator on 25-7-5.
//

#ifndef MD_EDITOR_BY_QT_COMMON_BASE_H
#define MD_EDITOR_BY_QT_COMMON_BASE_H
#include <QString>
#include <QMenu>
#include <QWidget>

struct MenuItemAttr {
    const QString obj_name;
    const QString label;
    const QString shortcut;
};

struct MenuCreator {
    QMenu** target{};
    std::function<QMenu*(QWidget*)> create{};
    MenuItemAttr attr;
};

#endif //MD_EDITOR_BY_QT_COMMON_BASE_H
