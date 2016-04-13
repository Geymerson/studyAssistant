#include "headers/activitylist.h"
#include "headers/activity.h"

ActivityList::ActivityList(QObject *parent)
    : QAbstractListModel(parent) {

    m_roleNames[NameRole] = "name";
    m_roleNames[DisciplineRole] = "discipline";
    m_roleNames[DateRole] = "date";
    m_roleNames[GradeRole] = "grade";
    m_roleNames[AchievedGradeRole] = "achievedGrade";
    m_roleNames[ActivityTypeRole] = "activityType";
}

ActivityList::~ActivityList() {
    m_data.clear();
}

void ActivityList::insert(int index, Activity* activity) {
    if(index < 0 || index > m_data.count()) {
        return;
    }

    emit beginInsertRows(QModelIndex(), index, index);
    m_data.insert(index, activity);
    emit endInsertRows();
    emit countChanged(m_data.count());
}

void ActivityList::append(Activity* activity) {
    insert(count(), activity);
}

void ActivityList::remove(int index) {
    if(index < 0 || index >= m_data.count()) {
        return;
    }
    emit beginRemoveRows(QModelIndex(), index, index);
    m_data.removeAt(index);
    emit endRemoveRows();
    emit countChanged(m_data.count());
}

void ActivityList::clear() {
    emit beginResetModel();
    m_data.clear();
    emit endResetModel();
}

Activity* ActivityList::get(int index) {
    if( index < 0 || index >= m_data.count() ) {
        return NULL;
    }
    return m_data.at(index);
}

int ActivityList::rowCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return m_data.count();
}

QVariant ActivityList::data(const QModelIndex &index, int role) const {
    int row = index.row();
    if(row < 0 || row >= m_data.count()) {
        return QVariant();
    }

    Activity* activity = m_data.at(row);

    switch(role) {

    case NameRole:
        // return activity's name as a string (model.name)
        return activity->name();

    case DisciplineRole:
        // return activity's discipline (model.discipline)
        return activity->discipline();

    case DateRole:
        // return activity's submission date
        return activity->date();

    case GradeRole:
        return activity->grade();

    case AchievedGradeRole:
        return activity->achievedGrade();

    case ActivityTypeRole:
        return activity->activityType();
    }
    return QVariant();

}

int ActivityList::count() const {
    return rowCount(QModelIndex());
}

QHash<int, QByteArray> ActivityList::roleNames() const {
    return m_roleNames;
}

void ActivityList::saveActivities() {
    foreach (Activity* acti, m_data) {
        QString disci = acti->discipline() + ".psa";
        if (QFile(disci).exists()) { //If this discipline exists
            QFile disciFile(disci);//Open discipline file
            if(!disciFile.open(QIODevice::Append)) {
                qDebug() << "Failed to open discipline file at loadList() method";
            }
            QByteArray toFile;
            toFile.append("{");
            toFile.append("name:"+acti->name()+';');
            toFile.append("grade:("+QString::number(acti->achievedGrade())+
                          ','+QString::number(acti->grade())+");");

            toFile.append("type:"+QString::number(acti->activityType())+";");
            toFile.append("date:"+acti->date().toString("dd.MM.yyyy")+';');
            toFile.append("discription:not defined");
            toFile.append("}\n");
            disciFile.write(toFile);
            disciFile.flush();
            disciFile.close();
        }
        else {
            qDebug() << "Discipline doesn't exist";
        }
    }
    emit activitiesSaved();
}

