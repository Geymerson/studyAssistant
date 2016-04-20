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
var appDate = new Date();
//var cellWidth = 100;
//var cellHeight = 30;
//var rowNumber = 10;
//var columnNumber = 5;
//var gridSize = cellWidth * cellHeight;
//var grid = new Array(gridSize)

//function getIndex(row, column) {
//    return row * 5 + column;
//}

//function loadGrid() {
//    //Destroy previous grid
//    for(var i = 0; i < gridSize; i++) {
//        if(grid[i] != null) {
//            grid[i].destroy();
//        }
//    }

//    grid = new Array(gridSize);

//    for (var row = 0; row < rowNumber; row++) {
//        for (var col = 0; col < columnNumber; col++) {
//            grid[getIndex(row, col)] = null;
//            createGridElement(row, col, disciName);
//        }
//    }
//}

//function createGridElement(row, column, disciName) {
//    if (component == null) {
//        component = Qt.createComponent("../qmlsource/MGridElement.qml");
//    }

//    if( component.status == Component.Ready ) {
//        var dynamicObject = component.createObject(disciplineGrid)
//        if (dynamicObject == null) {
//            console.log("error creating grid element");
//            console.log(component.errorString());
//            return false;
//        }
//        dynamicObject.text = disciName
//        dynamicObject.x = column * cellWidth;
//        dynamicObject.y = row * cellHeight;
//        dynamicObject.width = cellWidth;
//        dynamicObject.height = cellHeight;
//        grid[ getIndex(row, column) ] = dynamicObject;
//    }
//    else {
//        console.log("error creating grid element component");
//        console.log(component.errorString());
//        return false;
//    }
//}

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
        console.log("error loading block component");
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
        console.log("error loading block component");
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
