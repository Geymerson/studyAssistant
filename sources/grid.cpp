#include "headers/grid.h"
#include "headers/discipline.h"

Grid::Grid(QObject *parent)
    : QAbstractListModel(parent) {

    m_disciplineFields[NameRole] = "name";
    m_disciplineFields[ProfessorRole] = "professor";

}

Grid::~Grid() {
    m_data.clear();
}

void Grid::insert(int index, Discipline* discipline) {
    if(index < 0 || index > m_data.count()) {
        return;
    }

    emit beginInsertRows(QModelIndex(), index, index);
    m_data.insert(index, discipline);
    emit endInsertRows();
    emit countChanged(m_data.count());
}

void Grid::append(Discipline* discipline) {
    insert(count(), discipline);
}

void Grid::remove(int index) {
    if(index < 0 || index >= m_data.count()) {
        return;
    }
    emit beginRemoveRows(QModelIndex(), index, index);
    m_data.removeAt(index);
    emit endRemoveRows();
    emit countChanged(m_data.count());
}

void Grid::clear() {
    emit beginResetModel();
    m_data.clear();
    emit endResetModel();
}

Discipline* Grid::get(int index) {
    if( index < 0 || index >= m_data.count() ) {
        return NULL;
    }
    return m_data.at(index);
}

int Grid::rowCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return m_data.count();
}

QVariant Grid::data(const QModelIndex &index, int role) const {
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
    }
    return QVariant();
}

int Grid::count() const {
    return rowCount(QModelIndex());
}

QHash<int, QByteArray> Grid::disciplineFields() const {
    return m_disciplineFields;
}
