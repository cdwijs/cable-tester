QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += mockup #so the compiler finds something that looks like the pi pico includes

SOURCES += \
    ../cable-tester/cable-tester.c \
    ../cable-tester/sampler.c \
    main.cpp \
    mainwindow.cpp \
    mockup/pico/stdlib.c \
    unity/unity.c

HEADERS += \
    ../cable-tester/sampler.h \
    mainwindow.h \
    mockup/pico/stdlib.h \
    unity/unity.h \
    unity/unity_internals.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
