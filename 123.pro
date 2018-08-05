#-------------------------------------------------
#
# Project created by QtCreator 2018-08-04T11:54:23
#
#-------------------------------------------------

QT       += core gui widgets

TARGET = 123
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

TRANSLATIONS += translate_RU.ts

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    windows/constructor/constructor_window.cpp \
    windows/time_calculate/time_calculate_window.cpp \
    windows/function/function_window.cpp \
    windows/time_calculate/librarys/sort.cpp \
    settings.cpp \
    windows/time_calculate/more_one_sorting.cpp \
    windows/time_calculate/write_sort.cpp \
    windows/time_calculate/librarys/color_progress_bar.cpp

HEADERS += \
        mainwindow.h \
    windows/constructor/constructor_window.h \
    windows/time_calculate/time_calculate_window.h \
    windows/function/function_window.h \
    windows/time_calculate/librarys/sort.h \
    settings.h \
    windows/time_calculate/more_one_sorting.h \
    windows/time_calculate/write_sort.h \
    windows/time_calculate/librarys/color_progress_bar.h

FORMS += \
        mainwindow.ui \
    windows/constructor/constructor_window.ui \
    windows/time_calculate/time_calculate_window.ui \
    windows/function/function_window.ui \
    settings.ui \
    windows/time_calculate/more_one_sorting.ui \
    windows/time_calculate/write_sort.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    yahzwhatisit.qrc
