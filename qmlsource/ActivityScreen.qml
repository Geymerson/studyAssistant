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
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.1
import psa.org 1.0

Item {
    id: root
    anchors.fill: parent

    Background {
        id: background
        screenTitle: "Activity Title"
    }

    function saveActivities() {
        activityList.saveActivities();
        activitiesSaved = true
    }

    property alias actionBox_z: actionBox.z
    property alias actionBoxVisible: actionBox.visible
    property alias actionBoxText: actionBox.text
    property alias componentType: actionBox.componentType
    property alias activityTitle: background.screenTitle
    property alias activityType: actionBox.activityType
    property var activityList: undefined
    property bool activitiesSaved: false

    //This box will pop up when
    //the add button is pressed
    ActionBox {
        id: actionBox
        visible: false
        text: "Exercise information"
        height: background.height - background.height/4
        componentType: componentType
        activityParent: activityList
        activityType: activityType
        professorLabelVisible: false
        professorTextFieldVisible: false
        gradeLabelVisible: true
        gradeTextFieldVisible: true
        achievedGradeLabelVisible: true
        achievedGradeTextFieldVisible: true
        disciplineLabelVisible: true
        disciplineTextFieldVisible: true
        dateLabelVisible: true
        dateTextFieldVisible: true
    }

    ColumnLayout {
        anchors.fill: parent
        anchors.topMargin: parent.height * 0.08
        anchors.bottomMargin: parent.height * 0.08
        width: root.width
        anchors.margins: 8

        ScrollView {
            Layout.fillHeight: true
            Layout.fillWidth: true

            ListView {
                id: view
                model: activityList
                delegate: ActivityModel {
                    width: ListView.view.width
                    //Get discipline name
                    text: model.name

                    onClicked: {
                        // make this delegate the current item
                        view.currentIndex = index
                        view.focus = true
                    }
                    onRemove: {
                        // remove the current entry from the model
                        activityList.remove(index)
                    }
                }

                //Transitions
                add: Transition {
                    // applied when entry is added
                    NumberAnimation {
                        properties: "x"; from: -view.width;
                        duration: 250; easing.type: Easing.InCirc
                    }
                    NumberAnimation { properties: "y"; from: view.height;
                        duration: 250; easing.type: Easing.InCirc
                    }
                }
                remove: Transition {
                    // applied when entry is removed
                    NumberAnimation {
                        properties: "x"; to: view.width;
                        duration: 250; easing.type: Easing.InBounce
                    }
                }
                displaced: Transition {
                    // applied when entry is moved
                    // (e.g because another element was removed)
                    SequentialAnimation {
                        // wait until remove has finished
                        PauseAnimation { duration: 250 }
                        NumberAnimation { properties: "y"; duration: 75
                        }
                    }
                }
            }
        }
    }
}//end element item
