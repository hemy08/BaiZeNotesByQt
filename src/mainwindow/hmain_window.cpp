//
// Created by Administrator on 25-6-29.
//
#include <QStyleFactory>
#include <QMenu>
#include <QAction>
#include <QMenuBar>
#include <QActionGroup>
#include <QStyle>
#include "hmain_window.h"
#include "central_widgets.h"
#include "h_menu_bar.h"
#include "const_def.h"
#include "hemy_style.h"


namespace HemyUi
{
    HMainWindow::HMainWindow(QWidget *parent) :
        QMainWindow(parent) {
        CreateMainWindow();
        setupUi();
        applyStyles();
    }

    void HMainWindow::CreateMainWindow()
    {
        if (objectName().isEmpty()) {
            setObjectName(ConstMainWin::OBJ_NAME);
        }

        // 设置初始语言为系统语言
        if (QLocale::system().language() == QLocale::Chinese) {
            switchToChinese();
        } else {
            switchToEnglish();
        }
        setWindowTitle(ConstMainWin::TITLE);
        resize(ConstMainWin::MAIN_DEFAULT_WIDTH, ConstMainWin::MAIN_DEFAULT_HEIGHT);
    }

    void HMainWindow::setupUi()
    {

        central_ = CentralWidgets::CreateCentralWidgets(this);
        setCentralWidget(central_);
        menuBar_ = new HemyMenu::HMenuBar(this);
        setMenuBar(menuBar_);
        statusBar_ = new HemyStatus::HStatusBar(this);
        setStatusBar(statusBar_);

        retranslateUi();

        QMetaObject::connectSlotsByName(this);
    }

    void HMainWindow::applyStyles()
    {
        qApp->setStyleSheet(HemyStyle::DefaultBlack_MainWindow);
        // 设置应用程序字体
        QFont appFont("Segoe UI", 12, QFont::Bold);
        qApp->setFont(appFont);
    }

    void HMainWindow::ShowWindow()
    {
        show();
    }

    void HMainWindow::changeEvent(QEvent *event)
    {
        if (event->type() == QEvent::LanguageChange) {
            // 重新翻译UI
            retranslateUi();
            setWindowTitle(tr("Qt Internationalization Demo"));

            // 重新翻译自定义菜单
            //fileMenu->retranslateMenu();
        }
        QMainWindow::changeEvent(event);
    }

    void HMainWindow::loadLanguage(const QString& language) {
        // 移除旧翻译
        qApp->removeTranslator(&appTranslator);

        // 加载新翻译
        QString langPath = QApplication::applicationDirPath() +
                           "/translations/app_" + language;

        if (appTranslator.load(langPath)) {
            qApp->installTranslator(&appTranslator);
        } else {
            qWarning() << "Failed to load translation file:" << langPath;
        }
    }

    void HMainWindow::retranslateUi() {
        // 触发语言改变事件
        QEvent event(QEvent::LanguageChange);
        QApplication::sendEvent(this, &event);
    }

    void HMainWindow::switchToEnglish()
    {
        loadLanguage("en_US");
        retranslateUi();
    }

    void HMainWindow::switchToChinese()
    {
        loadLanguage("zh_CN");
        retranslateUi();
    }
}