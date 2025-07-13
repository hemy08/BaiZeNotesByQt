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

        void setTitle(const QString &title) const;
        void addExplorer(QWidget *widget) const;
        void clearExplorer() const;

    private:
        void setupUI();

        QVBoxLayout *m_layout;
        QLabel *m_titleLabel;
    };
}
#endif //EXPLORER_WIDGET_H
