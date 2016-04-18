#include "../headers/testlist.h"

TestList::TestList(QObject *parent) : QAbstractListModel(parent), DataManager(1) {
    m_roleNames[NameRole] = "name";
    m_roleNames[DisciplineRole] = "discipline";
    m_roleNames[DateRole] = "date";
    m_roleNames[GradeRole] = "grade";
    m_roleNames[AchievedGradeRole] = "achievedGrade";
    m_roleNames[ActivityTypeRole] = "activityType";
    loadActivities();
}

TestList::~TestList() {
    m_data.clear();
}

void TestList::insert(int index, Activity* activity) {
    if(index < 0 || index > m_data.count()) {
        return;
    }

    emit beginInsertRows(QModelIndex(), index, index);
    m_data.insert(index, activity);
    emit endInsertRows();
    emit countChanged(m_data.count());
}

void TestList::append(Activity* activity) {
    insert(count(), activity);
}

void TestList::remove(int index) {
    if(index < 0 || index >= m_data.count()) {
        return;
    }
    emit beginRemoveRows(QModelIndex(), index, index);
    m_data.removeAt(index);
    emit endRemoveRows();
    emit countChanged(m_data.count());
}

void TestList::clear() {
    emit beginResetModel();
    m_data.clear();
    emit endResetModel();
}

Activity* TestList::get(int index) {
    if( index < 0 || index >= m_data.count() ) {
        return NULL;
    }
    return m_data.at(index);
}

int TestList::rowCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return m_data.count();
}

QVariant TestList::data(const QModelIndex &index, int role) const {
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

int TestList::count() const {
    return rowCount(QModelIndex());
}

QHash<int, QByteArray> TestList::roleNames() const {
    return m_roleNames;
}

void TestList::saveActivities() {
    QMutexLocker locker(&m_mutex);
    setActivityList(m_data);
    saveActivityList();
    emit activitiesSaved();
}

void TestList::loadActivities() {
    QMutexLocker locker(&m_mutex);
    m_data = getActivityList();
    emit activitiesLoaded();
}
