import QtQuick 2.5

Item {
    id: root

    property alias discipline: disciplinelabel.text
    property alias startsAt: fromLabel.text
    property alias endsAt: toLabel.text
    property alias visibleStartsAt: fromLabel.visible
    property alias visibleEndsAt: toLabel.visible
    property alias color: classImage.color
    clip: true

    Rectangle {
        id: classImage
        anchors.fill: parent
        anchors.centerIn: parent
        color: "deepskyblue"
        border.color: Qt.lighter(color)
//        source: "../images/stone" + (Math.floor(Math.random() * (5 - 1)) + 1) + ".png"

        Item {
            id: labels
            anchors.centerIn: parent
            height: parent.height - parent.height * 0.1
            width: parent.width - parent.width * 0.1

            Text {
                id: disciplinelabel
                text: "undefined"
                anchors {
                    horizontalCenter: labels.horizontalCenter
                    top: labels.top
                }
                font.pixelSize: parent.height * 0.3

            }

            Text {
                id: fromLabel
                text: "from: 08:00\tam"
                anchors {
                    top: disciplinelabel.bottom
                    horizontalCenter: labels.horizontalCenter
                }
                font.pixelSize: parent.height * 0.15
            }

            Text {
                id: toLabel
                text: "to: 10:00\tam"
                anchors {
                    top: fromLabel.bottom
                    horizontalCenter: labels.horizontalCenter
                }
                font.pixelSize: parent.height * 0.15
            }
        }
//        Image {
//            id: removeIcon
//            source: "../images/removeButton.png"
//            width: 25; height: 25
//            anchors.right: bookMarkBG.right
//            anchors.verticalCenter: parent.verticalCenter
//            anchors.rightMargin: bookMarkBG.width * 0.1

//            MouseArea {
//                anchors.fill: parent
//                onClicked: root.remove()
//            }
//        }
    }
}

