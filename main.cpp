#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>

#include "headers/disciplinelist.h"
#include "headers/exerciselist.h"
#include "headers/testlist.h"
#include "headers/projectlist.h"
#include "headers/classappointment.h"
#include "headers/schedule.h"

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);

    qmlRegisterType<Activity> ("sa.project", 1, 0, "Activity");
    qmlRegisterType<ExerciseList> ("sa.project", 1, 0, "ExerciseList");
    qmlRegisterType<ProjectList> ("sa.project", 1, 0, "ProjectList");
    qmlRegisterType<TestList> ("sa.project", 1, 0, "TestList");
    qmlRegisterType<Discipline> ("sa.project", 1, 0, "Discipline");
    qmlRegisterType<DisciplineList> ("sa.project", 1, 0, "DisciplineList");
    qmlRegisterType<ClassAppointment> ("sa.project", 1, 0, "ClassAppointment");
    qmlRegisterType<Schedule> ("sa.project", 1, 0, "Schedule");


    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    //** ########################## Testing space ##########################**//

    //DataManager loadData(2);
    //loadData.loadData();
    //    ActivityList activityList(2);
    //    activityList.loadActivities();
    //    qDebug() << activityList.count();

    //    for(int i = 0; i < activityList.count(); i++) {
    //        qDebug() << activityList.get(i)->name();
    //    }

    //    DisciplineList disciList;

//    ExerciseList exeList;
//    for(int i = 0; i < exeList.count(); i++) {
//        qDebug() << exeList.get(i)->name();
//        qDebug() << exeList.get(i)->discipline();
//        qDebug() << exeList.get(i)->activityType();
//        qDebug() << exeList.get(i)->achievedGrade();
//        qDebug() << exeList.get(i)->date();
//    }

//    DataManager scheduleSaver;
//    scheduleSaver.saveScheduleList();

//    DataManager scheduleLoader;
//    scheduleLoader.loadSchedule();
//    qDebug() << scheduleLoader.getSchedule().length();
//    QList<ClassAppointment*> schedule = scheduleLoader.getSchedule();
//    foreach (ClassAppointment* aptr, schedule) {
//        qDebug() << aptr->discipline();
//        qDebug() << aptr->day();
//        qDebug() << aptr->startsAt().toString("hh:mm");
//        qDebug() << aptr->endsAt().toString("hh:mm");
//    }

//    Schedule sched;


    //** ###################################################################### **/
    return app.exec();
}
