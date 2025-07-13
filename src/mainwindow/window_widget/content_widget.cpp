//
// Created by zhaoj on 25-7-11.
//

#include "content_widget.h"
#include "editor_widget.h"

namespace HMainLayOut
{
    HemyContentWidget::HemyContentWidget(QWidget *parent)
        : QSplitter(Qt::Vertical, parent) {
        setupUI();
    }

    void HemyContentWidget::setupUI() {
        // 设置分割器样式
        setHandleWidth(1);
        setStyleSheet(
            "QSplitter::handle {"
            "   background-color: #95a5a6;"
            "}"
        );

        // 添加快捷菜单
        m_editor_menu = new HemyContentMenuWidget(this);
        m_editor_menu->setFixedHeight(50);
        addWidget(m_editor_menu);

        // 创建编辑/预览分割器
        m_editPreviewSplitter = new QSplitter(Qt::Horizontal);
        m_editPreviewSplitter->setHandleWidth(1);
        m_editPreviewSplitter->setStyleSheet(
            "QSplitter::handle {"
            "   background-color: #95a5a6;"
            "}"
        );
        addWidget(m_editPreviewSplitter);

        // 添加编辑区域
        m_editor = new HemyEditorWidget(this);
        m_editPreviewSplitter->addWidget(m_editor);

        // 添加预览区域
        m_preview = new HemyPreviewWidget(this);
        m_editPreviewSplitter->addWidget(m_preview);
        m_editPreviewSplitter->setSizes({400, 200}); // 编辑:预览 = 2:1

        // 防止折叠
        setChildrenCollapsible(false);
        m_editPreviewSplitter->setChildrenCollapsible(false);

        // 连接信号
        connect(m_editor, &HemyEditorWidget::textChanged, [this]() {
            m_preview->updatePreview(m_editor->editorContent());
        });
    }

    HemyContentMenuWidget *HemyContentWidget::editorMenu() const {
        return m_editor_menu;
    }

    HemyEditorWidget *HemyContentWidget::editor() const {
        return m_editor;
    }

    HemyPreviewWidget *HemyContentWidget::preview() const {
        return m_preview;
    }
}
