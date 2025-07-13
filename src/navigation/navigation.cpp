//
// Created by zhaoj on 25-7-13.
//

#include "navigation.h"
#include <QListWidget>
#include <QLineEdit>
#include <QMessageBox>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QFormLayout>
#include <QComboBox>
#include <QCheckBox>
#include "explorer_widget.h"
#include "hmain_window.h"
#include "main_spitter.h"
#include "sidebar_widget.h"

namespace HemyNav
{
    /*void HNavigation::addSampleContent() {
        HMainLayOut::HemyExplorerWidget *explorer = mainSpliter_->explorer();

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
    }*/

    void HNavigation::onHandleTriggeredButton(const HMainLayOut::HemyMainSpitter& mainSpliter, const QString &buttonText) {
        const HMainLayOut::HemyExplorerWidget *explorer = mainSpliter.explorer();
        explorer->setTitle(buttonText);

        // 清除旧内容（保留标题）
        if (QLayout *layout = explorer->layout()) {
            while (const QLayoutItem *item = layout->takeAt(1)) {
                if (QWidget *widget = item->widget()) {
                    widget->setParent(nullptr);
                    widget->deleteLater();
                }
                delete item;
            }
        }

        // 获取或创建新内容
        QWidget *contentWidget = nullptr;

        /*if (contentCache.contains(buttonText)) {
            contentWidget = contentCache[buttonText];
        } else {
            if (buttonText == "🔍") {
                contentWidget = createSearchContent();
            } else if (buttonText == "📖") {
                contentWidget = createDocumentContent();
            } else if (buttonText == "💾") {
                contentWidget = createSaveContent();
            } else if (buttonText == "☎") {
                contentWidget = createContactContent();
            }

            if (contentWidget) {
                contentCache[buttonText] = contentWidget;
            }
        }*/

        // 添加新内容
        /*if (contentWidget) {
            explorer->addExplorer(contentWidget);
            contentWidget->show();
        }*/
    }

    // 搜索页面内容
QWidget* HNavigation::createSearchContent() {
    QWidget *searchWidget = new QWidget();
    QVBoxLayout *layout = new QVBoxLayout(searchWidget);

    QLineEdit *searchInput = new QLineEdit();
    searchInput->setPlaceholderText("输入搜索内容...");
    searchInput->setStyleSheet("padding: 10px; font-size: 16px;");

    QPushButton *searchButton = new QPushButton("搜索");
    searchButton->setStyleSheet("padding: 10px; background-color: #4CAF50; color: white;");

    QListWidget *resultsList = new QListWidget();

    layout->addWidget(searchInput);
    layout->addWidget(searchButton);
    layout->addWidget(resultsList);

    // 连接搜索功能
    connect(searchButton, &QPushButton::clicked, [=]() {
        QString query = searchInput->text().trimmed();
        if (!query.isEmpty()) {
            resultsList->clear();
            // 模拟搜索结果
            for (int i = 0; i < 5; ++i) {
                resultsList->addItem(QString("结果 %1: %2").arg(i + 1).arg(query));
            }
        }
    });

    return searchWidget;
}

// 文档页面内容
QWidget* HNavigation::createDocumentContent() {
    QWidget *docWidget = new QWidget();
    QVBoxLayout *layout = new QVBoxLayout(docWidget);

    QTextEdit *textEdit = new QTextEdit();
    textEdit->setPlaceholderText("在此输入文档内容...");
    textEdit->setStyleSheet("font-size: 14px;");

    QPushButton *saveButton = new QPushButton("保存文档");
    saveButton->setStyleSheet("padding: 8px; background-color: #2196F3; color: white;");

    layout->addWidget(textEdit);
    layout->addWidget(saveButton, 0, Qt::AlignRight);

    // 连接保存功能
    connect(saveButton, &QPushButton::clicked, [=]() {
        QString content = textEdit->toPlainText();
        if (!content.isEmpty()) {
            QMessageBox::information(nullptr, "文档保存", "文档已成功保存！");
        } else {
            QMessageBox::warning(nullptr, "文档保存", "文档内容为空！");
        }
    });

    return docWidget;
}

// 保存页面内容
QWidget* HNavigation::createSaveContent() {
    QWidget *saveWidget = new QWidget();
    QVBoxLayout *layout = new QVBoxLayout(saveWidget);

    QLabel *titleLabel = new QLabel("保存选项");
    titleLabel->setStyleSheet("font-size: 18px; font-weight: bold;");

    QComboBox *formatCombo = new QComboBox();
    formatCombo->addItems({"PDF", "DOCX", "TXT", "HTML"});

    QCheckBox *backupCheck = new QCheckBox("创建备份副本");
    backupCheck->setChecked(true);

    QPushButton *saveButton = new QPushButton("执行保存");
    saveButton->setStyleSheet("padding: 10px; background-color: #FF9800; color: white;");

    layout->addWidget(titleLabel);
    layout->addWidget(new QLabel("保存格式:"));
    layout->addWidget(formatCombo);
    layout->addWidget(backupCheck);
    layout->addWidget(saveButton, 0, Qt::AlignCenter);

    // 连接保存功能
    connect(saveButton, &QPushButton::clicked, [=]() {
        QString format = formatCombo->currentText();
        bool backup = backupCheck->isChecked();

        QString message = QString("正在保存为 %1 格式").arg(format);
        if (backup) message += " (包含备份)";

        QMessageBox::information(nullptr, "保存操作", message);
    });

    return saveWidget;
}

// 联系页面内容
QWidget* HNavigation::createContactContent() {
    QWidget *contactWidget = new QWidget();
    QFormLayout *form = new QFormLayout(contactWidget);

    QLineEdit *nameInput = new QLineEdit();
    nameInput->setPlaceholderText("您的姓名");

    QLineEdit *emailInput = new QLineEdit();
    emailInput->setPlaceholderText("您的邮箱");

    QTextEdit *messageInput = new QTextEdit();
    messageInput->setPlaceholderText("您的留言...");
    messageInput->setMaximumHeight(150);

    QPushButton *sendButton = new QPushButton("发送消息");
    sendButton->setStyleSheet("padding: 10px; background-color: #9C27B0; color: white;");

    form->addRow("姓名:", nameInput);
    form->addRow("邮箱:", emailInput);
    form->addRow("留言:", messageInput);
    form->addRow(sendButton);

    // 连接发送功能
    connect(sendButton, &QPushButton::clicked, [=]() {
        QString name = nameInput->text().trimmed();
        QString email = emailInput->text().trimmed();
        QString message = messageInput->toPlainText().trimmed();

        if (name.isEmpty() || email.isEmpty() || message.isEmpty()) {
            QMessageBox::warning(nullptr, "发送失败", "请填写所有字段");
            return;
        }

        if (!email.contains("@")) {
            QMessageBox::warning(nullptr, "发送失败", "邮箱格式不正确");
            return;
        }

        QMessageBox::information(nullptr, "消息已发送",
                                QString("感谢 %1, 您的消息已发送!\n"
                                        "我们会尽快通过 %2 回复您")
                                .arg(name).arg(email));
    });

    return contactWidget;
}
}
