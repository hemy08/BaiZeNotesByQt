#include <QGuiApplication>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    // 加载QML文件（确保路径正确）
    //engine.load(QUrl("qrc:/main.qml"));  // 或使用绝对路径
    // 改用绝对路径（调试用）
    engine.load(QUrl::fromLocalFile("res/HelloQml.qml"));

    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}