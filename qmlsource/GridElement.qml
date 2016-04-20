import QtQuick 2.5

Rectangle {
    id: root
    width: 100; height: 30
    property alias text: textElement.text
    color: "deepskyblue"
    border.color: Qt.lighter(color)

    Text {
        id: textElement
        text: qsTr("text")
        anchors {
            centerIn: parent
        }
    }
}
