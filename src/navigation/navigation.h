//
// Created by zhaoj on 25-7-13.
//

#ifndef NAVIGATION_H
#define NAVIGATION_H
#include "hmain_window.h"

namespace HemyNav
{
    class HNavigation final: public QWidget {
        Q_OBJECT

    public:
        void addSampleContent();
    public slots:
        static void onHandleTriggeredButton(const HemyUI::HExplorer& explorer, const QString &buttonText);

    private:
        // 内容创建函数
        static QWidget* createSearchContent();
        static QWidget* createDocumentContent();
        static QWidget* createSaveContent();
        static QWidget* createContactContent();

        // 当前内容缓存
        //static QMap<QString, QWidget*> contentCache;
    };
}



#endif //NAVIGATION_H
