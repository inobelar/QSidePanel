#-------------------------------------------------
#
# Project created by QtCreator 2019-08-15T16:32:12
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = q_side_panel_proj
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

contains(CONFIG, BOARD_QT_FIX) {
    message("Platform: Board Mon700: Applied patch - changed GCC path (for Qt from repository)")

    # ---------------------------------
    QMAKE_CC         = /usr/bin/gcc-4.9
    QMAKE_CXX        = /usr/bin/g++-4.9
    QMAKE_LINK       = /usr/bin/g++-4.9
    QMAKE_LINK_SHLIB = /usr/bin/g++-4.9

   #QMAKE_AR         = /usr/bin/ar
    QMAKE_OBJCOPY    = /usr/bin/objcopy
    QMAKE_STRIP      = /usr/bin/strip
    # ---------------------------------

    # Path for libGAL (dependency for libGLESv2)
    LIBS += -L/usr/lib/arm-linux-gnueabihf/vivante/x11 -lGAL
}


CONFIG += c++11

include($${PWD}/QSidePanel/q_side_panel.pri)

SOURCES += \
        MainWindow.cpp \
        main.cpp \

HEADERS += \
        MainWindow.hpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
