//
// Created by Administrator on 25-7-5.
//

#ifndef HEMY_MENU_FILE_SUB_EXPORT_H
#define HEMY_MENU_FILE_SUB_EXPORT_H
#include <QMenu>
#include "menu_base.h"
#include "common.h"

namespace HemyMenu {
    class HemyFileSubMenuExport final : public MenuBase {
    public:
        explicit HemyFileSubMenuExport(QWidget *parent = nullptr);
        ~HemyFileSubMenuExport() override = default;

        // 提供访问菜单项的公共接口
        QAction* toWordAction() const { return actionToWord; }
        QAction* toHtmlAction() const { return actionToHtml; }
        QAction* toJsonAction() const { return actionToJson; }
        QAction* toPdfAction() const { return actionToPdf; }
        QAction* toXmlAction() const { return actionToXml; }
        QAction* toYamlAction() const { return actionToYaml; }
    private:
        QAction* actionToWord = nullptr;
        QAction* actionToHtml = nullptr;
        QAction* actionToJson = nullptr;
        QAction* actionToYaml = nullptr;
        QAction* actionToXml = nullptr;
        QAction* actionToPdf = nullptr;

        void CreateFileSubMenuExport();
    };
}



#endif //HEMY_MENU_FILE_SUB_EXPORT_H
