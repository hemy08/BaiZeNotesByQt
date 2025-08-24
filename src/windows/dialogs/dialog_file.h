//
// Created by zhaoj on 25-8-10.
//

#ifndef DIALOG_FILE_H
#define DIALOG_FILE_H
#include <QDialog>
#include <QFileDialog>

#include "error.h"
#include "gui_comm_def.h"

namespace HEMY_DIALOGS
{
    class HFile: public QWidget {
        ErrCode NewFile(QString& fileName, QString title = "新建文件");
        ErrCode NewFolder(QString& folderName, QString title = "新建文件夹");
        ErrCode OpenFile(QString& fileName, QString title =  "打开文件");
        ErrCode OpenFolder(QString& folderName, QString title = "打开文件夹");
        ErrCode SaveFile(QString title = "保存文件");
        ErrCode SaveAsFile(QString title = "另存为...");
    };

}



#endif //DIALOG_FILE_H
