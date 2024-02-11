QT       += core gui
QT += sql
QT += core gui charts
QT       += core gui sql
QT       += core gui charts
QT       += core gui sql
QT+= serialport
QT += printsupport
QT += network
QT += qml
QT       += core gui printsupport
QT       += location
QT       +=printsupport
QT       +=charts
QT       +=network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS
DEFINES += XLSX_NO_LIB



# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ajout.cpp \
    alerte.cpp \
    arduino.cpp \
    auditeur.cpp \
    client.cpp \
    connection.cpp \
    employe.cpp \
    formations.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    matriels.cpp \
    modify.cpp \
    penalite.cpp \
    qrcode.cpp \
    smtp.cpp \
    supprime.cpp

HEADERS += \
    ajout.h \
    alerte.h \
    arduino.h \
    auditeur.h \
    client.h \
    connection.h \
    employe.h \
    formations.h \
    login.h \
    mainwindow.h \
    matriels.h \
    modify.h \
    penalite.h \
    qrcode.h \
    smtp.h \
    supprime.h

FORMS += \
    STATS.ui \
    ajout.ui \
    alerte.ui \
    login.ui \
    mainwindow.ui \
    modify.ui \
    supprime.ui


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

include(C:/Users/Lenovo/Desktop/Esprit 2eme/QtXlsxWriter-master/src/xlsx/qtxlsx.pri)

RESOURCES += \
    rsrc.qrc \
    rsrc.qrc

DISTFILES += \
    CRUD.pro.user

