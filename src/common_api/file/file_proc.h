//
// Created by zhaoj on 25-7-17.
//

#ifndef FILE_PROC_H
#define FILE_PROC_H
#include <QFile>
#include <QDir>
#include <QFileDialog>
#include <QInputDialog>
#include <QMessageBox>

namespace HEMY_API
{
    class File final : public QFile {
    public:
        using MsgCallBack = std::function<void(const QString &title, const QString &text)>;
        static bool ReadFile(const QString& filePath, QString& content, const MsgCallBack& msgBox);
    };
}





#endif //FILE_PROC_H
