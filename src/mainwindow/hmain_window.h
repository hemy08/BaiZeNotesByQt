//
// Created by Administrator on 25-6-29.
//

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtCore/QVariant>
#include <QTranslator>

#include "h_menu_bar.h"
#include "h_status_bar.h"

namespace HemyUi
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
        HemyMenu::HMenuBar *menuBar_{};
        HemyStatus::HStatusBar *statusBar_{}; // 改为自定义类
        QWidget *central_{};
        QTranslator appTranslator;

        void applyStyles();
        void loadLanguage(const QString& language);
        void retranslateUi();
    };
}

#endif //MAINWINDOW_H
