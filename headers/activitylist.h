#ifndef ACTIVITYLIST
#define ACTIVITYLIST

#include <QList>
#include "activity.h"
#include <QAbstractListModel>
#include <QFile>
#include <QDebug>

class ActivityList: public QAbstractListModel {
    Q_OBJECT
    Q_PROPERTY(int count READ count NOTIFY countChanged)
public:
    enum ActivityFields {
        NameRole = Qt::UserRole,
        DisciplineRole = Qt::UserRole+2,
        DateRole = Qt::UserRole+3,
        GradeRole = Qt::UserRole+4,
        AchievedGradeRole = Qt::UserRole+5,
        ActivityTypeRole = Qt::UserRole+6
    };

    explicit ActivityList(QObject *parent = 0);
    ~ActivityList();

    Q_INVOKABLE void insert(int index, Activity* activity);
    Q_INVOKABLE void append(Activity* activity);
    Q_INVOKABLE void remove(int index);
    Q_INVOKABLE void clear();
    Q_INVOKABLE Activity* get(int index);
    Q_INVOKABLE void saveActivities();

public: // interface QAbstractListModel
    virtual int rowCount(const QModelIndex &parent) const;
    virtual QVariant data(const QModelIndex &index, int role) const;
    int count() const;

signals:
    void countChanged(int arg);
    void activitiesSaved();

protected: // interface QAbstractListModel
    virtual QHash<int, QByteArray> roleNames() const;

public slots:

private:
    QList<Activity*> m_data;
    QHash<int, QByteArray> m_roleNames;
    int m_count;
};

#endif // ACTIVITYLIST

