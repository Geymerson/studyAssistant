/**
    Study Assistant: an application to help the management of study activities
    Copyright (C) {2016},  @author: Geymerson Ramos <geymerson.r@gmail.com>

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
import "../cmpCreator.js" as CmpCreator

Image {
    id: root
    width: parent.width; height: 20
    source: "../images/toolBar.png"

    signal addClicked()
    signal quitClicked()
    signal settingsClicked()

    MouseArea {
        id: mouseArea
        anchors.fill: parent
        hoverEnabled: true
        onHoveredChanged: {
            root.height == 20 ? root.height = 60 : root.height = 20
        }
    }

    Item {
        width: parent.width
        anchors.bottom: parent.bottom
        anchors.top: parent.top
        anchors.topMargin: 22

        //Exit button
        MButton {
            id: quitButton
            source: "../images/quitButton.png"
            anchors.bottom: parent.bottom
            anchors.leftMargin: parent.width * 0.03
            anchors.bottomMargin: parent.width * 0.02
            anchors.top: parent.top
            anchors.left: parent.left
            onClicked: root.quitClicked()
        }

        //Button to add discipline
        MButton {
            id: addButton
            source: "../images/addButton.png"
            anchors.bottom: parent.bottom
            anchors.top: parent.top
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottomMargin: parent.width * 0.02
            onClicked: root.addClicked()
        }

        //Button to change settings
        MButton {
            id: settingsButton
            source: "../images/settingsButton.png"
            anchors.bottom: parent.bottom
            anchors.right: parent.right
            anchors.rightMargin: parent.width * 0.03
            anchors.bottomMargin: parent.width * 0.02
            anchors.top: parent.top
            onClicked: root.settingsClicked()
        }
    }

    //Tool bar animation
    Behavior on height {
        NumberAnimation {
            duration: 300
            easing.type: Easing.InOutQuad
        }
    }
}
