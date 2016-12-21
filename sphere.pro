#-------------------------------------------------
#
# Project created by QtCreator 2013-10-16T17:37:54
#
#-------------------------------------------------

QT       += core gui opengl

TARGET = sphere
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    unitsphere.cpp \
    mywidget.cpp

HEADERS  += mainwindow.h \
    unitsphere.h \
    mywidget.h

FORMS    += mainwindow.ui

OTHER_FILES += \
    fragshader.frag \
    vexshader.vert
