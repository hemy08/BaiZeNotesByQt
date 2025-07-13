//
// Created by Administrator on 25-7-4.
//

#include "status_bar.h"

#include "default.h"
#include "menu_bar.h"
#include "qt_style.h"

namespace HemyStatus
{
    HStatusBar::HStatusBar(QWidget *parent)
        : QStatusBar(parent)
    {
        CreateStatusBar();
    }

    void HStatusBar::CreateStatusBar()
    {
        setObjectName("statusbar");
        showMessage("就绪");
        setStyleSheet(HemyStyle::DefaultBlack_StatusBar);
        // 在此添加状态栏初始化代码
        // 示例：showMessage(tr("Ready"));
        // 添加永久部件到状态栏
        model_ = new QLabel("Normal Mode", this);
        addPermanentWidget(model_);

        line_= new QLabel("Line: 1, Col: 1", this);
        addPermanentWidget(line_);

        theme_ = new QLabel(HemyStyle::QT_STYLE_Fusion, this);
        addPermanentWidget(theme_);
    }
}
