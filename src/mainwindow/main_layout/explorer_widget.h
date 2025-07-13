//
// Created by zhaoj on 25-7-11.
//

#ifndef EXPLORER_WIDGET_H
#define EXPLORER_WIDGET_H
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>

namespace HMainLayOut
{
    class HemyExplorerWidget : public QWidget {
        Q_OBJECT
    public:
        explicit HemyExplorerWidget(QWidget *parent = nullptr);
        ~HemyExplorerWidget() override = default;

        void setTitle(const QString &title);
        void addExplorer(QWidget *widget);
        void clearExplorer();

    private:
        void setupUI();

        QVBoxLayout *m_layout;
        QLabel *m_titleLabel;
    };
}
#endif //EXPLORER_WIDGET_H
