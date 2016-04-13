TEMPLATE = app

QT += qml quick
CONFIG += c++11

SOURCES += main.cpp \
    sources/activity.cpp \
    sources/discipline.cpp \
    sources/disciplinelist.cpp \
    sources/activitylist.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    headers/discipline.h \
    headers/disciplinelist.h \
    headers/activitylist.h \
    headers/activity.h

