//
// Created by zhaoj on 25-7-17.
//

#include "special_font_dialog.h"
#include <QDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QComboBox>
#include <QColorDialog>
#include <QFontDatabase>

namespace HemyUI
{
    SpecialFont::SpecialFont(QWidget *parent) : QDialog(parent) {
        // 设置对话框字体为非粗体
        QFont dialogFont = this->font();
        dialogFont.setBold(false);
        this->setFont(dialogFont);
        setupUI();
        connectSignals();
    }

    void SpecialFont::setupUI()
    {
        // 主布局
        QVBoxLayout *mainLayout = new QVBoxLayout(this);

        // 创建非粗体字体
        QFont nonBoldFont = this->font();
        nonBoldFont.setBold(false);

        // 字体选择行
        QHBoxLayout *fontLayout = new QHBoxLayout();
        QLabel *fontLabel = new QLabel("选择字体:");
        fontLabel->setFont(nonBoldFont);
        fontLayout->addWidget(fontLabel);

        fontCombo = new QFontComboBox();
        fontLayout->addWidget(fontCombo);

        QPushButton *addButton = new QPushButton("Add");
        addButton->setFont(nonBoldFont);
        fontLayout->addWidget(addButton);

        // 字体大小行
        QHBoxLayout *sizeLayout = new QHBoxLayout();
        QLabel *sizeLabel = new QLabel("字体大小:");
        sizeLabel->setFont(nonBoldFont);
        sizeLayout->addWidget(sizeLabel);

        sizeSpin = new QSpinBox();
        sizeSpin->setRange(1, 100);
        sizeSpin->setValue(5);
        sizeLayout->addWidget(sizeSpin);

        QLabel *ptLabel = new QLabel("pt");
        ptLabel->setFont(nonBoldFont);
        sizeLayout->addWidget(ptLabel);

        // 颜色选择行
        QHBoxLayout *colorLayout = new QHBoxLayout();
        QLabel *colorLabel = new QLabel("字体颜色:");
        colorLabel->setFont(nonBoldFont);
        colorLayout->addWidget(colorLabel);

        colorButton = new QPushButton();
        colorButton->setFixedSize(30, 20);
        colorButton->setStyleSheet("background-color: black;");
        colorLayout->addWidget(colorButton);

        colorLayout->addSpacing(20);

        QLabel *bgColorLabel = new QLabel("背景色:");
        bgColorLabel->setFont(nonBoldFont);
        colorLayout->addWidget(bgColorLabel);

        bgColorButton = new QPushButton();
        bgColorButton->setFixedSize(30, 20);
        bgColorButton->setStyleSheet("background-color: white;");
        colorLayout->addWidget(bgColorButton);

        // 样式设置区域
        QGroupBox *styleGroup = new QGroupBox("文本样式");
        styleGroup->setFont(nonBoldFont);
        QGridLayout *styleLayout = new QGridLayout();

        boldCheck = new QCheckBox("加粗");
        boldCheck->setFont(nonBoldFont);
        italicCheck = new QCheckBox("倾斜");
        italicCheck->setFont(nonBoldFont);
        underlineCheck = new QCheckBox("下划线");
        underlineCheck->setFont(nonBoldFont);
        strikeCheck = new QCheckBox("删除线");
        strikeCheck->setFont(nonBoldFont);

        styleLayout->addWidget(boldCheck, 0, 0);
        styleLayout->addWidget(italicCheck, 0, 1);
        styleLayout->addWidget(underlineCheck, 1, 0);
        styleLayout->addWidget(strikeCheck, 1, 1);

        styleGroup->setLayout(styleLayout);

        // 对齐方式区域
        QGroupBox *alignGroup = new QGroupBox("对齐方式");
        alignGroup->setFont(nonBoldFont);
        QGridLayout *alignLayout = new QGridLayout();

        leftAlign = new QRadioButton("左对齐");
        leftAlign->setFont(nonBoldFont);
        centerAlign = new QRadioButton("居中对齐");
        centerAlign->setFont(nonBoldFont);
        rightAlign = new QRadioButton("右对齐");
        rightAlign->setFont(nonBoldFont);
        justifyAlign = new QRadioButton("两端对齐");
        justifyAlign->setFont(nonBoldFont);
        leftAlign->setChecked(true);

        alignLayout->addWidget(leftAlign, 0, 0);
        alignLayout->addWidget(centerAlign, 0, 1);
        alignLayout->addWidget(rightAlign, 1, 0);
        alignLayout->addWidget(justifyAlign, 1, 1);

        alignGroup->setLayout(alignLayout);

        // 样式和对齐组合布局
        QHBoxLayout *styleAlignLayout = new QHBoxLayout();
        styleAlignLayout->addWidget(styleGroup);
        styleAlignLayout->addWidget(alignGroup);

        // 编辑区域
        QLabel *editLabel = new QLabel("编辑区域:");
        editLabel->setFont(nonBoldFont);
        textEdit = new QTextEdit();
        textEdit->setPlaceholderText("在此输入文本...");
        textEdit->setFixedHeight(100);

        // 预览区域
        QLabel *previewLabel = new QLabel("效果预览:");
        previewLabel->setFont(nonBoldFont);
        previewText = new QLabel("这是一段预览文字。");
        previewText->setFrameStyle(QFrame::Panel | QFrame::Sunken);
        previewText->setAlignment(Qt::AlignCenter);
        previewText->setMinimumHeight(40);
        previewText->setStyleSheet("background-color: white;");

        // 按钮区域
        QHBoxLayout *buttonLayout = new QHBoxLayout();
        buttonLayout->addStretch();
        cancelButton = new QPushButton("取消");
        cancelButton->setFont(nonBoldFont);
        buttonLayout->addWidget(cancelButton);

        // 添加所有部件到主布局
        mainLayout->addLayout(fontLayout);
        mainLayout->addLayout(sizeLayout);
        mainLayout->addLayout(colorLayout);
        mainLayout->addLayout(styleAlignLayout);
        mainLayout->addWidget(editLabel);
        mainLayout->addWidget(textEdit);
        mainLayout->addWidget(previewLabel);
        mainLayout->addWidget(previewText);
        mainLayout->addLayout(buttonLayout);

        setWindowTitle("特殊文字编辑");
        resize(500, 600);
    }

