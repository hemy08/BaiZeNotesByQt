//
// Created by Administrator on 25-6-29.
//

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QHBoxLayout>
#include <QSplitter>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>
#include <QTranslator>
#include "explorer_widget.h"
#include "menu_bar.h"
#include "sidebar_widget.h"
#include "status_bar.h"
#include "window_central.h"
#include "workbench.h"

namespace HemyUI
{
    class HMainWindow : public QMainWindow {
        Q_OBJECT

    public:
        static HMainWindow* GetInst() {
            static HMainWindow instance; // 静态局部变量保证唯一性
            return &instance;
        }
        ~HMainWindow() override = default;

        void Initial(); // setupUi
        void SetupUI(); // setupUi
        void ShowWindow();
        QString getMainWinTitle();
        void setMainWinTitle(const QString& value);
        QString getMainWinObjName();
        void setMainWinObjName(const QString& value);
        int getMainWinDefaultWidth() const;
        void setMainWinDefaultWidth(const int& value);
        [[nodiscard]] int getMainWinDefaultHeight() const;
        void setMainWinDefaultHeight(const int& value);

    signals:  // 信号声明区域（无返回值，只需声明）
        void SgPlainTextRenderResult(const QString& text);  // 信号声明

    protected:
        void changeEvent(QEvent *event) override;


    private slots:
        void switchToEnglish();
        void switchToChinese();
        void plainTextRender(const QString& text);

    private:
        QString title = "";
        QString objName = "";
        int defaultWidth = 0;
        int defaultHeight = 0;
        HMenuBar *m_menubar_ = nullptr;
        HStatusBar *m_statusbar_ = nullptr; // 改为自定义类
        HMainCentral *m_central_ = nullptr;
        QSplitter *m_main_splitter = nullptr;
        HSidebar *m_sidebar_ = nullptr;
        HExplorer *m_explorer_ = nullptr;
        HWorkBench *m_workbench_ = nullptr;
        QHBoxLayout *m_main_layout = nullptr;
        HWorkBenchEditor *m_text_edit = nullptr;
        HWorkBenchMenu *m_text_menu = nullptr;
        HWorkBenchPreview *m_text_preview = nullptr;
        LineNumberArea *m_line_no_view = nullptr;
        QTranslator appTranslator;

        void LoadLanguage(const QString& language);
        void RetranslateUi();
    };
}

#endif //MAINWINDOW_H
