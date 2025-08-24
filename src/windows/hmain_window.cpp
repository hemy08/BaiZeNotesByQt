//
// Created by Administrator on 25-6-29.
//
#include <QStyleFactory>
#include <QMenu>
#include <QActionGroup>
#include "hmain_window.h"
#include "window_central.h"
#include "menu_bar.h"
#include "gui_comm_def.h"
#include "../process/render/latex_render.h"
#include "../process/render/render.h"


namespace HemyUI
{
    void HMainWindow::Initial() {
        this->setMainWinTitle(HEMY_GUI::MAIN_WINDOW_TITLE);
        this->setMainWinObjName(HEMY_GUI::MAIN_WINDOW_OBJ_NAME);
        this->setMainWinDefaultWidth(HEMY_GUI::MAIN_WINDOW_DEFAULT_WIDTH);
        this->setMainWinDefaultHeight(HEMY_GUI::MAIN_WINDOW_DEFAULT_HEIGHT);
        SetupUI();
    }

    void HMainWindow::SetupUI() {
        this->resize(getMainWinDefaultWidth(), getMainWinDefaultHeight());

        // 菜单栏
        m_menubar_ = new HMenuBar(this);
        this->setMenuBar(m_menubar_);

        // 中间区域
        m_central_ = new HMainCentral(this);
        this->setCentralWidget(m_central_);
        m_main_splitter = m_central_->central_splitter();
        m_sidebar_ = m_central_->sidebar();
        m_explorer_ = m_central_->explorer();
        m_workbench_ = m_central_->workbench();
        m_main_layout = m_central_->central_layout();
        m_text_edit = m_workbench_->editor();
        m_text_menu = m_workbench_->editorMenu();
        m_text_preview = m_workbench_->preview();
        m_line_no_view = m_workbench_->editor()->lineNoView();

        // 状态栏
        m_statusbar_ = new HStatusBar(this);
        this->setStatusBar(m_statusbar_);

        this->RetranslateUi();

        QMetaObject::connectSlotsByName(this);
        connect(m_workbench_, HWorkBench::SgPlainTextRender, this, plainTextRender);
    }

    void HMainWindow::ShowWindow() {
        show();
    }

    void HMainWindow::changeEvent(QEvent *event)
    {
    }

    void HMainWindow::LoadLanguage(const QString& language) {
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

    void HMainWindow::RetranslateUi() {
        // 触发语言改变事件
        QEvent event(QEvent::LanguageChange);
        QApplication::sendEvent(this, &event);
    }

    void HMainWindow::switchToEnglish()
    {
        LoadLanguage("en_US");
        RetranslateUi();
    }

    void HMainWindow::switchToChinese()
    {
        LoadLanguage("zh_CN");
        RetranslateUi();
    }

    QString HMainWindow::getMainWinTitle()
    {
        if (title.isEmpty()) {
            return HEMY_GUI::MAIN_WINDOW_TITLE;
        }
        return title;
    }

    void HMainWindow::setMainWinTitle(const QString& value)
    {
        title = value;
        this->setWindowTitle(value);
    }

    QString HMainWindow::getMainWinObjName()
    {
        if (objName.isEmpty()) {
            return HEMY_GUI::MAIN_WINDOW_OBJ_NAME;
        }

        if (this->objectName().isEmpty()) {
            this->setObjectName(objName);
        }

        return this->objectName();
    }

    void HMainWindow::setMainWinObjName(const QString& value)
    {
        objName = value;
        this->setObjectName(value);
    }

    int HMainWindow::getMainWinDefaultWidth() const
    {
        if (defaultWidth == 0) {
            return HEMY_GUI::MAIN_WINDOW_DEFAULT_WIDTH;
        }
        return defaultWidth;
    }

    void HMainWindow::setMainWinDefaultWidth(const int& value)
    {
        defaultWidth = value;
    }
    int HMainWindow::getMainWinDefaultHeight() const
    {
        if (defaultHeight == 0) {
            return HEMY_GUI::MAIN_WINDOW_DEFAULT_HEIGHT;
        }
        return defaultHeight;
    }

    void HMainWindow::setMainWinDefaultHeight(const int& value)
    {
        defaultHeight = value;
    }

    void HMainWindow::plainTextRender(const QString& text)
    {
        auto result = HemyRender::Render::RenderText(text);
        LOG_INFO("plain_text", result);
        emit SgPlainTextRenderResult(result);
    }
}
