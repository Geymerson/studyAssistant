#include "../headers/schedule.h"

Schedule::Schedule(QObject *parent) : QObject(parent), DataManager() {
    QQmlEngine::setObjectOwnership(this, QQmlEngine::CppOwnership);
    m_classesSchedule = getScheduleList();
    //    qDebug() << m_classesSchedule.length();
}

QList<ClassAppointment *> Schedule::getSchedule() {
    return m_classesSchedule;
}

void Schedule::insertClassAppointment(int index, ClassAppointment* appointment) {
    if(index < 0 || index > m_classesSchedule.length()) {
        return;
    }
    m_classesSchedule.insert(index, appointment);
}

void Schedule::appendClassAppointment(ClassAppointment* appointment) {
    insertClassAppointment(m_classesSchedule.length(), appointment);
}

void Schedule::removeClassAppointment(int index) {
    if(index < 0 || index >= m_classesSchedule.length()) {
        return;
    }
    m_classesSchedule.removeAt(index);
}

void Schedule::clearSchedule() {
    m_classesSchedule.clear();
}

ClassAppointment* Schedule::getClassAppointment(int index) {
    if( index < 0 || index >= m_classesSchedule.length() ) {
        return NULL;
    }
    return m_classesSchedule.at(index);
}

int Schedule::length() {
    return m_classesSchedule.length();
}

void Schedule::saveSchedule() {
    QMutexLocker locker(&m_mutex);
    saveScheduleList();
}

void Schedule::loadSchedule() {
    QMutexLocker locker(&m_mutex);
    loadScheduleList();
}
