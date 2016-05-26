#include "../headers/discipline.h"

Discipline::Discipline(QObject *parent) : QObject(parent) {
    QQmlEngine::setObjectOwnership(this, QQmlEngine::CppOwnership);
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
