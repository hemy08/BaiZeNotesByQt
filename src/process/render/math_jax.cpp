//
// Created by zhaoj on 25-8-17.
//

#include "math_jax.h"
#include <QtWebView>
#include <QProcess>
#include <QtMath>
#include <QTemporaryFile>

namespace HemyRender
{
    QString renderWithMathJaxNode(const QString& latex) {
        QTemporaryDir tempDir;
        QString inputPath = tempDir.filePath("input.tex");
        QString outputPath = tempDir.filePath("output.html");

        // 创建输入文件
        QFile inputFile(inputPath);
        if (inputFile.open(QIODevice::WriteOnly)) {
            inputFile.write(latex.toUtf8());
            inputFile.close();
        }

        // 执行 MathJax 渲染
        QProcess process;
        process.start("node", {
            "/path/to/mathjax-render.js",
            "--input", inputPath,
            "--output", outputPath
        });
        process.waitForFinished();

        // 读取结果
        QFile outputFile(outputPath);
        if (outputFile.open(QIODevice::ReadOnly)) {
            return outputFile.readAll();
        }

        return "<div>Rendering failed</div>";
    }
}