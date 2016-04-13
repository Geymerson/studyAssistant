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
import psa.org 1.0

Item {
    id: root
    anchors.fill: parent

    Background {
        id: background
        screenTitle: "How i'm doing..."
    }

    property var disciplineList: undefined
    property var model: undefined

    ListModel {
        id: comboBoxModel
    }

    function loadDiscipline() {
        //console.log("method invoked. List lentgth " + disciplineList.length())
        for(var i = 0; i < disciplineList.length(); i++) {
            comboBoxModel.append({text: disciplineList.get(i).name})
        }
    }

    RowLayout {
        id: row
        anchors.top: parent.top
        anchors.topMargin: parent.height * 0.09
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.leftMargin: parent.width * 0.08
        anchors.rightMargin: parent.width * 0.08

        Label {
            id: disciplineLabel
            text: "Discipline:"
            font.pixelSize: 18
            font.family: "courier"
            font.bold: true
            color: "blue"
        }

        ComboBox {
            id: disciplineComboBox
            model: comboBoxModel
            anchors.right: parent.right
            Layout.fillWidth: true
        }
    }

    QChart {
        id: performanceChart
        width: parent.width/2; height: parent.height/3
        chartAnimated: true
        chartAnimationEasing: Easing.InOutElastic
        chartAnimationDuration: 2000
        chartData: ChartsData.ChartLineData
        chartType: Charts.ChartType.LINE
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: row.bottom
        anchors.topMargin: parent.height * 0.08
        visible: true
    }

    //TODO: This is just an example
    function loadGrades() {
        for(var i = 0; i < 10; i++) {
            ChartsData.ChartLineData.labels[i] = i;
            ChartsData.ChartLineData.datasets[0].data[i] = i;
            //ChartsData.ChartLineData.datasets[0].data[i] = get(i).grades;
            //ChartsData.ChartLineData.datasets[1].data[i] = i + 1;
        }
        chart_line.chartData = ChartsData.ChartLineData;
        chart_line.update()
    }
}//end element item
