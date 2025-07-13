//
// Created by zhaoj on 25-7-10.
//

#ifndef MAIN_LAYOUT_SPITTER_H
#define MAIN_LAYOUT_SPITTER_H
#include "content_widget.h"
#include "explorer_widget.h"
#include "sidebar_widget.h"


namespace HMainLayOut
{
    class HemyMainSpitter : public QSplitter {
        Q_OBJECT
    public:
        explicit HemyMainSpitter(QWidget *parent = nullptr);
        ~HemyMainSpitter() override = default;

        HemySidebarWidget *sidebar() const;
        HemyExplorerWidget *explorer() const;
        HemyContentWidget *content() const;
        void setInitialSizes(const QList<int> &sizes);

    private:
        void setupUI();
        HemySidebarWidget *m_sidebar;
        HemyExplorerWidget *m_explorer;
        HemyContentWidget *m_content;
    };
}

#endif //MAIN_LAYOUT_SPITTER_H
