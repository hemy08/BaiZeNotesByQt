//
// Created by zhaoj on 25-7-11.
//

#include "workbench.h"
#include "default.h"
#include "gui_comm_def.h"
#include "hemy_debug.h"
#include "hmain_window.h"
#include "workbench_editor.h"
#include "workbench_preview.h"
#include "workbench_menu.h"

namespace HemyUI
{
    HWorkBench::HWorkBench(QWidget *parent)
        : QWidget( parent) {
        this->setWindowTitle("Workbench");
        this->setObjectName("HWorkBench");
        Initial();
    }

    void HWorkBench::Initial()
    {
        // 创建Layout布局，垂直布局，上方是menu、下方是编辑和预览区域
        this->setLayout(new QVBoxLayout());
        m_workbench_layout = dynamic_cast<QVBoxLayout *>(this->layout());
        m_workbench_layout->setParent(this);
        m_workbench_layout->setSpacing(HEMY_GUI::ZERO_SPACING);
        m_workbench_layout->setContentsMargins(HEMY_GUI::ZERO_MARGINS);

        // 创建分割布局，垂直布局，上方是menu、下方是编辑和预览区域
        m_workbench_spliter = new  QSplitter(Qt::Vertical, this);
        setupWorkBenchSplitter();
        m_workbench_layout->addWidget(m_workbench_spliter);

        // 连接信号
        connect(m_editor, &HWorkBenchEditor::textChanged, this, Render);
    }

    void HWorkBench::setupWorkBenchSplitter()
    {
        m_workbench_spliter->setObjectName("HWorkBenchSplitter");
        m_workbench_spliter->setHandleWidth(HEMY_GUI::ZERO_SPLITER_WIDTH);
        m_workbench_spliter->setContentsMargins(HEMY_GUI::ZERO_MARGINS);
        m_workbench_spliter->setChildrenCollapsible(false); // 防止子部件被完全折叠

        // 添加快捷菜单
        m_editor_menu = new HWorkBenchMenu(this);
        createWorkBenchEditorMenu();
        m_workbench_spliter->addWidget(m_editor_menu);
        // 创建编辑/预览分割器
        m_edit_preview_spliter = new QSplitter(Qt::Horizontal);
        createSplitterEditorPreview();
        m_workbench_spliter->addWidget(m_edit_preview_spliter);
    }

    void HWorkBench::createWorkBenchEditorMenu()
    {
        if (m_editor_menu == nullptr) {
            m_editor_menu = new HWorkBenchMenu(this);
        }
        m_editor_menu->setFixedHeight(HEMY_GUI::WORKBENCH_MENU_HEIGHT);
    }

    void HWorkBench::createSplitterEditorPreview()
    {
        if (m_edit_preview_spliter == nullptr) {
            m_edit_preview_spliter = new QSplitter(Qt::Horizontal);
        }

        m_edit_preview_spliter->setHandleWidth(HEMY_GUI::ZERO_SPLITER_WIDTH);
        m_edit_preview_spliter->setContentsMargins(HEMY_GUI::ZERO_MARGINS);
        m_edit_preview_spliter->setObjectName("HEditPreviewSplitter");

        // 添加编辑区域
        m_edit_preview_spliter->addWidget(createEditor(this));

        // 添加预览区域
        m_edit_preview_spliter->addWidget(createPreview(this));

        m_edit_preview_spliter->setSizes({400, 200}); // 编辑:预览 = 2:1
        m_edit_preview_spliter->setChildrenCollapsible(false);
    }

    QWidget *HWorkBench::createEditor(QWidget *parent)
    {
        m_editor = new HWorkBenchEditor(parent);
        return m_editor;
    }

    QWidget *HWorkBench::createPreview(QWidget *parent)
    {
        m_preview = new HWorkBenchPreview(parent);
        return m_preview;
    }

    void HWorkBench::Render()
    {
        auto plain_text = m_editor->toPlainText();
        LOG_INFO("plain_text", plain_text);
        emit SgPlainTextRender(plain_text);
    }
}
