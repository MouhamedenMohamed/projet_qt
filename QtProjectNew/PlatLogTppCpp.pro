QT       += core gui
QT       += xml
QT       += sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    adminadduser.cpp \
    admininterface.cpp \
    main.cpp \
    mainwindow.cpp \
    profil.cpp \
    userinterface.cpp \
    usersmanagement.cpp


HEADERS += \
    adminadduser.h \
    admininterface.h \
    mainwindow.h \
    profil.h \
    userinterface.h \
    usersmanagement.h


FORMS += \
    adminadduser.ui \
    admininterface.ui \
    mainwindow.ui \
    profil.ui \
    userinterface.ui \
    usersmanagement.ui


TRANSLATIONS += \
    PlatLogTppCpp_fr_FR.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
