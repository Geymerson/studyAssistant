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
import QtQuick.Window 2.2
import QtQuick.Controls 1.4
import psa.org 1.0
import "qmlsource"

Window {
    id: appWindow
    visible: true
    width: 310; height: 500

    Item {
        id: navigators
        anchors.top: appWindow.top
        width: parent.width; height: 50
        z: 10

        MButton {
            id: backwardButton
            source: "images/backwardButton.png"
            anchors.left: parent.left
            anchors.top: parent.top
            anchors.leftMargin: parent.width * 0.05
            anchors.topMargin: parent.width * 0.01
            visible: false
            onClicked: {
                if(stackView.depth > 1) {
                    stackView.pop()
                    if(stackView.depth == 1) {
                        visible = false
                    }
                    else if(stackView.depth == 5) {
                        forwardButton.visible = true
                    }
                }
            }
        }

        MButton {
            id: forwardButton
            source: "images/forwardButton.png"
            anchors.right: parent.right
            anchors.top: parent.top
            anchors.topMargin: parent.width * 0.01
            anchors.rightMargin: parent.width * 0.05
            onClicked: {
                if(stackView.depth == 1) {
                    stackView.push(exerciseScreen)
                    backwardButton.visible = true
                }
                else if(stackView.depth == 2) {
                    stackView.push(testScreen)
                }
                else if(stackView.depth == 3) {
                    stackView.push(projectScreen)
                }
                else if(stackView.depth == 4) {
                    stackView.push(gridScreen)
                }
                else if(stackView.depth == 5) {
                    stackView.push(performanceScreen)
                    visible = false
                }
            }
        }
    }

    DisciplineScreen {
        id: disciplineScreen

        onDisciplinesLoaded: {
            performanceScreen.disciplineList = disciplineScreen.disciplineList
            performanceScreen.loadDiscipline();
            performanceScreen.loadGrades();
        }

        onDisciplinesSaved: {
            exerciseScreen.saveActivities()
        }        
    }

    ExerciseScreen {
        id: exerciseScreen
        onActivitiesSavedChanged: projectScreen.saveActivities()
    }

    ProjectScreen {
        id: projectScreen
        onActivitiesSavedChanged: testScreen.saveActivities()
    }

    TestScreen {
        id: testScreen
        onActivitiesSavedChanged: Qt.quit()
    }

    GridScreen {
        id: gridScreen
    }

    PerformanceScreen {
        id: performanceScreen
        //disciplineList: disciplineScreen.disciplineList
    }

    StackView {
        id: stackView
        anchors.fill: parent
        focus: true
        initialItem: disciplineScreen

        delegate: StackViewDelegate {
            function transitionFinished(properties) {
                properties.exitItem.opacity = 1
            }

            pushTransition: StackViewTransition {
                PropertyAnimation {
                    target: enterItem
                    property: "opacity"
                    from: 0
                    to: 1
                }
                PropertyAnimation {
                    target: exitItem
                    property: "opacity"
                    from: 1
                    to: 0
                }
            }
        }
    }

    MToolBar{
        id: toolBar
        anchors.bottom: parent.bottom

        onQuitClicked: {
            disciplineScreen.saveList();
        }

        onAddClicked: {
            if(stackView.depth == 1) {
                disciplineScreen.actionBoxVisible = true
                disciplineScreen.actionBox_z = 10
            }
            else if(stackView.depth == 2) {
                exerciseScreen.actionBoxVisible = true
                exerciseScreen.actionBox_z = 10
            }
            else if(stackView.depth == 3) {
                testScreen.actionBoxVisible = true
                testScreen.actionBox_z = 10
            }
            else if(stackView.depth == 4) {
                projectScreen.actionBoxVisible = true
                projectScreen.actionBox_z = 10
            }
        }

        onSettingsClicked: {
            console.log("Not configured yet!")
            console.log(disciplineScreen.disciplineList.length())
        }
    }
}
