import QtQuick 2.5
import QtQuick.Controls 1.4

Item {
    id: root
    height: 25; width: 100

    property var itemList: undefined
    property alias currentText: comboBox.currentText
    property alias currentIndex: comboBox.currentIndex
    property alias count: comboBox.count
    property alias comboBoxModel: comboBoxModel

    function loadBoxItems() {
        for(var i = 0; i < itemList.length(); i++) {
            comboBoxModel.append({text: itemList.get(i).name})
        }
    }

    ListModel {
        id: comboBoxModel
    }

    ComboBox {
        id: comboBox
        anchors.fill: parent
        model: comboBoxModel
    }
}

