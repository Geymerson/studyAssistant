#include "headers/activity.h"

Activity::Activity(QObject *parent) : QObject(parent) {
    QQmlEngine::setObjectOwnership(this, QQmlEngine::CppOwnership);
}

QString Activity::name() const {
    return m_name;
}

void Activity::setName(const QString &name) {
    m_name = name;
}

QString Activity::discipline() const {
    return m_discipline;
}

void Activity::setDiscipline(const QString &discipline) {
    m_discipline = discipline;
}

QDate Activity::date() const {
    return m_date;
}

void Activity::setDate(const QDate &date) {
    m_date = date;
}

float Activity::grade() const {
    return m_grade;
}

void Activity::setGrade(float grade) {
    m_grade = grade;
}

float Activity::achievedGrade() const {
    return m_achievedGrade;
}

void Activity::setAchievedGrade(float achievedGrade) {
    m_achievedGrade = achievedGrade;
}

int Activity::activityType() const {
    return m_activityType;
}

void Activity::setActivityType(int value) {
    m_activityType = value;
}
