//
// Created by zhaoj on 25-8-17.
//

#include "latex_render.h"
#include <QRegularExpression>

namespace HemyRender
{
    // 转换单个公式
    QString HLatex::convertFormula(const QString& formula, bool isInline = true) {
        QString converted = formula.trimmed();

        // 移除多余空格
        converted.replace(QRegularExpression("\\s+"), " ");

        // 添加Markdown公式标记
        if (isInline) {
            return "$" + converted + "$";
        } else {
            return "$$\n" + converted + "\n$$";
        }
    }

    // 转换文本中的公式
    QString HLatex::convertTextWithFormulas(const QString& text) {
        QString result = text;

        // 处理行内公式
        QRegularExpression inlineRegex(R"(\$([^\$]+)\$)");
        QRegularExpressionMatchIterator i = inlineRegex.globalMatch(text);
        while (i.hasNext()) {
            QRegularExpressionMatch match = i.next();
            QString formula = match.captured(1);
            result.replace("$" + formula + "$", convertFormula(formula, true));
        }

        // 处理行间公式
        QRegularExpression blockRegex(R"(\\\[(.*?)\\\]|\$\$(.*?)\$\$)",
                                     QRegularExpression::DotMatchesEverythingOption);
        i = blockRegex.globalMatch(text);
        while (i.hasNext()) {
            QRegularExpressionMatch match = i.next();
            QString formula = match.captured(1).isEmpty() ? match.captured(2) : match.captured(1);
            result.replace(match.captured(0), convertFormula(formula, false));
        }

        // 处理LaTeX环境
        QRegularExpression envRegex(R"(\\begin\{([a-z]+)\*\}(.*?)\\end\{\1\*\})",
                                   QRegularExpression::DotMatchesEverythingOption);
        i = envRegex.globalMatch(text);
        while (i.hasNext()) {
            QRegularExpressionMatch match = i.next();
            QString formula = match.captured(2);
            result.replace(match.captured(0), convertFormula(formula, false));
        }

        return result;
    }
    QString HLatex::convertMatrixToMarkdown(const QString& latexMatrix)
    {
        QRegularExpression matrixRegex(R"(\\begin\{bmatrix\}(.*?)\\end\{bmatrix\})");
        matrixRegex.setPatternOptions(QRegularExpression::DotMatchesEverythingOption);

        QString result = latexMatrix;

        int pos = 0;
        QRegularExpressionMatch match;
        while ((match = matrixRegex.match(result, pos)).hasMatch()) {
            QString matrix = match.captured(1).trimmed();
            QStringList rows = matrix.split("\\\\");
            QStringList mdRows;

            // 处理每一行
            for (const QString& row : rows) {
                QStringList cols = row.split("&");
                // 清理每列内容
                for (QString& col : cols) {
                    col = col.trimmed();
                    // 处理空列
                    if (col.isEmpty()) col = " ";
                }
                mdRows << "| " + cols.join(" | ") + " |";
            }

            // 添加表头分隔线
            if (!mdRows.isEmpty()) {
                QString separator = "|";
                for (int i = 0; i < mdRows.first().count('|') - 1; i++) {
                    separator += " --- |";
                }
                mdRows.insert(1, separator);
            }

            // 构建替换内容
            QString replacement = "\n" + mdRows.join("\n") + "\n";

            // 执行替换
            result.replace(match.capturedStart(), match.capturedLength(), replacement);
            pos = match.capturedStart() + replacement.length();
        }

        return result;
    }

    // 获取编辑器内容并转换公式
    QString HLatex::Render(const QString& text) {
        QString output = text;

        // 1. 标准LaTeX公式转换
        output = convertTextWithFormulas(output);

        // 2. 矩阵转换
        output = convertMatrixToMarkdown(output);

        // 3. 分数转换
        output.replace(QRegularExpression(R"(\\frac\{([^{}]+)\}\{([^{}]+)\})"),
                      "($1)/($2)");

        // 4. 根号转换
        output.replace(QRegularExpression(R"(\\sqrt\[([^]]+)\]\{([^{}]+)\})"),
                      "root($2, $1)");
        output.replace(QRegularExpression(R"(\\sqrt\{([^{}]+)\})"),
                      "√($1)");

        // 5. 希腊字母转换
        QHash<QString, QString> greekMap = {
            {"\\alpha", "α"}, {"\\beta", "β"}, {"\\gamma", "γ"}, {"\\delta", "δ"},
            {"\\epsilon", "ε"}, {"\\zeta", "ζ"}, {"\\eta", "η"}, {"\\theta", "θ"},
            {"\\iota", "ι"}, {"\\kappa", "κ"}, {"\\lambda", "λ"}, {"\\mu", "μ"},
            {"\\nu", "ν"}, {"\\xi", "ξ"}, {"\\pi", "π"}, {"\\rho", "ρ"},
            {"\\sigma", "σ"}, {"\\tau", "τ"}, {"\\upsilon", "υ"}, {"\\phi", "φ"},
            {"\\chi", "χ"}, {"\\psi", "ψ"}, {"\\omega", "ω"}
        };

        for (auto it = greekMap.constBegin(); it != greekMap.constEnd(); ++it) {
            output.replace(it.key(), it.value());
        }

        return output;
    }
}
