//
// Created by Administrator on 25-6-29.
//

#ifndef CENTRALWIDGETS_H
#define CENTRALWIDGETS_H
#include <QHBoxLayout>
#include <QMainWindow>
#include <QWidget>
#include "workbench.h"
#include "explorer_widget.h"
#include "sidebar_widget.h"

namespace HemyUI {
    struct LayOutSize {
        int minWidth;
        int maxWidth;
        int minHeight;
        int maxHeight;
    };

    struct MainLayOutPara {
        LayOutSize sideBar;
        LayOutSize explorer;
        LayOutSize content;
    };

class HMainCentral : public QWidget {
public:
    explicit HMainCentral(QWidget *parent = nullptr);
    ~HMainCentral() override = default;

    [[nodiscard]] HSidebar *sidebar() const;
    [[nodiscard]] HExplorer *explorer() const;
    [[nodiscard]] HWorkBench *workbench() const;
    [[nodiscard]] QSplitter *central_splitter() const;
    [[nodiscard]] QHBoxLayout *central_layout() const;
    void setMinWidthSidebar(const int val) {m_layOutPara.sideBar.minWidth = val;};
    void setMaxWidthSidebar(const int val) {m_layOutPara.sideBar.maxWidth = val;};
    void setMinWidthExplorer(const int val) {m_layOutPara.explorer.minWidth = val;};
    void setMaxWidthExplorer(const int val) {m_layOutPara.explorer.maxWidth = val;};
    void setMinWidthWorkBench(const int val) {m_layOutPara.content.minWidth = val;};
    void setMaxWidthWorkBench(const int val) {m_layOutPara.content.maxWidth = val;};
    [[nodiscard]] int getMinWidthSidebar() const { return m_layOutPara.sideBar.minWidth; };
    [[nodiscard]] int getMaxWidthSidebar() const { return m_layOutPara.sideBar.maxWidth; };
    [[nodiscard]] int getMinWidthExplorer() const { return m_layOutPara.explorer.minWidth; };
    [[nodiscard]] int getMaxWidthExplorer() const { return m_layOutPara.explorer.maxWidth; };
    [[nodiscard]] int getMinWidthWorkBench() const { return m_layOutPara.content.minWidth; };
    [[nodiscard]] int getMaxWidthWorkBench() const { return m_layOutPara.content.maxWidth; };

private:
    QHBoxLayout *m_central_layout = nullptr;
    QSplitter *m_central_splitter = nullptr;
    HSidebar *m_sidebar = nullptr;
    HExplorer *m_explorer = nullptr;
    HWorkBench *m_workbench = nullptr;
    MainLayOutPara m_layOutPara{};

    void Initial();
    void setupMainSpliter();
    void SetupNavigation();
    void AddSampleContent();

};

} // HemyUI

#endif //CENTRALWIDGETS_H
