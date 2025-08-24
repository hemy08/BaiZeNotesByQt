//
// Created by zhaoj on 25-7-17.
//

#include "file_proc.h"
#include "const_def.h"
#include "gui_comm_def.h"

namespace HEMY_API
{
    bool File::ReadFile(const QString& filePath, QString& content, const MsgCallBack& msgBox)
    {
        // 检查文件是否存在
        if (!QFileInfo::exists(filePath)) {
            msgBox(HEMY_GUI::MSG_TYPE_ERROR, "文件不存在:" + filePath);
            return false;
        }

        // 检查文件大小（防止加载超大文件）
        constexpr qint64 maxSize = 10 * 1024 * 1024; // 10MB限制
        const QFileInfo fileInfo(filePath);
        if (fileInfo.size() > maxSize) {
            const QString text = "文件过大，无法读取:" + filePath + "大小:" +
                QString::fromStdString(std::to_string(fileInfo.size())) + "字节";
            msgBox(HEMY_GUI::MSG_TYPE_ERROR, text);
            return false;
        }

        QFile file(filePath);

        // 尝试打开文件
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            msgBox(HEMY_GUI::MSG_TYPE_ERROR,
                "无法打开文件:" + filePath + "错误:" + file.errorString());
            return false;
        }

        // 使用QTextStream读取，明确设置编码
        QTextStream in(&file);
        in.setEncoding(QStringConverter::Utf8); // 明确使用UTF-8编码

        // 读取内容
        content = in.readAll();

        // 检查读取错误
        if (in.status() != QTextStream::Ok) {
            msgBox(HEMY_GUI::MSG_TYPE_ERROR, "读取文件时发生错误:" + filePath);
            file.close();
            return false;
        }

        file.close();
        return true;
    }
}