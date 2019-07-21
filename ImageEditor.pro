#-------------------------------------------------
#
# Project created by QtCreator 2019-06-23T16:11:52
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ImageEditor
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
    core/xyfuncpanelwidget.cpp \
    core/xyfuncplugin.cpp \
    core/xyfuncproxywidget.cpp \
    core/xyfuncsbox.cpp \
    core/xyimageviewer.cpp \
    core/xyexpansionsbox.cpp \
    core/xystoragebox.cpp \
    core/flowlayout.cpp

HEADERS += \
    version.h \
    mainwindow.h \
    core/xyfuncpanelwidget.h \
    core/xyfuncplugin.h \
    core/xyfuncproxywidget.h \
    core/xyfuncsbox.h \
    core/xyimageviewer.h \
    core/xyexpansionsbox.h \
    core/xystoragebox.h \
    core/flowlayout.h

FORMS += \
        mainwindow.ui

INCLUDEPATH += core

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images/images.qrc

win32 {
msvc {
greaterThan(QT_MAJOR_VERSION, 4): RC_FILE = app.rc
}
}
