//
// Created by zhaoj on 25-7-13.
//

#ifndef EDITOR_LINE_NO_H
#define EDITOR_LINE_NO_H
#include "workbench_editor.h"
#include <QWidget>

namespace HemyUI
{
    class LineNumberArea : public QWidget {
    public:
        explicit LineNumberArea(HWorkBenchEditor *editor = nullptr);
        ~LineNumberArea() override = default;

        [[nodiscard]] QSize sizeHint() const override;

    protected:
        void paintEvent(QPaintEvent *event) override;

    private:
        HWorkBenchEditor *m_editor;
    };
}


#endif //EDITOR_LINE_NO_H
