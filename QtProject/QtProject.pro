#-------------------------------------------------
#
# Project created by QtCreator 2019-02-09T11:50:14
#
#-------------------------------------------------

QT       += core gui
QT += sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtProject
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    login.cpp \
    ajoutpatient.cpp \
    ajoutpersonnel.cpp \
    apropos.cpp \
    calendrier.cpp \
    modeltablepatient.cpp \
    patient.cpp \
    personnel.cpp \
    modeltreepersonnel.cpp \
    c_init_bd.cpp \
    requetebd.cpp \
    consult.cpp \
    supprimerpatient.cpp \
    modifierpatient.cpp \
    compte.cpp \
    supprimerpersonnel.cpp \
    modifierpersonnel.cpp

HEADERS += \
        mainwindow.h \
    login.h \
    ajoutpatient.h \
    ajoutpersonnel.h \
    apropos.h \
    calendrier.h \
    modeltablepatient.h \
    patient.h \
    personnel.h \
    modeltreepersonnel.h \
    c_init_bd.h \
    requetebd.h \
    consult.h \
    supprimerpatient.h \
    modifierpatient.h \
    compte.h \
    supprimerpersonnel.h \
    modifierpersonnel.h

FORMS += \
        mainwindow.ui \
    login.ui \
    ajoutpatient.ui \
    ajoutpersonnel.ui \
    apropos.ui \
    calendrier.ui \
    supprimerpatient.ui \
    modifierpatient.ui \
    supprimerpersonnel.ui \
    modifierpersonnel.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ressources/ressources.qrc

DISTFILES +=
