//
// Created by zhaoj on 25-7-11.
//

#ifndef CONTENT_WIDGET_H
#define CONTENT_WIDGET_H
#include <QSplitter>
#include "workbench_menu.h"
#include "workbench_preview.h"
#include "workbench_editor.h"

namespace HemyUI
{
    class HWorkBench : public QWidget {
        Q_OBJECT
    public:
        explicit HWorkBench(QWidget *parent = nullptr);
        ~HWorkBench() override = default;
        [[nodiscard]] HWorkBenchEditor *editor() const { return m_editor; }
        [[nodiscard]] HWorkBenchPreview *preview() const { return m_preview; }
        [[nodiscard]] HWorkBenchMenu *editorMenu() const { return m_editor_menu; }

    signals:
        void SgPlainTextRender(QString text);
    private slots:
        void Render();

    private:
        void Initial();
        QVBoxLayout* m_workbench_layout{};
        QSplitter *m_workbench_spliter = nullptr;
        HWorkBenchMenu *m_editor_menu = nullptr;
        QSplitter *m_edit_preview_spliter = nullptr;
        HWorkBenchEditor *m_editor = nullptr;
        HWorkBenchPreview *m_preview = nullptr;
        void setupWorkBenchSplitter();
        void createWorkBenchEditorMenu();
        void createSplitterEditorPreview();
        QWidget *createEditor(QWidget *parent);
        QWidget *createPreview(QWidget *parent);
    };
}


#endif //CONTENT_WIDGET_H
