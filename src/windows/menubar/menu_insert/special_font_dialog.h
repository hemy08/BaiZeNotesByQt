//
// Created by zhaoj on 25-7-17.
//

#ifndef SPECIAL_FONT_DIALOG_H
#define SPECIAL_FONT_DIALOG_H
#include <qdialog.h>
#include <QApplication>
#include <QLabel>
#include <QPushButton>
#include <QSpinBox>
#include <QCheckBox>
#include <QTextEdit>
#include <QGroupBox>
#include <QButtonGroup>
#include <QRadioButton>
#include <QFontComboBox>


namespace HemyUI
{
    class SpecialFont : public QDialog
    {
        Q_OBJECT
    public:
        explicit SpecialFont(QWidget *parent = nullptr);
        ~SpecialFont() override = default;

    private:
        void setupUI();
        void connectSignals();

    private slots:
        void updatePreview() const;
    private:
        QFontComboBox* fontCombo = nullptr;
        QSpinBox* sizeSpin = nullptr;
        QPushButton* colorButton = nullptr;
        QPushButton* bgColorButton = nullptr;
        QCheckBox* boldCheck = nullptr;
        QCheckBox* italicCheck = nullptr;
        QCheckBox* underlineCheck = nullptr;
        QCheckBox* strikeCheck = nullptr;
        QRadioButton* leftAlign = nullptr;
        QRadioButton* centerAlign = nullptr;
        QRadioButton* rightAlign = nullptr;
        QRadioButton* justifyAlign = nullptr;
        QTextEdit* textEdit = nullptr;
        QLabel* previewText = nullptr;
        QPushButton* cancelButton = nullptr;
        QPushButton* applyButton = nullptr;
    };
}



#endif //SPECIAL_FONT_DIALOG_H
