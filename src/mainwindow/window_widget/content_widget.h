//
// Created by zhaoj on 25-7-11.
//

#ifndef CONTENT_WIDGET_H
#define CONTENT_WIDGET_H
#include <QSplitter>
#include "editor_menu_widget.h"
#include "preview_widget.h"
#include "editor_widget.h"

namespace HMainLayOut
{
    class HemyContentWidget : public QSplitter {
        Q_OBJECT
    public:
        explicit HemyContentWidget(QWidget *parent = nullptr);
        ~HemyContentWidget() override = default;

        HemyContentMenuWidget *editorMenu() const;
        HemyEditorWidget *editor() const;
        HemyPreviewWidget *preview() const;

    private:
        void setupUI();

        HemyContentMenuWidget *m_editor_menu = nullptr;
        QSplitter *m_editPreviewSplitter = nullptr;
        HemyEditorWidget *m_editor = nullptr;
        HemyPreviewWidget *m_preview = nullptr;
    };
}


#endif //CONTENT_WIDGET_H
