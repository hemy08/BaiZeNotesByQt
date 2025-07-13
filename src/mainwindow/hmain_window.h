//
// Created by Administrator on 25-6-29.
//

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>
#include <QTranslator>
#include "menu_bar.h"
#include "status_bar.h"
#include "main_spitter.h"

namespace HemyUI
{
    class HMainWindow : public QMainWindow {
        Q_OBJECT

    public:
        explicit HMainWindow(QWidget *parent = nullptr);
        void CreateMainWindow(); // setupUi
        void setupUi(); // setupUi
        void ShowWindow();

    protected:
        void changeEvent(QEvent *event) override;

    private slots:
        void switchToEnglish();
        void switchToChinese();

    private:
        HemyMenu::HMenuBar *menuBar = nullptr;
        HemyStatus::HStatusBar *statusBar = nullptr; // 改为自定义类
        HMainLayOut::HemyMainSpitter *m_main_splitter = nullptr;
        QHBoxLayout *mainLayout = nullptr;
        QWidget *central = nullptr;
        QTranslator appTranslator;

        void createMainLayout();
        void setupNavigation();
        void addSampleContent();
        void applyStyles();
        void loadLanguage(const QString& language);
        void retranslateUi();
    };
}

#endif //MAINWINDOW_H
