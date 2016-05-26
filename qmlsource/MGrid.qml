import QtQuick 2.5
import QtQuick.Layouts 1.1
import "../cmpCreator.js" as CmpCreator
import sa.project 1.0

Item {

    id: disciGrid
    anchors.centerIn: parent
    width: 500
    height: 500

    property int cellHeight: height/10
    property int cellWidth: width/5
    property alias schedule: schedule

    Schedule {
        id: schedule
        Component.onCompleted: {
//            console.log(length())
            CmpCreator.startGrid();
        }
    }
}