    void SpecialFont::connectSignals() {
        // 连接信号槽
        connect(fontCombo, &QFontComboBox::currentFontChanged, this, &SpecialFont::updatePreview);
        connect(sizeSpin, QOverload<int>::of(&QSpinBox::valueChanged), this, &SpecialFont::updatePreview);
        connect(colorButton, &QPushButton::clicked, this, [this]() {
            QColor color = QColorDialog::getColor(Qt::black, this);
            if (color.isValid()) {
                colorButton->setStyleSheet("background-color: " + color.name() + ";");
                updatePreview();
            }
        });
        connect(bgColorButton, &QPushButton::clicked, this, [this]() {
            QColor color = QColorDialog::getColor(Qt::white, this);
            if (color.isValid()) {
                bgColorButton->setStyleSheet("background-color: " + color.name() + ";");
                updatePreview();
            }
        });
        connect(boldCheck, &QCheckBox::checkStateChanged, this, &SpecialFont::updatePreview);
        connect(italicCheck, &QCheckBox::checkStateChanged, this, &SpecialFont::updatePreview);
        connect(underlineCheck, &QCheckBox::checkStateChanged, this, &SpecialFont::updatePreview);
        connect(strikeCheck, &QCheckBox::checkStateChanged, this, &SpecialFont::updatePreview);
        connect(textEdit, &QTextEdit::textChanged, this, &SpecialFont::updatePreview);
        connect(applyButton, &QPushButton::clicked, this, &QDialog::accept);
        connect(cancelButton, &QPushButton::clicked, this, &QDialog::reject);
    }

    void SpecialFont::updatePreview() const
    {
        // 获取当前设置
        QFont font = fontCombo->currentFont();
        font.setPointSize(sizeSpin->value());
        font.setBold(boldCheck->isChecked());
        font.setItalic(italicCheck->isChecked());
        font.setUnderline(underlineCheck->isChecked());
        font.setStrikeOut(strikeCheck->isChecked());

        // 设置预览文本
        QString text = textEdit->toPlainText().isEmpty() ?
                      "这是一段预览文字。" : textEdit->toPlainText();

        previewText->setFont(font);
        previewText->setText(text);

        // 设置颜色
        QString style = "background-color: " + bgColorButton->styleSheet().split(": ").last().replace(";", "") + ";";
        style += "color: " + colorButton->styleSheet().split(": ").last().replace(";", "") + ";";
        previewText->setStyleSheet(style);

        // 设置对齐方式
        Qt::Alignment align = Qt::AlignLeft;
        if (centerAlign->isChecked()) align = Qt::AlignCenter;
        else if (rightAlign->isChecked()) align = Qt::AlignRight;
        else if (justifyAlign->isChecked()) align = Qt::AlignJustify;
        previewText->setAlignment(align);
    }
}