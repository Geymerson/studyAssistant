#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>

#include "headers/discipline.h"
#include "headers/disciplinelist.h"
#include "headers/activity.h"
#include "headers/activitylist.h"


int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);

    qmlRegisterType<DisciplineList> ("psa.org", 1, 0, "DisciplineList");
    qmlRegisterType<Discipline> ("psa.org", 1, 0, "Discipline");
    qmlRegisterType<ActivityList> ("psa.org", 1, 0, "ActivityList");
    qmlRegisterType<Activity> ("psa.org", 1, 0, "Activity");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
