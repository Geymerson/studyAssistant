#ifndef ACTIVITY_H
#define ACTIVITY_H

#include <QObject>
#include <QString>
#include <QDate>

class Activity : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString discipline READ discipline WRITE setDiscipline NOTIFY disciplineChanged)
    Q_PROPERTY(QDate date READ date WRITE setDate NOTIFY dateChanged)
    Q_PROPERTY(float grade READ grade WRITE setGrade NOTIFY gradeChanged)
    Q_PROPERTY(float achievedGrade READ achievedGrade WRITE setAchievedGrade NOTIFY achievedGradeChanged)
    Q_PROPERTY(int activityType READ activityType WRITE setActivityType NOTIFY activityTypeChanged)

public:
    explicit Activity(QObject *parent = 0);

    QString name() const;
    void setName(const QString &name);

    QString discipline() const;
    void setDiscipline(const QString &discipline);

    QDate date() const;
    void setDate(const QDate &date);

    float grade() const;
    void setGrade(float grade);

    float achievedGrade() const;
    void setAchievedGrade(float achievedGrade);

    int activityType() const;
    void setActivityType(int value);

private:

    //Activity name
    QString m_name;

    //Discipline name
    QString m_discipline;

    //Submission date
    QDate m_date;

    //Activity grade
    float m_grade;

    //Achieved grade
    float m_achievedGrade;

    //Activity type: test = 1, exercise = 2, project = 3
    int m_activityType;

signals:
    void nameChanged(QString arg);
    void disciplineChanged(QString arg);
    void dateChanged(QDate arg);
    void gradeChanged(float arg);
    void achievedGradeChanged(float arg);
    void activityTypeChanged(int arg);

public slots:
};

#endif // ACTIVITY_H
