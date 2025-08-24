//
// Created by zhaoj on 25-7-11.
//

#include "sidebar_widget.h"
#include "default.h"
#include "gui_comm_def.h"
#include "hemy_font.h"

namespace HemyUI
{
    HSidebar::HSidebar(QWidget *parent): QFrame(parent)  {
        this->setObjectName("HSidebar");
        Initial();
    }

    void HSidebar::Initial() {
        this->setLayout(new QVBoxLayout());
        m_sidebar_layout = dynamic_cast<QVBoxLayout *>(this->layout());
        m_sidebar_layout->setSpacing(HEMY_GUI::SIDEBAR_SPACING);
        m_sidebar_layout->setContentsMargins(HEMY_GUI::SIDEBAR_MARGINS);
    }

    void HSidebar::addNavigationButton(const QString &text) {
        auto *btn = new QPushButton(text);
        btn->setParent(dynamic_cast<QWidget*>(m_sidebar_layout));
        btn->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        connect(btn, &QPushButton::clicked, [this, text]() {
            emit buttonClicked(text);
        });
    }

    void HSidebar::setWidthRange(const int min, const int max) {
        setMinimumWidth(min);
        setMaximumWidth(max);
    }
}
