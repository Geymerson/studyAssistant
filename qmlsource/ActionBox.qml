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
import QtQuick.Layouts 1.1
import "../cmpCreator.js" as CmpCreator

Item {
    id: root
    height: parent.height / 2
    width: parent.width - 10
    anchors.centerIn: parent
    z: 0

    property int componentType: 0
    property int activityType: 0
    property var activityParent: undefined
    property alias itemList: disciplineComboBox.itemList
    property alias text: title.text
    property alias nameLabelVisible: nameLabel.visible
    property alias nameTextFieldVisible: nameTextField.visible
    property alias professorLabelVisible: professorLabel.visible
    property alias professorTextFieldVisible: professorTextField.visible
    property alias disciplineLabelVisible: disciplineLabel.visible
    property alias disciplineComboBoxVisible: disciplineComboBox.visible
    property alias gradeLabelVisible: gradeLabel.visible
    property alias gradeTextFieldVisible: gradeTextField.visible
    property alias achievedGradeLabelVisible: achievedGradeLabel.visible
    property alias achievedGradeTextFieldVisible: achievedGradeTextField.visible
    property alias dateLabelVisible: dateLabel.visible
    property alias dateTextFieldVisible: dateTextField.visible

    //ActionBox background
    Image {
        id: background
        source: "../images/stickyNote.png"
        anchors.fill: parent

        Item {
            id: container
            anchors.fill: parent
            anchors.margins: parent.height * 0.10

            //Box remove icon
            Image {
                id: removeIcon
                anchors.right: parent.right
                anchors.top: parent.top
                source: "../images/removeButton.png"
                height: title.height
                width: height
                scale: 0.8

                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        root.visible = false
                        root.z = 0
                    }
                }
            }

            Item {
                id: verticalSpacement1
                width: background.width
                height: background.height * 0.12
            }

            //Box title
            Text {
                id: title
                text: qsTr("General information")
                font.family: "courier"
                font.bold: true
                font.pixelSize: 15
                color: "black"
                anchors.horizontalCenter: container.horizontalCenter
                anchors.top: verticalSpacement1.bottom
            }

            //Box add icon
            Image {
                id: addIcon
                anchors.bottom: container.bottom
                anchors.horizontalCenter: container.horizontalCenter
                source: "../images/addButton.png"
                height: 30; width: 30

                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        if(root.componentType == 0) {//Disciplines
                            CmpCreator.createDiscipline(nameTextField.text,
                                                        professorTextField.text)
                            nameTextField.text = ""
                            professorTextField.text  = ""
                        }
                        else if(root.componentType == 1) {//Activities
                            var date = new Date()
                            CmpCreator.createActivity(nameTextField.text,
                                                      disciplineComboBox.currentText,
                                                      root.activityType,
                                                      dateTextField.text1,
                                                      dateTextField.text2,
                                                      gradeTextField.text,
                                                      achievedGradeTextField.text,
                                                      root.activityParent)
                            console.log(disciplineComboBox.currentText)
                            nameTextField.text = ""
                            gradeTextField.text = ""
                            achievedGradeTextField.text = ""
                            dateTextField.text1 = ""
                            dateTextField.text2 = ""
                        }
                        root.z = 0
                        root.visible = false
                    }
                }
            }

            Item {
                id: verticalSpacement2
                height: container.height * 0.12
                width: container.width
                anchors.top: title.bottom
            }

            GridLayout {
                id: grid
                anchors.top: verticalSpacement2.bottom
                columns: 2

                Label {
                    id: nameLabel
                    text: "Name:"
                    font.pixelSize: 12
                    font.family: "courier"
                    font.bold: true
                    color: "black"
                }

                TextField {
                    id: nameTextField
                    font.pixelSize: 12
                }

                Label {
                    id: professorLabel
                    text: "Professor:"
                    font.pixelSize: 12
                    font.family: "courier"
                    font.bold: true
                    color: "black"
                }

                TextField {
                    id: professorTextField
                    font.pixelSize: 12
                }

                Label {
                    id: disciplineLabel
                    text: "Discipline:"
                    font.family: "courier"
                    font.pixelSize: 12
                    font.bold: true
                    color: "black"
                    visible: false
                }

                MComboBox {
                    id: disciplineComboBox
                    Layout.fillWidth: true
                    //font.pixelSize: 12
                    visible: false
                    Component.onCompleted: {
                        loadBoxItems()
                    }
                }

                Label {
                    id: daysLabel
                    text: "Class Day:"
                    font.family: "courier"
                    font.pixelSize: 12
                    font.bold: true
                    color: "black"
                    visible: false
                }

                ComboBox {
                    id: daysComboBox
                    Layout.fillWidth: true
                    //font.pixelSize: 12
                    visible: false
                    model: ["Monday", "Tuesday", "Wednesday", "Thursday", "Friday","Saturday","Sunday"]
                }

                Label {
                    id: dateLabel
                    text: "Submission date:"
                    font.family: "courier"
                    font.pixelSize: 12
                    font.bold: true
                    color: "black"
                    visible: false
                }

                MTimePicker {
                    id: dateTextField
                    visible: false
                    Layout.fillWidth: true
                    Component.onCompleted: {
                        if(!date) {
                            placeholderText1 = "hh"
                            placeholderText2 = "mm"
                        }
                    }
                }

//                TextField {
//                    id: dateTextField
//                    font.pixelSize: 12
//                    visible: false
//                    Layout.fillWidth: true
//                }

                Label {
                    id: gradeLabel
                    text: "Grade:"
                    font.family: "courier"
                    font.pixelSize: 12
                    font.bold: true
                    color: "black"
                    visible: false
                }

                TextField {
                    id: gradeTextField
                    font.pixelSize: 12
                    visible: false
                }

                Label {
                    id: achievedGradeLabel
                    text: "Achieved Grade:"
                    font.family: "courier"
                    font.pixelSize: 12
                    font.bold: true
                    color: "black"
                    visible: false
                }

                TextField {
                    id: achievedGradeTextField
                    font.pixelSize: 12
                    visible: false
                }
            }
        }
    }
}
