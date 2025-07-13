//
// Created by zhaoj on 25-7-11.
//

#include "explorer_widget.h"


namespace HMainLayOut
{
    HemyExplorerWidget::HemyExplorerWidget(QWidget *parent) : QWidget(parent) {
        setupUI();
        setStyleSheet("background-color: #ecf0f1;");
    }

    void HemyExplorerWidget::setupUI() {
        m_layout = new QVBoxLayout(this);
        m_layout->setContentsMargins(20, 20, 20, 20);

        m_titleLabel = new QLabel("<h1>内容区域</h1>");
        m_layout->addWidget(m_titleLabel);
        m_layout->addStretch();
    }

    void HemyExplorerWidget::setTitle(const QString &title) {
        m_titleLabel->setText(QString("<h1>%1</h1>").arg(title));
    }

    void HemyExplorerWidget::addExplorer(QWidget *widget) {
        m_layout->insertWidget(m_layout->count() - 1, widget);
    }

    void HemyExplorerWidget::clearExplorer() {
        QLayoutItem *child;
        while ((child = m_layout->takeAt(1)) != nullptr) { // 保留标题
            if (child->widget()) {
                child->widget()->deleteLater();
            }
            delete child;
        }
    }
}