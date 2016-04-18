#include "../headers/disciplinelist.h"

DisciplineList::DisciplineList(QObject *parent)
    : QAbstractListModel(parent), DataManager() {

    m_roleNames[NameRole] = "name";
    m_roleNames[ProfessorRole] = "professor";
    m_roleNames[GradeRole] = "grade";
    loadDisciplines();
}

DisciplineList::~DisciplineList() {
    //m_data.clear();
}

void DisciplineList::insert(int index, Discipline* discipline) {
    if(index < 0 || index > m_data.count()) {
        return;
    }

    emit beginInsertRows(QModelIndex(), index, index);
    m_data.insert(index, discipline);
    emit endInsertRows();
    emit countChanged(m_data.count());
}

void DisciplineList::append(Discipline* discipline) {
    insert(count(), discipline);
}

void DisciplineList::remove(int index) {
    if(index < 0 || index >= m_data.count()) {
        return;
    }
    emit beginRemoveRows(QModelIndex(), index, index);
    QFile(get(index)->name() + ".sa").remove();
    m_data.removeAt(index);
    setDisciplineList(m_data);
    updateDisciplines();
    emit endRemoveRows();
    emit countChanged(m_data.count());
}

void DisciplineList::clear() {
    emit beginResetModel();
    m_data.clear();
    emit endResetModel();
}

Discipline* DisciplineList::get(int index) {
    if( index < 0 || index >= m_data.count() ) {
        return NULL;
    }
    return m_data.at(index);
}

void DisciplineList::updateDisciplines() {
    QMutexLocker locker(&m_mutex);
    updateDisciplineList();
}

int DisciplineList::length() const {
    return count();
}

void DisciplineList::saveDisciplines() {
    QMutexLocker locker(&m_mutex);
    setDisciplineList(m_data);
    saveDisciplineList();
    emit disciplinesSaved();
}

void DisciplineList::loadDisciplines() {
    QMutexLocker locker(&m_mutex);
    m_data = getDisciplineList();
    emit disciplinesLoaded();
}

int DisciplineList::rowCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return m_data.count();
}

QVariant DisciplineList::data(const QModelIndex &index, int role) const {
    int row = index.row();
    if(row < 0 || row >= m_data.count()) {
        return QVariant();
    }

    Discipline* discipline = m_data.at(row);

    switch(role) {

    case NameRole:
        // return discipline's name as a string (model.name)
        return discipline->name();

    case ProfessorRole:
        // return discipline's professor (model.professor)
        return discipline->professor();

    case GradeRole:
        // return discipline's grade (model.grade)
        return discipline->grade();
    }
    return QVariant();
}

int DisciplineList::count() const {
    return rowCount(QModelIndex());
}

QHash<int, QByteArray> DisciplineList::roleNames() const {
    return m_roleNames;
}
