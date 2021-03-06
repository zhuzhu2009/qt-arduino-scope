################################################################
# Qwt Widget Library
# Copyright (C) 1997   Josef Wilgen
# Copyright (C) 2002   Uwe Rathmann
#
# This library is free software; you can redistribute it and/or
# modify it under the terms of the Qwt License, Version 1.0
################################################################

include( examples.pri )

INCLUDEPATH += /usr/include/QtExtSerialPort
INCLUDEPATH += /usr/include
INCLUDEPATH += /usr/lib/qt4/examples/designer/qledplugin/

QT += serialport
QT+=qledplugin

LIBS += -lqledplugin
TARGET   = oscilloscope
LIBS += -lqextserialport
DEFINES = _TTY_POSIX_

HEADERS = \
    signaldata.h \
    plot.h \
    knob.h \
    wheelbox.h \
    samplingthread.h \
    curvedata.h \
    led/widgetwithbackground.h \
    led/led.h  \
    mainwindow.h


SOURCES = \
    signaldata.cpp \
    plot.cpp \
    knob.cpp \
    wheelbox.cpp \
    samplingthread.cpp \
    curvedata.cpp \
    mainwindow.cpp \
    led/widgetwithbackground.cpp \
    led/led.cpp \
    main.cpp
