//
// Created by Administrator on 25-7-4.
//

#ifndef HQMENUBAR_H
#define HQMENUBAR_H
#include <QMenuBar>

namespace HemyMenu {

class HMenuBar final :public QMenuBar {
    Q_OBJECT
public:
    explicit HMenuBar(QWidget *parent = nullptr);
    ~HMenuBar() override = default;

    // 禁止覆盖样式
    void paintEvent(QPaintEvent *e) override;

    // 菜单项
    QMenu* menuFile_ = nullptr;
    QMenu* menuEdit_ = nullptr;
    QMenu* menuView_ = nullptr;
    QMenu* menuCoding_ = nullptr;
    QMenu* menuInsert_ = nullptr;
    QMenu* menuSettings_ = nullptr;
    QMenu* menuTools_ = nullptr;
    QMenu* menuPlugins_ = nullptr;
    QMenu* menuOnlineTools_ = nullptr;
    QMenu* menuLinks_ = nullptr;
    QMenu* menuHelp_ = nullptr;

private:
    void CreateHemyMenus();
    void setMenuBarSheetStyle();

};

} // HemyMenu

#endif //HQMENUBAR_H
