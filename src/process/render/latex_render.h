//
// Created by zhaoj on 25-8-17.
//

#ifndef LATEX_RENDER_H
#define LATEX_RENDER_H
#include <qstring.h>

namespace HemyRender
{
    class HLatex {
    public:
        static HLatex* GetInst() {
            static HLatex instance; // 静态局部变量保证唯一性
            return &instance;
        }
        static QString Render(const QString& text);

    private:
        static QString convertFormula(const QString& formula, bool isInline);
        static QString convertTextWithFormulas(const QString& text);
        static QString convertMatrixToMarkdown(const QString& latexMatrix);
    };
}

#endif //LATEX_RENDER_H
