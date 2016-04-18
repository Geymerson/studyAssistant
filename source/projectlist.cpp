#include "../headers/projectlist.h"

ProjectList::ProjectList(QObject *parent) : QAbstractListModel(parent), DataManager(3) {
    m_roleNames[NameRole] = "name";
    m_roleNames[DisciplineRole] = "discipline";
    m_roleNames[DateRole] = "date";
    m_roleNames[GradeRole] = "grade";
    m_roleNames[AchievedGradeRole] = "achievedGrade";
    m_roleNames[ActivityTypeRole] = "activityType";
    loadActivities();
}

ProjectList::~ProjectList() {
    m_data.clear();
}

void ProjectList::insert(int index, Activity* activity) {
    if(index < 0 || index > m_data.count()) {
        return;
    }

    emit beginInsertRows(QModelIndex(), index, index);
    m_data.insert(index, activity);
    emit endInsertRows();
    emit countChanged(m_data.count());
}

void ProjectList::append(Activity* activity) {
    insert(count(), activity);
}

void ProjectList::remove(int index) {
    if(index < 0 || index >= m_data.count()) {
        return;
    }
    emit beginRemoveRows(QModelIndex(), index, index);
    m_data.removeAt(index);
    //setActivityList(m_data);
    emit endRemoveRows();
    emit countChanged(m_data.count());
}

void ProjectList::clear() {
    emit beginResetModel();
    m_data.clear();
    //setActivityList(m_data);
    emit endResetModel();
}

Activity* ProjectList::get(int index) {
    if( index < 0 || index >= m_data.count() ) {
        return NULL;
    }
    return m_data.at(index);
}

int ProjectList::rowCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return m_data.count();
}

QVariant ProjectList::data(const QModelIndex &index, int role) const {
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

int ProjectList::count() const {
    return rowCount(QModelIndex());
}

QHash<int, QByteArray> ProjectList::roleNames() const {
    return m_roleNames;
}

void ProjectList::saveActivities() {
    QMutexLocker locker(&m_mutex);
    setActivityList(m_data);
    saveActivityList();
    emit activitiesSaved();
}

void ProjectList::loadActivities() {
    QMutexLocker locker(&m_mutex);
    m_data = getActivityList();
    emit activitiesLoaded();
}
