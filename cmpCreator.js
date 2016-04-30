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

var component;
//var appDate = new Date();
var maxRow = 11;
var maxColumn = 5;
var maxIndex = maxColumn * maxRow;
var grid = new Array(maxIndex);

function getIndex(row, column) {
    console.log(row * maxColumn + column);
    return row * maxColumn + column;
}

function startGrid() {
    for (var i = 0; i < maxIndex; i++) {
        if (grid[i] != null)
            grid[i].destroy();
    }
    maxIndex = maxRow * maxColumn;
    grid = new Array(maxIndex);

    for (var column = 0; column < maxColumn; column++) {
        for (var row = 0; row < maxRow; row++) {
            if( getIndex(row, column) == 0) {
                createClass(row, column, "Monday");
            }
            else if(getIndex(row, column) == 1) {
                createClass(row, column, "Tuesday", 0, 0);
            }
            else if(getIndex(row, column) == 2) {
                createClass(row, column, "Wednesday", 0, 0);
            }
            else if(getIndex(row, column) == 3) {
                createClass(row, column, "Thursday", 0, 0);
            }
            else if( getIndex(row, column) == 4) {
                createClass(row, column, "Friday", 0, 0);
            }
            else {
                disciGrid[ getIndex(row, column) ] = null;
                createClass(row, column, "any", 0, 0);
            }
        }
    }
}

function createClass(row, column, discipline, hour, time) {
    if (component == null) {
        component = Qt.createComponent("../qmlsource/MClass.qml");
    }

    if (component.status == Component.Ready) {
        var dynamicObject = component.createObject(disciGrid);
        if (dynamicObject == null) {
            console.log("error creating class");
            console.log(component.errorString());
            return false;
        }
        if(row == 0) {
            dynamicObject.visibleStartsAt = false
            dynamicObject.visibleEndsAt = false
            dynamicObject.color = "orange"
        }

        dynamicObject.discipline = discipline;
        //        dynamicObject.classTime = "00:00";
        dynamicObject.x = column * disciGrid.cellWidth;
        dynamicObject.y = row * disciGrid.cellHeight;
        dynamicObject.width = disciGrid.cellWidth;
        dynamicObject.height = disciGrid.cellHeight;
        grid[ getIndex(row, column) ] = dynamicObject;
        //        dynamicObject.append();

    }
    else {
        console.log("error loading class component");
        console.log(component.errorString());
        return false;
    }
    return true;
}

function createDiscipline(name, professor) {
    if (component == null) {
        component = Qt.createComponent("../qmlsource/MDiscipline.qml");
    }

    if (component.status == Component.Ready) {
        var dynamicObject = component.createObject(disciplineList);
        if (dynamicObject == null) {
            console.log("error creating discipline");
            console.log(component.errorString());
            return false;
        }
        dynamicObject.name = name;
        dynamicObject.professor = professor;
        disciplineList.append(dynamicObject);
    }
    else {
        console.log("error loading discipline component");
        console.log(component.errorString());
        return false;
    }
    return true;
}

function createActivity(name, discipline, type, day, month, grade, achievedGrade, parent) {
    if (component == null) {
        component = Qt.createComponent("../qmlsource/MActivity.qml");
    }

    if (component.status == Component.Ready) {
        var dynamicObject = component.createObject(parent);
        if (dynamicObject == null) {
            console.log("error creating activity");
            console.log(component.errorString());
            return false;
        }
        dynamicObject.name = name;
        dynamicObject.discipline = discipline;
        dynamicObject.activityType = type;

        dynamicObject.date = String(appDate.getFullYear()) + '-' + month + '-' + day
        console.log(dynamicObject.date.toString())
        dynamicObject.grade = grade;
        dynamicObject.achievedGrade = achievedGrade;
        parent.append(dynamicObject);
    }
    else {
        console.log("error loading activity component");
        console.log(component.errorString());
        return false;
    }
    return true;
}

function loadDisciplines() {
    for(var i = 0; i < disciplineList.length(); i++) {
        comboBoxModel.append({text: disciplineList.get(i).name})
    }
}
