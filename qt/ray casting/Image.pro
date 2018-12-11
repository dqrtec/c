#-------------------------------------------------
#
# Project created by QtCreator 2018-09-26T22:32:10
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Image
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    esfera.cpp \
    material.cpp \
    color.cpp \
    camera.cpp \
    vetor.cpp \
    cena.cpp

HEADERS  += mainwindow.h \
    esfera.h \
    ray.h \
    intersection.h \
    material.h \
    color.h \
    camera.h \
    ponto.h \
    cena.h \
    vetor.h

FORMS    += mainwindow.ui
