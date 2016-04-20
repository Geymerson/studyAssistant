import QtQuick 2.5
import QtQuick.Controls 1.4

Item {
    id: root
    height: 25
    property alias text1: field1.text
    property alias placeholderText1: field1.placeholderText
    property alias maximumLength1: field1.maximumLength
    property alias text2: field2.text
    property alias placeholderText2: field2.placeholderText
    property alias maximumLength2: field2.maximumLength
    property int pixelSize: 12
    property bool date: true

    TextField {
        id: field1
        placeholderText: "dd"
        width: parent.width/2 - separator.width
        height: parent.height
        font.pixelSize: pixelSize
        anchors {
            left: parent.left
        }
    }

    Label {
        id: separator
        text: ":"
        anchors {
            left: field1.right
        }
    }

    TextField {
        id: field2
        placeholderText: "mm"
        width: parent.width/2 - separator.width
        height: parent.height
        font.pixelSize: pixelSize
        anchors {
            left: separator.right
            right: parent.right
        }
    }
}

