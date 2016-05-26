#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include <QFile>
#include <QDebug>
#include "activity.h"
#include "discipline.h"
#include "classappointment.h"

class DataManager
{
public:
    DataManager();
    DataManager(int loadType);
    void clear();

    QList<Discipline *> getDisciplineList();
    void setDisciplineList(const QList<Discipline *> &disciplineList);
    void appendDisciplineList(const QList<Discipline *> &list);
    void loadDisciplineList();
    void saveDisciplineList();
    void updateDisciplineList();

    QList<Activity *> getActivityList();
    void setActivityList(const QList<Activity *> &activityList);
    void appendActivityList(const QList<Activity *> &list);
    void loadActivityList();
    void saveActivityList();

    QList<ClassAppointment *> getScheduleList();
    void setScheduleList(const QList<ClassAppointment *> &schedule);
    void appendScheduleList(const QList<ClassAppointment *> &list);
    void loadScheduleList();
    void saveScheduleList();

    int getLoadType() const;
    void setLoadType(int loadType);

private:
    QList<Discipline *> m_disciplineList;
    QList<Activity *> m_activityList;
    QList<ClassAppointment *> m_classesSchedule;
    int m_loadType;
};

#endif // DATAMANAGER_H
