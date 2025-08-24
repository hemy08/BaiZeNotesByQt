//
// Created by Administrator on 25-7-4.
//

#include "status_bar.h"

#include "default.h"
#include "menu_bar.h"
#include "qt_style.h"

namespace HemyUI
{
    HStatusBar::HStatusBar(QWidget *parent)
        : QStatusBar(parent)
    {
        statusBarFont = HCommon::HemyFont::GetInst().GetAppStatusBarFont();
        // 创建一个调色板对象
        QPalette palette;
        // 设置背景颜色（这里使用QColor构造颜色）
        palette.setColor(QPalette::Window, QColor(0X007ACC));
        // 应用调色板到窗口
        this->setPalette(palette);
        //this->setFont(statusBarFont);
        this->setParent(parent);
        this->setBackgroundRole(QPalette::Window);
        CreateStatusBar();
    }

    void HStatusBar::CreateStatusBar()
    {
        setObjectName("HStatusBar");
        showMessage("就绪");

        //setBackgroundRole(palette);
        //setStyleSheet(HEMY::STYLE::DFT::StatusBar);
        // 在此添加状态栏初始化代码
        // 示例：showMessage(tr("Ready"));
        // 添加永久部件到状态栏
        // 创建标签时不立即设置父对象
        /*model_ = new QLabel("Normal Mode", this);
        line_ = new QLabel("Line: 1, Col: 1", this);
        theme_ = new QLabel("Fusion", this);

        // 延迟添加部件
        this->insertPermanentWidget(0, model_);
        this->insertPermanentWidget(1, line_);
        this->insertPermanentWidget(2, theme_);

        model_->setFont(statusBarFont);
        line_->setFont(statusBarFont);
        theme_->setFont(statusBarFont);*/
    }
}
