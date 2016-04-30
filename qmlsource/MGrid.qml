import QtQuick 2.5
import QtQuick.Layouts 1.1
import "../cmpCreator.js" as CmpCreator

Item {
    //    color: "green"
    id: disciGrid
    anchors.centerIn: parent
    //    anchors.horizontalCenter: parent.horizontalCenter
    width: 500
    height: 500

    property int cellHeight: height/10
    property int cellWidth: width/5

    Component.onCompleted: {
        CmpCreator.startGrid()
    }
}
