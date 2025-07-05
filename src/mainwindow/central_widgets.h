//
// Created by Administrator on 25-6-29.
//

#ifndef CENTRALWIDGETS_H
#define CENTRALWIDGETS_H
#include <QMainWindow>
#include <QWidget>

namespace HemyUI {

class CentralWidgets : public QWidget {
public:
    static QWidget* CreateCentralWidgets(QMainWindow* window);
};

} // HemyUI

#endif //CENTRALWIDGETS_H
