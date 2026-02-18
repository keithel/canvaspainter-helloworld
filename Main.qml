import QtQuick
import canvaspainter_helloworld

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
    color: "black"

    HelloItem {
        id: hi
        anchors.fill: parent
        PropertyAnimation {
            target: hi
            property: "rotation"
            from: 0
            to: 360
            duration: 5000
            loops: Animation.Infinite
            running: true
        }
    }
}
