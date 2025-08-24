//
// Created by Administrator on 25-6-29.
//
#include <QHBoxLayout>
#include "window_central.h"
#include "navigation.h"
#include "explorer_widget.h"
#include "gui_comm_def.h"

namespace HemyUI {
    HMainCentral::HMainCentral(QWidget *parent): QWidget(parent) {
        this->setParent(parent);
        this->setObjectName("HMainCentral");
        Initial();
    }

    void HMainCentral::Initial() {
        // 中间区域水平布局，左侧增加SideBar，中间是Explorer区域，右侧是编辑器工作空间
        this->setLayout(new QHBoxLayout());
        m_central_layout = dynamic_cast<QHBoxLayout *>(this->layout());
        m_central_layout->setParent(this);
        m_central_layout->setSpacing(HEMY_GUI::ZERO_SPACING);
        m_central_layout->setContentsMargins(HEMY_GUI::ZERO_MARGINS);

        // 创建分割布局
        m_central_splitter = new QSplitter(Qt::Horizontal, this);
        setupMainSpliter();
        m_central_layout->addWidget(m_central_splitter);
    }

    void HMainCentral::setupMainSpliter()  {
        m_central_splitter->setObjectName("HMainSpitter");
        m_central_splitter->setHandleWidth(HEMY_GUI::MAIN_SPLITER_WIDTH); // 设置分割条宽度
        m_central_splitter->setChildrenCollapsible(false); // 防止子部件被完全折叠
        setMinWidthSidebar(HEMY_GUI::SIDEBAR_WIDTH_MIN);
        setMaxWidthSidebar(HEMY_GUI::SIDEBAR_WIDTH_MAX);
        setMinWidthExplorer(HEMY_GUI::EXPLORER_WIDTH_MIN);
        setMaxWidthExplorer(HEMY_GUI::EXPLORER_WIDTH_MAX);
        setMinWidthWorkBench(HEMY_GUI::WORKBENCH_WIDTH_MIN);
        setMaxWidthWorkBench(HEMY_GUI::WORKBENCH_WIDTH_MAX);
        // 侧边栏
        m_sidebar = new HSidebar(this);
        m_sidebar->setWidthRange(getMinWidthSidebar(), getMaxWidthSidebar());

        // Explorer区域
        m_explorer = new HExplorer(this);
        m_explorer->setMinimumWidth(getMinWidthExplorer());
        m_explorer->setMaximumWidth(getMaxWidthExplorer());

        // 编辑器区域
        m_workbench = new HWorkBench(this);
        m_workbench->setMinimumWidth(getMinWidthWorkBench());

        // 布局
        m_central_splitter->addWidget(m_sidebar);
        m_central_splitter->addWidget(m_explorer);
        m_central_splitter->addWidget(m_workbench);

        // 设置初始比例
        m_central_splitter->setSizes({getMinWidthSidebar(), getMinWidthExplorer(), getMaxWidthWorkBench()});
    }

    HSidebar *HMainCentral::sidebar() const {
        return m_sidebar;
    }

    HExplorer *HMainCentral::explorer() const {
        return m_explorer;
    }

    HWorkBench *HMainCentral::workbench() const {
        return m_workbench;
    }

    QSplitter *HMainCentral::central_splitter() const {
        return m_central_splitter;
    }

    QHBoxLayout *HMainCentral::central_layout() const {
        return m_central_layout;
    }

    void HMainCentral::SetupNavigation() {
        m_sidebar->addNavigationButton("🔍");
        m_sidebar->addNavigationButton("📖");
        m_sidebar->addNavigationButton("💾");
        m_sidebar->addNavigationButton("☎");

        // 连接按钮点击信号
        connect(m_sidebar, &HSidebar::buttonClicked, this, [this](const QString &buttonText) {
            HemyNav::HNavigation::onHandleTriggeredButton(*m_explorer, buttonText);
        });
    }

    void HMainCentral::AddSampleContent() {
        // 添加示例控件
        auto *sampleFrame = new QFrame();
        //explorer_ = new QVBoxLayout(sampleFrame);
        m_explorer->addExplorer(sampleFrame);
    }
} // HemyUI