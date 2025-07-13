//
// Created by zhaoj on 25-7-11.
//

#include "sidebar_widget.h"
#include "default.h"

namespace HMainLayOut
{
    HemySidebarWidget::HemySidebarWidget(QWidget *parent): QFrame(parent)  {
        setupUI();
        setStyleSheet(
            "SidebarWidget {"
            "   background-color: #2c3e50;"
            "}"
        );
    }

    void HemySidebarWidget::setupUI() {
        m_sidebar_layout = new QVBoxLayout(this);
        m_sidebar_layout->setSpacing(10);
        m_sidebar_layout->setContentsMargins(10, 20, 10, 20);

        QLabel *title = new QLabel("导航菜单");
        title->setStyleSheet(
            "QLabel {"
            "   color: #ecf0f1;"
            "   font-weight: bold;"
            "   font-size: 14pt;"
            "   margin-bottom: 15px;"
            "}"
        );
        m_sidebar_layout->addWidget(title);
    }

    void HemySidebarWidget::addNavigationButton(const QString &text) {
        QPushButton *btn = new QPushButton(text);
        btn->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        btn->setStyleSheet(
            "QPushButton {"
            "   text-align: left;"
            "   padding: 10px 1px;"
            "   color: #ecf0f1;"
            "   border-radius: 4px;"
            "   font-size: 14pt;"
            "}"
            "QPushButton:hover {"
            "   background-color: #34495e;"
            "}"
            "QPushButton:pressed {"
            "   background-color: #1abc9c;"
            "}"
        );

        connect(btn, &QPushButton::clicked, [this, text]() {
            emit buttonClicked(text);
        });

        m_sidebar_layout->addWidget(btn);
    }

    void HemySidebarWidget::setWidthRange(int min, int max) {
        setMinimumWidth(min);
        setMaximumWidth(max);
    }
}