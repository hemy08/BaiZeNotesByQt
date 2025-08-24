//
// Created by zhaoj on 25-7-11.
//

#include "workbench_menu.h"
#include <QToolButton>
#include <QStyle>
#include "default.h"
#include "gui_comm_def.h"

namespace HemyUI
{
    HWorkBenchMenu::HWorkBenchMenu(QWidget *parent) : QWidget(parent) {
        this->setObjectName("HWorkBenchMenu");
        setupUI();
    }

    void HWorkBenchMenu::setupUI() {
        m_content_layout = new QHBoxLayout(this);
        m_content_layout->setContentsMargins(HEMY_GUI::WORKBENCH_MARGINS);
        m_content_layout->setSpacing(HEMY_GUI::WORKBENCH_SPACING);
    }

    void HWorkBenchMenu::addToolButton(const QIcon &icon, const QString &tooltip) {
        auto *btn = new QToolButton(this);
        btn->setIcon(icon);
        btn->setToolTip(tooltip);
        btn->setIconSize(QSize(24, 24));
        m_content_layout->addWidget(btn);
    }
}
