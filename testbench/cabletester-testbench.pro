QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += mockup #so the compiler finds something that looks like the pi pico includes

DEFINES += RUNNING_SIMULATED_ON_PC

SOURCES += \
    ../cable-tester/cable-tester.c \
    ../cable-tester/sampler-test.c \
    ../cable-tester/sampler.c \
    main.cpp \
    mainwindow.cpp \
    mockup/hardware/gpio.c \
    mockup/hardware/irq.c \
    mockup/hardware/timer.c \
    mockup/hardware/uart.c \
    mockup/pico/stdio.c \
    mockup/pico/stdlib.c \
    mockup/pico/time.c \
    unity/unity.c

HEADERS += \
    ../cable-tester/sampler-test.h \
    ../cable-tester/sampler.h \
    ../cable-tester/utils.h \
    mainwindow.h \
    mockup/boards/pico.h \
    mockup/hardware/address_mapped.h \
    mockup/hardware/gpio.h \
    mockup/hardware/irq.h \
    mockup/hardware/platform_defs.h \
    mockup/hardware/regs/addressmap.h \
    mockup/hardware/regs/dreq.h \
    mockup/hardware/regs/intctrl.h \
    mockup/hardware/regs/io_bank0.h \
    mockup/hardware/regs/m0plus.h \
    mockup/hardware/regs/pads_bank0.h \
    mockup/hardware/regs/sio.h \
    mockup/hardware/regs/timer.h \
    mockup/hardware/regs/uart.h \
    mockup/hardware/structs/interp.h \
    mockup/hardware/structs/iobank0.h \
    mockup/hardware/structs/padsbank0.h \
    mockup/hardware/structs/sio.h \
    mockup/hardware/structs/timer.h \
    mockup/hardware/structs/uart.h \
    mockup/hardware/timer.h \
    mockup/hardware/uart.h \
    mockup/pico.h \
    mockup/pico/assert.h \
    mockup/pico/config.h \
    mockup/pico/config_autogen.h \
    mockup/pico/error.h \
    mockup/pico/platform.h \
    mockup/pico/stdio.h \
    mockup/pico/stdlib.h \
    mockup/pico/time.h \
    mockup/pico/types.h \
    mockup/pico/version.h \
    mockup/pico/version.h.in \
    unity/unity.h \
    unity/unity_internals.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
