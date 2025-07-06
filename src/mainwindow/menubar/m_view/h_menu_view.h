//
// Created by Administrator on 25-7-5.
//

#ifndef HEMY_MAIN_WIN_MENU_VIEW_H
#define HEMY_MAIN_WIN_MENU_VIEW_H
#include <QMenu>
#include "menu_base.h"
#include "common.h"
#include "view_expand.h"
#include "view_fold.h"

namespace HemyMenu
{
    class HMenuView final : public MenuBase {
    public:
        explicit HMenuView(QWidget *parent = nullptr);
        ~HMenuView() override = default;

        // 提供访问子菜单的接口
        [[nodiscard]] HemyViewSubMenuFold* viewSubMenuFold() const { return m_fold_; }
        [[nodiscard]] HemyViewSubMenuExpand* viewSubMenuExpand() const { return m_expand_; }

    private:
        QAction* actionEditModel = nullptr;
        QAction* actionPreviewModel = nullptr;
        QAction* actionEditPreview = nullptr;
        QAction* actionShowExplorer = nullptr;
        QAction* actionShowToc = nullptr;
        QAction* actionShowLineNo = nullptr;
        QAction* actionShowLineBreak = nullptr;
        QAction* actionShowSpace = nullptr;
        QAction* actionShowAll = nullptr;
        QAction* actionFoldAll = nullptr;
        QAction* actionExpandAll = nullptr;
        QAction* actionFoldCur = nullptr;
        QAction* actionExpandCur = nullptr;

        HemyViewSubMenuFold *m_fold_ = nullptr;
        HemyViewSubMenuExpand *m_expand_ = nullptr;

        void CreateMenuView();
    };
}


#endif //HEMY_MAIN_WIN_MENU_VIEW_H
