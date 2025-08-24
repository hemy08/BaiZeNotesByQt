//
// Created by zhaoj on 25-7-11.
//

#include "explorer_widget.h"
#include "gui_comm_def.h"

namespace HemyUI
{
    HExplorer::HExplorer(QWidget *parent) : QWidget(parent) {
        this->setObjectName("HExplorer");
        Initial();
    }

    void HExplorer::Initial() {
        // 垂直布局
        this->setLayout(new QVBoxLayout);
        m_exp_layout = dynamic_cast<QVBoxLayout*>(this->layout());
        m_exp_layout->setContentsMargins(HEMY_GUI::EXPLORER_MARGINS);

        m_exp_label = new QLabel("<h1>内容区域</h1>");
        m_exp_layout->addWidget(m_exp_label);
        m_exp_layout->addStretch();
    }

    void HExplorer::setTitle(const QString &title) const
    {
        m_exp_label->setText(QString("<h1>%1</h1>").arg(title));
    }

    void HExplorer::addExplorer(QWidget *widget) const
    {
        m_exp_layout->insertWidget(m_exp_layout->count() - 1, widget);
    }

    void HExplorer::clearExplorer() const
    {
        QLayoutItem *child;
        while ((child = m_exp_layout->takeAt(1)) != nullptr) { // 保留标题
            if (child->widget()) {
                child->widget()->deleteLater();
            }
            delete child;
        }
    }
}
