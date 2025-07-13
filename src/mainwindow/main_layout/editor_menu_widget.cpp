//
// Created by zhaoj on 25-7-11.
//

#include "editor_menu_widget.h"
#include <QToolButton>
#include <QStyle>

namespace HMainLayOut
{
    HemyContentMenuWidget::HemyContentMenuWidget(QWidget *parent) : QWidget(parent) {
        setupUI();
        setStyleSheet(
            "HemyContentMenuWidget {"
            "   background-color: #bdc3c7;"
            "   border-bottom: 1px solid #95a5a6;"
            "}"
        );
    }

    void HemyContentMenuWidget::setupUI() {
        m_layout = new QHBoxLayout(this);
        m_layout->setContentsMargins(5, 2, 5, 2);
        m_layout->setSpacing(5);
    }

    void HemyContentMenuWidget::addToolButton(const QIcon &icon, const QString &tooltip) {
        QToolButton *btn = new QToolButton(this);
        btn->setIcon(icon);
        btn->setToolTip(tooltip);
        btn->setIconSize(QSize(24, 24));
        btn->setStyleSheet(
            "QToolButton {"
            "   background-color: transparent;"
            "   border: 1px solid transparent;"
            "   border-radius: 3px;"
            "   padding: 3px;"
            "}"
            "QToolButton:hover {"
            "   background-color: #95a5a6;"
            "}"
            "QToolButton:pressed {"
            "   background-color: #7f8c8d;"
            "}"
        );
        m_layout->addWidget(btn);
    }
}