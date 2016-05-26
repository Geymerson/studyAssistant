TEMPLATE = app

QT += qml quick
CONFIG += c++11

SOURCES += main.cpp \
    source/datamanager.cpp \
    source/disciplinelist.cpp \
    source/discipline.cpp \
    source/exerciselist.cpp \
    source/activity.cpp \
    source/testlist.cpp \
    source/projectlist.cpp \
    source/classappointment.cpp \
    source/schedule.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    headers/datamanager.h \
    headers/disciplinelist.h \
    headers/discipline.h \
    headers/exerciselist.h \
    headers/activity.h \
    headers/testlist.h \
    headers/projectlist.h \
    headers/classappointment.h \
    headers/schedule.h
