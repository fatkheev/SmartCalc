QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../func/stack.c \
    ../func/validator.c \
    creditcalculatorwindow.cpp \
    main.cpp \
    mainwindow.cpp \
    qcustomplot.cpp \
    style.cpp
    style.qss
    qcustomplot.cpp

QT += \
    printsupport

HEADERS += \
    ../creditcalculatorwindow.h \
    creditcalculatorwindow.h \
    mainwindow.h \
    qcustomplot.h \
    style.h
    qcustomplot.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    cat.gif \
    style/styles.qss

RESOURCES += \
    res.qrc
