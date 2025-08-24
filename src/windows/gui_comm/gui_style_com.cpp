//
// Created by zhaoj on 25-8-10.
//

#include "gui_style_com.h"

#include <QString>

namespace HEMY_GUI
{
    QString applyQPushButtonStyle(const QString &align, int padding, int radius) {
        return QString(
            "QPushButton {"
            "  background-color: #3498db;"
            "  text-align: %1;"
            "  padding: %2px 1px;"
            "  color: #ecf0f1;"
            "  border-radius: %3px;"
            "  font-weight: bold;"
            "  border: 2px solid #2980b9;"
            "}"
            "QPushButton:hover {"
            "  background-color: #34495e;"
            "}"
            "QPushButton:pressed {"
            "  background-color: #1abc9c;"
            "}"
        ).arg(align).arg(padding).arg(radius);
    }

}
