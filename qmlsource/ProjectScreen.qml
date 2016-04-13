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
import psa.org 1.0

ActivityScreen {
    id: root
    activityTitle: "Projects"
    actionBoxText: "Project information"
    componentType: 1
    activityType: 3

    ActivityList {
        id: projectList
    }
    activityList: projectList
}
