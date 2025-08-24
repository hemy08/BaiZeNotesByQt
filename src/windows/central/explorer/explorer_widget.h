//
// Created by zhaoj on 25-7-11.
//

#ifndef EXPLORER_WIDGET_H
#define EXPLORER_WIDGET_H
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>

namespace HemyUI
{
    class HExplorer : public QWidget {
        Q_OBJECT
    public:
        explicit HExplorer(QWidget *parent = nullptr);
        ~HExplorer() override = default;

        void setTitle(const QString &title) const;
        void addExplorer(QWidget *widget) const;
        void clearExplorer() const;

    private:
        void Initial();

        QVBoxLayout* m_exp_layout{};
        QLabel *m_exp_label{};
    };
}
#endif //EXPLORER_WIDGET_H
