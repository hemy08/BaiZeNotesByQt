//
// Created by Administrator on 25-7-5.
//

#ifndef HEMY_MENU_FILE_SUB__IMPORT_FROM_H
#define HEMY_MENU_FILE_SUB__IMPORT_FROM_H
#include <QMenu>

namespace HemyMenu {
    class HemyFileSubMenuImport final : public QMenu {
    public:
        explicit HemyFileSubMenuImport(QWidget *parent = nullptr);
        ~HemyFileSubMenuImport() override = default;

        // 提供访问菜单项的公共接口
        QAction* fromWordAction() const { return actionFromWord; }
        QAction* fromHtmlAction() const { return actionFromHtml; }
        QAction* fromJsonAction() const { return actionFromJson; }
        QAction* fromYamlAction() const { return actionFromYaml; }
        QAction* fromXmlAction() const { return actionFromXml; }
        QAction* fromTxtAction() const { return actionFromTxt; }
    private:
        QAction* actionFromWord{};
        QAction* actionFromHtml{};
        QAction* actionFromJson{};
        QAction* actionFromYaml{};
        QAction* actionFromXml{};
        QAction* actionFromTxt{};

        void CreateFileSubMenuImport();
        void ActionFormWord();
        void ActionFormHtml();
        void ActionFormJson();
        void ActionFormYaml();
        void ActionFormXml();
        void ActionFormTxt();
    };
}

#endif //HEMY_MENU_FILE_SUB__IMPORT_FROM_H
