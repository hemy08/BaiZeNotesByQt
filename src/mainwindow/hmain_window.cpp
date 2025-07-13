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
#include "menu_bar.h"
#include "const_def.h"
#include "hemy_style.h"
#include "main_spitter.h"
#include "sidebar_widget.h"
#include "../navigation/navigation.h"


namespace HemyUI
{
    HMainWindow::HMainWindow(QWidget *parent) :
        QMainWindow(parent) {
        CreateMainWindow();
        setupUi();
        applyStyles();
    }

    HMainWindow::~HMainWindow()
    {
        delete m_main_splitter;
        delete mainLayout;
    }

    void HMainWindow::CreateMainWindow()
    {
        if (objectName().isEmpty()) {
            setObjectName(MAIN_WIN_OBJ_NAME);
        }

        // 设置初始语言为系统语言
        /*if (QLocale::system().language() == QLocale::Chinese) {
            switchToChinese();
        } else {
            switchToEnglish();
        }*/
        setWindowTitle(WIN_TITLE);
        resize(MAIN_DEFAULT_WIDTH, MAIN_DEFAULT_HEIGHT);

        central = CentralWidgets::CreateCentralWidgets(this);
        setCentralWidget(central);
        menuBar = new HemyMenu::HMenuBar(this);
        setMenuBar(menuBar);
        statusBar = new HemyStatus::HStatusBar(this);
        setStatusBar(statusBar);

        createMainLayout();
    }

    void HMainWindow::createMainLayout()
    {
        // 主布局
        mainLayout = new QHBoxLayout(central);
        mainLayout->setSpacing(0);
        mainLayout->setContentsMargins(0, 0, 0, 0);

        // 创建分割布局
        m_main_splitter = new HMainLayOut::HemyMainSpitter(central);
        mainLayout->addWidget(m_main_splitter);

        // 添加导航按钮
        setupNavigation();

        // 添加示例内容
        addSampleContent();
    }

    void HMainWindow::setupNavigation() {
        HMainLayOut::HemySidebarWidget *sidebar = m_main_splitter->sidebar();

        sidebar->addNavigationButton("🔍");
        sidebar->addNavigationButton("📖");
        sidebar->addNavigationButton("💾");
        sidebar->addNavigationButton("☎");

        // 连接按钮点击信号
        connect(sidebar, &HMainLayOut::HemySidebarWidget::buttonClicked, this, [this](const QString &buttonText) {
            HemyNav::HNavigation::onHandleTriggeredButton(*m_main_splitter, buttonText);
        });
    }

    void HMainWindow::addSampleContent() {
        HMainLayOut::HemyExplorerWidget *explorer = m_main_splitter->explorer();

        // 添加示例控件
        QFrame *sampleFrame = new QFrame();
        sampleFrame->setStyleSheet(
            "QFrame {"
            "   background-color: #bdc3c7;"
            "   border-radius: 8px;"
            "   padding: 15px;"
            "}"
        );
        auto *sampleLabel = new QLabel("尝试拖动左侧的分隔条来调整边栏宽度", sampleFrame);
        sampleLabel->setAlignment(Qt::AlignCenter);
        auto *frameLayout = new QVBoxLayout(sampleFrame);
        frameLayout->addWidget(sampleLabel);

        explorer->addExplorer(sampleFrame);
    }

    void HMainWindow::setupUi()
    {
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
        /*if (event->type() == QEvent::LanguageChange) {
            // 重新翻译UI
            retranslateUi();
            setWindowTitle(tr("Qt Internationalization Demo"));

            // 重新翻译自定义菜单
            //fileMenu->retranslateMenu();
        }
        QMainWindow::changeEvent(event);*/
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
