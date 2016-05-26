#include "headers/classappointment.h"

ClassAppointment::ClassAppointment(QObject *parent) : QObject(parent) {

}

void ClassAppointment::setDay(int day) {
    if(day >= 1 && day <= 5) {
        m_day = day;
        emit dayChanged(day);
        return;
    }
    qDebug() << "invalid input, day must be between 1 and 5";
}

int ClassAppointment::day() const {
    return m_day;
}

void ClassAppointment::setStartsAt(const QTime &startTime) {
    if (startTime.isValid()) {
        m_startsAt = startTime;
        emit startsAtChanged(startTime);
        return;
    }
    qDebug() << "invalid start time";
}

QTime ClassAppointment::startsAt() const {
    return m_startsAt;
}

void ClassAppointment::setEndsAt(const QTime &endTime) {
    if (endTime.isValid() && endTime > m_startsAt) {
        m_endsAt = endTime;
        emit endsAtChanged(endTime);
        return;
    }
    qDebug() << "invalid end time";
}

QTime ClassAppointment::endsAt() const {
    return m_endsAt;
}

QString ClassAppointment::discipline() const {
    return m_discipline;
}

void ClassAppointment::setDiscipline(const QString &discipline) {
    if (discipline != "") {
        m_discipline = discipline;
    }
}
