#ifndef DISCIPLINE_H
#define DISCIPLINE_H

#include <QObject>
#include <QTime>

class Discipline : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString name READ name WRITE setName)
    Q_PROPERTY(QString professor READ professor WRITE setProfessor)
//    Q_PROPERTY(QList<QTime*> classSchedule READ classSchedule WRITE setClassSchedule NOTIFY classScheduleChanged)

public:
    explicit Discipline(QObject *parent = 0);

    QString name() const;
    void setName(const QString &name);

    QString professor() const;
    void setProfessor(const QString &professor);

    float grade() const;
    void setGrade(float overalGrade);

    Q_INVOKABLE void insertClassTime(int index, QTime* time);
    Q_INVOKABLE void appendClassTime(QTime* time);
    Q_INVOKABLE void removeClassTime(int index);
    Q_INVOKABLE void clearSchedule();
    Q_INVOKABLE QTime* getClassTime(int index);
    Q_INVOKABLE int scheduleLength();

private:
    QString m_name;
    QString m_professor;
    QList<QTime*> m_classSchedule;
    float m_grade;
signals:

public slots:

};

#endif // DISCIPLINE_H
