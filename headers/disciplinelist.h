#ifndef DISCIPLINELIST_H
#define DISCIPLINELIST_H

#include "discipline.h"
#include <QList>
#include <QFile>
#include <QAbstractListModel>

class DisciplineList: public QAbstractListModel {
    Q_OBJECT
    Q_PROPERTY(int count READ count NOTIFY countChanged)
public:
    enum DisciplineFields {
        NameRole = Qt::UserRole,
        ProfessorRole = Qt::UserRole+2,
        GradeRole = Qt::UserRole+3,
    };

    explicit DisciplineList(QObject *parent = 0);
    ~DisciplineList();

    /** ### Insert discipline at index ### **/
    Q_INVOKABLE void insert(int index, Discipline* discipline);

    /** ### Insert at list's end ### **/
    Q_INVOKABLE void append(Discipline* discipline);

    /** ### Remove discipline at index ### **/
    Q_INVOKABLE void remove(int index);

    /** ### Clear discipline list ### **/
    Q_INVOKABLE void clear();

    /** ### Get discipline at index ### **/
    Q_INVOKABLE Discipline* get(int index);

    /** ### Save discipline list to files ### **/
    Q_INVOKABLE void saveList();

    /** ### Load discipline list from app's files ### **/
    Q_INVOKABLE void loadList();

    /** ### Update discipline list file ### **/
    Q_INVOKABLE void updateList();

    /** Return list length**/
    Q_INVOKABLE int length();

public: // interface QAbstractListModel
    virtual int rowCount(const QModelIndex &parent) const;
    virtual QVariant data(const QModelIndex &index, int role) const;
    int count() const;

signals:
    void countChanged(int arg);
    void disciplinesSaved();
    void disciplinesLoaded();

protected: // interface QAbstractListModel
    virtual QHash<int, QByteArray> roleNames() const;

public slots:

private:
    QList<Discipline*> m_data;
    QHash<int, QByteArray> m_roleNames;
    int m_count;
};

#endif // DISCIPLINELIST_H
