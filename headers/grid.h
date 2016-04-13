#ifndef GRID_H
#define GRID_H

#include <QList>
#include "discipline.h"
#include <QAbstractListModel>

class Grid: public QAbstractListModel {
    Q_OBJECT
    Q_PROPERTY(int count READ count NOTIFY countChanged)
public:
    enum DisciplineFields {
        NameRole = Qt::UserRole,
        ProfessorRole = Qt::UserRole+2,
//        Sensirion_humRole = Qt::UserRole+3,
//        Intersema_tempRole = Qt::UserRole+4,
//        Intersema_pressRole = Qt::UserRole+5,
//        Infrared_lightRole = Qt::UserRole+6,
//        LightRole = Qt::UserRole+7,
//        Accel_xRole = Qt::UserRole+8,
//        Accel_yRole = Qt::UserRole+9,
//        VoltageRole = Qt::UserRole+10,
//        StateRole = Qt::UserRole+11,
//        CityRole = Qt::UserRole+12,
//        LatitudeRole = Qt::UserRole+13,
//        LongitudeRole = Qt::UserRole+14,
//        DateRole = Qt::UserRole+15
    };

    explicit Grid(QObject *parent = 0);
    ~Grid();

    void insert(int index, Discipline* discipline);
    void append(Discipline* discipline);
    void remove(int index);
    void clear();
    Q_INVOKABLE Discipline* get(int index);

public: // interface QAbstractListModel
    virtual int rowCount(const QModelIndex &parent) const;
    virtual QVariant data(const QModelIndex &index, int role) const;
    int count() const;

signals:
    void countChanged(int arg);

protected: // interface QAbstractListModel
    virtual QHash<int, QByteArray> disciplineFields() const;

public slots:
    //void requestFinished(QNetworkReply *request);

private:
    QList<Discipline*> m_data;
    QHash<int, QByteArray> m_disciplineFields;
    int m_count;
    //QNetworkAccessManager *manager;
};
#endif // GRID_H
