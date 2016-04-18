#ifndef DISCIPLINELIST_H
#define DISCIPLINELIST_H

#include <QObject>
#include <QList>
#include <QDebug>
#include <QMutex>
#include <QAbstractListModel>
#include "datamanager.h"

class DisciplineList: public QAbstractListModel, DataManager {
    Q_OBJECT
    Q_PROPERTY(int count READ count NOTIFY countChanged)
public:
    enum DisciplineFields {
        NameRole = Qt::UserRole,
        ProfessorRole = Qt::UserRole+2,
        GradeRole = Qt::UserRole+3,
    };

    explicit DisciplineList(QObject *parent = 0);
    ~DisciplineList();

    /** ### Insert discipline at index ### **/
    Q_INVOKABLE void insert(int index, Discipline* discipline);

    /** ### Insert at list's end ### **/
    Q_INVOKABLE void append(Discipline* discipline);

    /** ### Remove discipline at index ### **/
    Q_INVOKABLE void remove(int index);

    /** ### Clear discipline list ### **/
    Q_INVOKABLE void clear();

    /** ### Get discipline at index ### **/
    Q_INVOKABLE Discipline* get(int index);

    /** ### Save discipline list to files ### **/
    Q_INVOKABLE void saveDisciplines();

    /** ### Load discipline list from app's files ### **/
    Q_INVOKABLE void loadDisciplines();

    /** ### Update discipline list file ### **/
    Q_INVOKABLE void updateDisciplines();

    /** Return list length**/
    Q_INVOKABLE int length();

public: // interface QAbstractListModel
    virtual int rowCount(const QModelIndex &parent) const;
    virtual QVariant data(const QModelIndex &index, int role) const;
    int count() const;

signals:
    void countChanged(int arg);
    void disciplinesSaved();
    void disciplinesLoaded();

protected: // interface QAbstractListModel
    virtual QHash<int, QByteArray> roleNames() const;

public slots:

private:
    QList<Discipline*> m_data;
    QHash<int, QByteArray> m_roleNames;
    int m_count;
    mutable QMutex m_mutex; //to thread safety
};

#endif // DISCIPLINELIST_H
