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

import "../jbQuick/QChart.js"        as Charts
import "../jbQuick/QChartGallery.js" as ChartsData
import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.1
import QtQuick.Controls.Styles 1.4
import sa.project 1.0

Item {
    id: root
    anchors.fill: parent

    Background {
        id: background
        screenTitle: "How am i doing?"
    }

    property var disciplineList: undefined
    //property var model: undefined

    Image {
        id: row
        source: "../images/flag" + (Math.floor(Math.random() * (4 - 1)) + 1) + ".png"
        height: 70
        anchors.top: parent.top
        anchors.topMargin: parent.height * 0.09
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.leftMargin: parent.width * 0.03
        anchors.rightMargin: parent.width * 0.03

        RowLayout {
            //anchors.centerIn: parent
            anchors.verticalCenter: parent.verticalCenter
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.leftMargin: parent.width * 0.05
            anchors.rightMargin: parent.width * 0.13

            Label {
                id: disciplineLabel
                text: "Discipline:"
                font.pixelSize: 18
                font.family: "courier"
                font.bold: true
                color: "blue"
            }

            MComboBox {
                id: disciplineComboBox
                itemList: disciplineList
                anchors.right: parent.right
                anchors.verticalCenter: parent.verticalCenter
                Layout.fillWidth: true
                Component.onCompleted: {
                    loadBoxItems()
                }
            }
        }
    }

    Image {
        id: graphBG
        source: "../images/graphBG.png"
        width: parent.width - parent.width * 0.10
        height: parent.height/2
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: row.bottom
        anchors.topMargin: parent.height * 0.03

        QChart {
            id: performanceChart
            width: root.width/2; height: root.height/3
            anchors.centerIn: parent
            chartAnimated: true
            chartAnimationEasing: Easing.InOutElastic
            chartAnimationDuration: 2000
            chartData: ChartsData.ChartLineData
            chartType: Charts.ChartType.LINE
            visible: true
        }
    }

    TextArea {
        id: notesTextArea
        font.pixelSize: 12
        text: "General notes:"
        anchors {
            top: graphBG.bottom
            bottom: root.bottom
            bottomMargin: root.height * 0.05
            horizontalCenter: parent.horizontalCenter
        }
        enabled: false
    }

    //TODO: This is just an example
    function loadGrades() {
        for(var i = 0; i < 10; i++) {
            ChartsData.ChartLineData.labels[i] = i;
            ChartsData.ChartLineData.datasets[0].data[i] = i;
            //ChartsData.ChartLineData.datasets[0].data[i] = get(i).grades;
            //ChartsData.ChartLineData.datasets[1].data[i] = i + 1;
        }
        performanceChart.chartData = ChartsData.ChartLineData;
        performanceChart.update()
    }
}//end element item
