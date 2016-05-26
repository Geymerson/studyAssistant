#ifndef CLASSAPPOINTMENT_H
#define CLASSAPPOINTMENT_H

#include <QObject>
#include <QDebug>
#include <QTime>

class ClassAppointment : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int day READ day WRITE setDay)
    Q_PROPERTY(QTime startsAt READ startsAt WRITE setStartsAt NOTIFY startsAtChanged)
    Q_PROPERTY(QTime endsAt READ endsAt WRITE setEndsAt NOTIFY endsAtChanged)
    Q_PROPERTY(QString discipline READ discipline WRITE setDiscipline NOTIFY disciplineChanged)

public:
    explicit ClassAppointment(QObject *parent = 0);

    /** Set class day **/
    void setDay(int day);

    /** Return: A int representing the class day class day**/
    int day() const;

    /** Set class initial time **/
    void setStartsAt(const QTime &time);

    /** Return: Class initial time **/
    QTime startsAt() const;

    /** Set class ending time **/
    void setEndsAt(const QTime &time);

    /** Return: Class ending time **/
    QTime endsAt() const;

    /** Return: appointment discipline name **/
    QString discipline() const;

    /** Set appointment discipline name **/
    void setDiscipline(const QString &discipline);

private:

    /** A integer between 1 and 5 representing a week day (monday ~ friday) **/
    int m_day;

    /** Class starting time **/
    QTime m_startsAt;

    /** Class ending time **/
    QTime m_endsAt;

    /** Appointment discipline **/
    QString m_discipline;

signals:
    void dayChanged(int day);
    void startsAtChanged(const QTime &time);
    void endsAtChanged(const QTime &time);
    void disciplineChanged(const QString& discipline);
public slots:

};

#endif // CLASSAPPOINTMENT_H
