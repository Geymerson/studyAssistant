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

Item {
    id: root
    width: ListView.view.width
    height: 70
    property alias text: label.text
    property alias color: label.color

    signal clicked()
    signal remove()

    Image {
        id: bookMarkBG
        anchors.fill: parent
        anchors.centerIn: parent
        source: "../images/flag" + (Math.floor(Math.random() * (4 - 1)) + 1) + ".png"

        Text {
            id: label
            anchors.verticalCenter: bookMarkBG.verticalCenter
            anchors.left: bookMarkBG.left
            anchors.leftMargin: bookMarkBG.width * 0.1
            font.pixelSize: 20
        }

        Image {
            id: removeIcon
            source: "../images/removeButton.png"
            width: 25; height: 25
            anchors.right: bookMarkBG.right
            anchors.verticalCenter: parent.verticalCenter
            anchors.rightMargin: bookMarkBG.width * 0.1

            MouseArea {
                anchors.fill: parent
                onClicked: root.remove()
            }
        }
    }
}

