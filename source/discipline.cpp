#include "../headers/discipline.h"

Discipline::Discipline(QObject *parent) : QObject(parent) {
    m_grade = 0;
}

QString Discipline::name() const {
    return m_name;
}

void Discipline::setName(const QString &name) {
    m_name = name;
}

QString Discipline::professor() const {
    return m_professor;
}

void Discipline::setProfessor(const QString &professor) {
    m_professor = professor;
}

float Discipline::grade() const {
    return m_grade;
}

void Discipline::setGrade(float grade) {
    m_grade = grade;
}

void Discipline::insertClassTime(int index, QTime* time) {
    if(index < 0 || index > m_classSchedule.length()) {
        return;
    }
    m_classSchedule.insert(index, time);
}

void Discipline::appendClassTime(QTime* time) {
    insertClassTime(m_classSchedule.length(), time);
}

void Discipline::removeClassTime(int index) {
    if(index < 0 || index >= m_classSchedule.length()) {
        return;
    }
    m_classSchedule.removeAt(index);
}

void Discipline::clearSchedule() {
    m_classSchedule.clear();
}

QTime* Discipline::getClassTime(int index) {
    if( index < 0 || index >= m_classSchedule.length() ) {
        return NULL;
    }
    return m_classSchedule.at(index);
}

int Discipline::scheduleLength() {
    return m_classSchedule.length();
}
