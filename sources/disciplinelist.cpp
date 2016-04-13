#include "headers/disciplinelist.h"
#include "headers/discipline.h"

#include <QDebug>

DisciplineList::DisciplineList(QObject *parent)
    : QAbstractListModel(parent) {

    m_roleNames[NameRole] = "name";
    m_roleNames[ProfessorRole] = "professor";
    m_roleNames[GradeRole] = "grade";
}

DisciplineList::~DisciplineList() {
    m_data.clear();
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
    QFile(get(index)->name() + ".psa").remove();
    m_data.removeAt(index);
    updateList();
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

void DisciplineList::updateList() {
    QByteArray toFile;
    QFile disciList("disciplineList.psa");
    if(!disciList.open(QIODevice::WriteOnly)) {
        qDebug() << " Could not open the file, update failed.";
        return;
    }
    foreach (Discipline *disci, m_data) {
        toFile.append(disci->name())
                .append('\n');
    }
    disciList.write(toFile);
    disciList.flush();
    disciList.close();
}

int DisciplineList::length() {
    return count();
}

void DisciplineList::saveList() {
    //Update list before saving data
    updateList();

    foreach(Discipline *disci, m_data) {
        QString filePath(disci->name()+".psa");
        QFile file(filePath);
        QByteArray toFile;

        if(!file.open(QIODevice::WriteOnly)) {
            qDebug() << " Could not open the file, save failed";
            return;
        }
        toFile.append("professor:" + disci->professor())
                .append('\n');
        toFile.append("discipline_grade:" + QString::number(disci->grade()))
                .append('\n');
        toFile.append("activities:\n");
        file.write(toFile);
        file.flush();
        file.close();
    }
    emit disciplinesSaved();
}

void DisciplineList::loadList() {
    QFile disciList("disciplineList.psa");

    if(!disciList.open(QIODevice::ReadOnly)) {
        qDebug() << "Could not open the file, load failed.";
        return;
    }

    //### Read discipline information ###
    QString disci;
    while(!disciList.atEnd()) {
        disci = disciList.readLine(); //Get discipline name
        disci = disci.left(disci.length() - 1); //Removing \n character
        QFile disciFile(disci + ".psa");//Open discipline file
        if(!disciFile.open(QIODevice::ReadOnly)) {
            qDebug() << "Failed to open discipline file at loadList() method";
        }
        //Read professor name and discipline grade
        Discipline *discipline = new Discipline();
        QString line;
        discipline->setName(disci);//Setting name
        line = disciFile.readLine();//Get professor
        discipline->setProfessor(line.right(line.length() - 10));//Setting professor
        line = disciFile.readLine();//Get grade
        discipline->setGrade(line.right(line.length() - 17).toFloat());//Setting grade
        append(discipline);//Insert discipline in the list
        disciFile.close();
    }
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
