#include "../headers/datamanager.h"

DataManager::DataManager() {
    m_loadType = 0; //Don't load any activity
}

DataManager::DataManager(int loadType) {
    m_loadType = loadType;
}

int DataManager::getLoadType() const {
    return m_loadType;
}

void DataManager::setLoadType(int loadType) {
    m_loadType = loadType;
}

void DataManager::clear() {
    m_activityList.clear();
    m_disciplineList.clear();
}

QList<Discipline *> DataManager::getDisciplineList() {
    loadDisciplineList();
    return m_disciplineList;
}

void DataManager::setDisciplineList(const QList<Discipline *> &disciplineList) {
    m_disciplineList = disciplineList;
}

void DataManager::appendDisciplineList(const QList<Discipline *> &disciplineList) {
    m_disciplineList.append(disciplineList);
}

void DataManager::loadDisciplineList() {
    QFile disciList("disciplineList.sa");
    if(!disciList.open(QIODevice::ReadOnly)) {
        qDebug() << "Could not open the file, discipline list doesn't exist, load failed.";
        return;
    }

    //### Read discipline information ###
    QString disci;
    while(!disciList.atEnd()) {
        disci = disciList.readLine(); //Get discipline name
        disci = disci.left(disci.length() - 1); //Removing \n character
        QFile disciFile(disci + ".sa");//Open discipline file
        if(!disciFile.open(QIODevice::ReadOnly)) {
            qDebug() << "Failed to open discipline file at loadList() method";
        }

        //Read professor name and discipline grade
        Discipline *discipline = new Discipline();
        QString line;
        discipline->setName(disci);//Setting name
        line = disciFile.readLine();//Get professor
        line = line.left(line.length() - 1);
        discipline->setProfessor(line.right(line.length() - 10));//Setting professor
        line = disciFile.readLine();//Get grade
        discipline->setGrade(line.right(line.length() - 17).toFloat());//Setting grade
        m_disciplineList.append(discipline);//Append discipline to the list
    }
    disciList.close();
}

void DataManager::updateDisciplineList() {
    QByteArray toFile;
    QFile disciList("disciplineList.sa");
    if(!disciList.open(QIODevice::WriteOnly)) {
        qDebug() << " Could not open the file, update failed.";
        return;
    }
    foreach (Discipline *disci, m_disciplineList) {
        toFile.append(disci->name())
                .append('\n');
    }
    disciList.write(toFile);
    disciList.flush();
    disciList.close();
}

void DataManager::saveDisciplineList() {
    updateDisciplineList();
    //Create disciplines individual files
    foreach(Discipline *disci, m_disciplineList) {
        QString filePath(disci->name()+".sa");
        QFile file(filePath);
        QByteArray toFile;

        if(!file.open(QIODevice::WriteOnly)) {
            qDebug() << " Could not open the file, save failed";
            return;
        }
        toFile.append("professor:" + disci->professor() + '\n');
        toFile.append("discipline_grade:" + QString::number(disci->grade()) + '\n');
        toFile.append("activities are saved as "
                      "{name;grade;achievedGrade;type;date;discription} below\n");
        file.write(toFile);
        file.flush();
        file.close();
    }
}

QList<Activity *> DataManager::getActivityList() {
    loadActivityList();
    return m_activityList;
}

void DataManager::setActivityList(const QList<Activity *> &activityList) {
    m_activityList = activityList;
}

void DataManager::appendActivityList(const QList<Activity*> &activityList) {
    m_activityList.append(activityList);
}

void DataManager::loadActivityList() {
    QFile disciList("disciplineList.sa");
    if(!disciList.open(QIODevice::ReadOnly)) {
        qDebug() << "Could not open the file, load failed.";
        return;
    }

    QStringList disciplines;
    QString line;
    while(!disciList.atEnd()) {
        Activity *activity = new Activity();
        line = disciList.readLine(); //Get discipline name
        line = line.left(line.length() - 1); //Removing \n character
//        qDebug() << line;
        activity->setDiscipline(line);
        disciplines.append(line);
        //m_activityList.append(activity);
    }
    disciList.close();

    foreach (QString discipline, disciplines) {
        QFile disciFile(discipline +".sa");
        if(!disciFile.open(QIODevice::ReadOnly)) {
            qDebug() << "failed to open dicicipline file at loadActivityList() method";
        }
        //Skip the 3 first lines
        disciFile.readLine();
        disciFile.readLine();
        disciFile.readLine();

        while(!disciFile.atEnd()) {
            line = disciFile.readLine();
            line = line.right(line.length() - 1).left(line.length() - 1); //Remove brackets {...}
            //A list with each activity information, like:
            //name at(0), grades at(1), etc...
            QStringList activityData = line.split(";");
            int activityType = activityData.at(3).toInt(); //Get activity type
            if(activityType == m_loadType) {
                Activity *activity = new Activity();

                activity->setDiscipline(discipline);
//                qDebug() << "name: "<<activity->discipline();

                activity->setName(activityData.at(0));
//                qDebug() << "name: "<<activity->name();

                activity->setGrade(activityData.at(1).toFloat());
                //qDebug() << "grade: "<<activity->grade();

                activity->setAchievedGrade(activityData.at(2).toFloat());
                //qDebug() << "achieved grade"<< activity->achievedGrade();

                activity->setActivityType(activityType);
                //qDebug() << "type: " << activity->activityType();

                //day at(0), month at(1), year at(2)
                QStringList date = activityData.at(4).split(".") ;
                activity->setDate(QDate(date.at(2).toInt(),
                                        date.at(1).toInt(),
                                        date.at(0).toInt()));
                m_activityList.append(activity);
            }
        }
        disciFile.close();
    }
}

void DataManager::saveActivityList() {
    //Write disciplines' activities
    foreach (Activity* acti, m_activityList) {
        QString disci = acti->discipline() + ".sa";
        QFile disciFile(disci);//Open discipline file
        if(!disciFile.open(QIODevice::Append)) {
            qDebug() << "Failed to open discipline file at loadList() method";
        }
        QByteArray toFile;
        toFile.append("{");
        toFile.append(acti->name()+';');
//        qDebug() << "Writing: " + acti->name() + " to file";
        toFile.append(QString::number(acti->grade())+';');
        toFile.append(QString::number(acti->achievedGrade())+';');
        toFile.append(QString::number(acti->activityType())+";");
        toFile.append(acti->date().toString("dd.MM.yyyy")+';');
        toFile.append("not defined");
        toFile.append("}\n");
        disciFile.write(toFile);
        disciFile.flush();
        disciFile.close();
    }
}
