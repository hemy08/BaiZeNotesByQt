//
// Created by Administrator on 25-6-29.
//

#ifndef CENTRALWIDGETS_H
#define CENTRALWIDGETS_H
#include <QMainWindow>
#include <QWidget>

namespace HemyUi {

class CentralWidgets : public QWidget {
public:
    static QWidget* CreateCentralWidgets(QMainWindow* window);
};

} // HEMYUI

#endif //CENTRALWIDGETS_H
