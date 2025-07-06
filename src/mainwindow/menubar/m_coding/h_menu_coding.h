//
// Created by Administrator on 25-7-5.
//

#ifndef HEMY_MAIN_WIN_MENU_CODE_H
#define HEMY_MAIN_WIN_MENU_CODE_H
#include <QMenu>
#include "menu_base.h"
#include "common.h"
#include "coding_convert.h"
#include "coding_open.h"

namespace HemyMenu {
    class HMenuCoding final : public MenuBase {
    public:
        explicit HMenuCoding(QWidget *parent = nullptr);
        ~HMenuCoding() override = default;
        // 提供访问子菜单的接口
        [[nodiscard]] HemyCodingSubMenuOpen* codeSubMenuOpen() const { return m_open_; }
        [[nodiscard]] HemyCodingSubMenuCvt* codeSubMenuCvt() const { return m_convert_; }
    private:
        HemyCodingSubMenuOpen* m_open_ = nullptr;
        HemyCodingSubMenuCvt* m_convert_ = nullptr;
        QAction* actionCodingNotify = nullptr;
        void CreateMenuCoding();
    };
}



#endif //HEMY_MAIN_WIN_MENU_CODE_H
