#-------------------------------------------------
#
# Project created by QtCreator 2018-10-28T13:04:56
#
#-------------------------------------------------

QT       += testlib xml xmlpatterns

QT       -= gui

TARGET = tst_testtest
CONFIG   += console
CONFIG   += c++11
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += tst_testtest.cpp \
    xmloutput.cpp \
    directoryhierarchy.cpp \
    ../../src/App/query.cpp \
    filetree.cpp

DEFINES += SRCDIR=\\\"$$PWD/\\\"

HEADERS += \
    xmloutput.h \
    directoryhierarchy.h \
    ../../src/App/query.h \
    filetree.h

DISTFILES +=

RESOURCES += \
    queries.qrc
