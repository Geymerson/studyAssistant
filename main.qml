import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Controls 1.4
import sa.project 1.0
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

        onDisciplinesSaved: {
            exerciseScreen.saveExercises()
            console.log("saving exercises")
        }

        onDisciplineListChanged: {
            performanceScreen.loadDiscipline()
        }
    }

    ExerciseScreen {
        id: exerciseScreen
        itemList: disciplineScreen.disciplineList
        onExercisesSaved: {
            projectScreen.saveProjects()
            console.log("saving projects")
//            Qt.quit()
        }
    }

    ProjectScreen {
        id: projectScreen
        itemList: disciplineScreen.disciplineList
        onProjectsSaved: {
            testScreen.saveTests()
            console.log("saving tests")
//            console.log("exiting...")
//            Qt.quit()
        }
    }

    TestScreen {
        id: testScreen
        itemList: disciplineScreen.disciplineList
        onTestsSaved: {
            console.log("exiting")
            Qt.quit()
        }
    }

    GridScreen {
        id: gridScreen
    }

    PerformanceScreen {
        id: performanceScreen
        disciplineList: disciplineScreen.disciplineList
        Component.onCompleted: {
//            loadDisciplines()
            loadGrades()
        }
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
            disciplineScreen.saveList()
            console.log("saving disciplines")
            //Qt.quit()
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
