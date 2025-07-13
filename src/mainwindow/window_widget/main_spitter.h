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
    class HemyMainSpitter final : public QSplitter {
        Q_OBJECT
    public:
        explicit HemyMainSpitter(QWidget *parent = nullptr);
        ~HemyMainSpitter() override = default;

        [[nodiscard]] HemySidebarWidget *sidebar() const;
        [[nodiscard]] HemyExplorerWidget *explorer() const;
        [[nodiscard]] HemyContentWidget *content() const;
        void setInitialSizes(const QList<int> &sizes);

    private:
        void setupUI();
        HemySidebarWidget *m_sidebar = nullptr;
        HemyExplorerWidget *m_explorer = nullptr;
        HemyContentWidget *m_content = nullptr;
    };
}

#endif //MAIN_LAYOUT_SPITTER_H
