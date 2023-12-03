QT       += core gui
QT += sql

LIBS += -L/usr/lib/x86_64-linux-gnu/qt5/plugins/sqldrivers -lqsqlpsql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++20

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    authentification/login.cpp \
    base/main.cpp \
    base/mainwindow.cpp \
    base/order.cpp \
    base/user.cpp \
    databaseStuff/sqlservice.cpp \
    selecting/drinktypewidget.cpp \
    selecting/orderswidget.cpp \
    selecting/rootwidget.cpp

HEADERS += \
    authentification/login.h \
    base/mainwindow.h \
    base/order.h \
    base/user.h \
    databaseStuff/configuratedatabase.h \
    databaseStuff/sqlservice.h \
    selecting/drinktypewidget.h \
    selecting/orderswidget.h \
    selecting/rootwidget.h

FORMS += \
    authentification/login.ui \
    base/mainwindow.ui \
    selecting/drinktypewidget.ui \
    selecting/orderswidget.ui \
    selecting/rootwidget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
