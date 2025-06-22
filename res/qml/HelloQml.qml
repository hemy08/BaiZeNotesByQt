import QtQuick 2.15
import QtQuick.Window 2.15

Window {
    width: 400
    height: 300
    visible: true
    title: "CLion QML Demo"

    Rectangle {
        anchors.centerIn: parent
        width: 200
        height: 100
        color: "lightblue"
        radius: 10

        Text {
            anchors.centerIn: parent
            text: "Hello QML!"
            font.pixelSize: 24
        }
    }
}