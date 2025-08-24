//
// Created by Administrator on 25-7-5.
//

#include "menu_insert.h"
#include "special_font_dialog.h"

namespace HemyUI
{
    HMenuInsert::HMenuInsert(QWidget *parent): MenuBase(parent) {
        InitialMenuItems();

    }
    void HMenuInsert::InitialMenuItems()
    {
        auto actionHandler = [this](const MenuItemID& id, const QString& objName) {
            MenuActionHandle(id, objName);
        };

        CreateMenu(this, GetMenuItems(MenuType::MENU_INSERT), actionHandler);
    }

    void HMenuInsert::MenuActionHandle(const MenuItemID& itemId, const QString& objName)
    {
        switch (itemId) {
            case MenuItemID::M_INSERT_FONT:
                {
                    const auto dialog = std::make_unique<SpecialFont>();
                    dialog->exec();
                    break;
                }

            case MenuItemID::M_INSERT_KATEX:
                {
                    KatexDialog();
                    break;
                }
            default:
                LOG_DEBUG("ITEM_ID: ", std::to_string(static_cast<int>(itemId)), ", OBJ: ", objName.toStdString(), " not fond");
        }
    }

    void HMenuInsert::KatexDialog()
    {

    }
}