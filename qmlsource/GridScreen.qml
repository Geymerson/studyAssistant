/**
    Study Assistant: an application to help the management of study activities
    Copyright (C) 2016,  @author: Geymerson Ramos <geymerson.r@gmail.com>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
**/

import QtQuick 2.5
import QtQuick.Controls 1.4

import "../cmpCreator.js" as CmpCreator

Item {
    id: root
    anchors.fill: parent

    property alias schedule: gridS.schedule
    property alias itemList: actionBox.itemList
    property alias actionBox_z: actionBox.z
    property alias actionBoxVisible: actionBox.visible

    Background {
        id: background
        screenTitle: "Grid"
    }

    Flickable {
        width: parent.width - parent.width * 0.1
        height: parent.height * 0.70
        clip: true
        anchors.centerIn: parent
        contentHeight: gridS.height
        contentWidth: gridS.width
        leftMargin:5
        rightMargin: 5

        MGrid {
            id: gridS
            z: 3
        }
    }

    ActionBox {
        id: actionBox
        visible: false
        text: "Class information"
        timePickerLabel: "From: "
        timePickerLabel1: "To: "
        height: background.height - background.height/4
        componentType: 2
        nameLabelVisible: false
        nameTextFieldVisible: false
        professorLabelVisible: false
        professorTextFieldVisible: false
        disciplineLabelVisible: true
        disciplineComboBoxVisible: true
        daysLabelVisible: true
        daysComboBoxVisible: true
        timePickerLabelVisible: true
        timePickerTextFieldVisible: true
        timePickerLabelVisible1: true
        timePickerTextFieldVisible1: true


        itemList: itemList
    }
}
