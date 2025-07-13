//
// Created by zhaoj on 25-7-10.
//

#include "main_spitter.h"
#include "content_widget.h"
#include "explorer_widget.h"
#include "sidebar_widget.h"

namespace HMainLayOut
{
    HemyMainSpitter::HemyMainSpitter(QWidget *parent): QSplitter(Qt::Horizontal, parent)  {
        setupUI();
    }

    void HemyMainSpitter::setupUI() {
        // 设置分割器样式
        setHandleWidth(2);
        setStyleSheet(
            "QSplitter::handle {"
            "   background-color: #7f8c8d;"
            "}"
        );

        // 添加侧边栏
        m_sidebar = new HemySidebarWidget;
        m_sidebar->setWidthRange(50, 100);
        addWidget(m_sidebar);

        // 添加Explorer区域
        m_explorer = new HemyExplorerWidget;
        m_explorer->setMinimumWidth(150);
        addWidget(m_explorer);

        // 添加编辑器区域
        m_content = new HemyContentWidget;
        m_content->setMinimumWidth(600);
        addWidget(m_content);

        // 设置初始比例
        setInitialSizes({100, 200, 700});

        // 防止折叠
        setChildrenCollapsible(false);
    }

    HemySidebarWidget *HemyMainSpitter::sidebar() const {
        return m_sidebar;
    }

    HemyExplorerWidget *HemyMainSpitter::explorer() const {
        return m_explorer;
    }

    HemyContentWidget *HemyMainSpitter::content() const {
        return m_content;
    }

    void HemyMainSpitter::setInitialSizes(const QList<int> &sizes) {
        setSizes(sizes);
    }
}
