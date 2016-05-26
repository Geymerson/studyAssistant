#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <QObject>
#include <QMutex>
#include <QQmlEngine>
#include "../headers/classappointment.h"
#include "../headers/datamanager.h"

class Schedule : public QObject, DataManager
{
    Q_OBJECT
public:
    explicit Schedule(QObject *parent = 0);

    QList<ClassAppointment *> getSchedule();
    Q_INVOKABLE void insertClassAppointment(int index, ClassAppointment* time);
    Q_INVOKABLE void appendClassAppointment(ClassAppointment* time);
    Q_INVOKABLE void removeClassAppointment(int index);
    Q_INVOKABLE void clearSchedule();
    Q_INVOKABLE ClassAppointment* getClassAppointment(int index);
    Q_INVOKABLE int length();
    Q_INVOKABLE void saveSchedule();
    Q_INVOKABLE void loadSchedule();

private:
    QList<ClassAppointment *> m_classesSchedule;
    mutable QMutex m_mutex; //to thread safety
signals:

public slots:
};

#endif // SCHEDULE_H
