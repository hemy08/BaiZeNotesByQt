//
// Created by Administrator on 25-7-5.
//

#ifndef HEMY_MENU_FILE_SUB__EXPORT_H
#define HEMY_MENU_FILE_SUB__EXPORT_H
#include <QMenu>

namespace HemyMenu {
    class HemyFileSubMenuExport final : public QMenu {
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
        QAction* toTxtAction() const { return actionToTxt; }
    private:
        QAction* actionToWord;
        QAction* actionToHtml;
        QAction* actionToJson;
        QAction* actionToYaml;
        QAction* actionToXml;
        QAction* actionToTxt;
        QAction* actionToPdf;

        void CreateFileSubMenuExport();
        void ActionToWord();
        void ActionToHtml();
        void ActionToJson();
        void ActionToYaml();
        void ActionToXml();
        void ActionToTxt();
        void ActionToPdf();
    };
}



#endif //HEMY_MENU_FILE_SUB__EXPORT_H
