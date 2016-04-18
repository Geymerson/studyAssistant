#ifndef DISCIPLINE_H
#define DISCIPLINE_H

#include <QObject>

class Discipline : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString name READ name WRITE setName)
    Q_PROPERTY(QString professor READ professor WRITE setProfessor)

public:
    explicit Discipline(QObject *parent = 0);

    QString name() const;
    void setName(const QString &name);

    QString professor() const;
    void setProfessor(const QString &professor);

    float grade() const;
    void setGrade(float overallGrade);

private:
    QString m_name;
    QString m_professor;
    float m_grade;

signals:

public slots:
};

#endif // DISCIPLINE_H
