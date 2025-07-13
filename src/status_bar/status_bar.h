//
// Created by Administrator on 25-7-4.
//

#ifndef H_STATUS_BAR_H
#define H_STATUS_BAR_H
#include <QStatusBar>
#include <QLabel>

namespace HemyStatus
{
class HStatusBar final :public QStatusBar{
    Q_OBJECT
public:
    explicit HStatusBar(QWidget *parent = nullptr);
    ~HStatusBar() override = default;
private:
    QLabel *model_{};
    QLabel *line_{};
    QLabel *theme_{};
    void CreateStatusBar(); // 可在此添加自定义状态栏初始化逻辑
};
}

#endif //H_STATUS_BAR_H
