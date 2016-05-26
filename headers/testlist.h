#ifndef TESTLIST_H
#define TESTLIST_H

#include <QObject>
#include <QList>
#include <QDebug>
#include <QMutex>
#include <QAbstractListModel>
#include "datamanager.h"

class TestList : public QAbstractListModel, DataManager
{
    Q_OBJECT
    Q_PROPERTY(int count READ count NOTIFY countChanged)
    enum TestRoles {
        NameRole = Qt::UserRole,
        DisciplineRole = Qt::UserRole+2,
        DateRole = Qt::UserRole+3,
        GradeRole = Qt::UserRole+4,
        AchievedGradeRole = Qt::UserRole+5,
        ActivityTypeRole = Qt::UserRole+6
    };
public:
    explicit TestList(QObject *parent = 0);
    ~TestList();
    Q_INVOKABLE void insert(int index, Activity* activity);
    Q_INVOKABLE void append(Activity* activity);
    Q_INVOKABLE void remove(int index);
    Q_INVOKABLE void clear();
    Q_INVOKABLE Activity* get(int index);
    Q_INVOKABLE void saveActivities();
    Q_INVOKABLE void loadActivities();
    Q_INVOKABLE int length() const;

public:
    virtual int rowCount(const QModelIndex &parent) const;
    virtual QVariant data(const QModelIndex &index, int role) const;
    int count() const;

signals:
    void countChanged(int arg);
    void activitiesSaved();
    void activitiesLoaded();

protected:
    virtual QHash<int, QByteArray> roleNames() const;

private:
    QList<Activity*> m_data;
    QHash<int, QByteArray> m_roleNames;
    int m_count;
    mutable QMutex m_mutex; //to thread safety
};


#endif // TESTLIST_H
