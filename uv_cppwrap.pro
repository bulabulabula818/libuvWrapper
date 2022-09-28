TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        application.cpp \
        main.cpp \
        tcpserver.cpp

HEADERS += \
    application.h \
    tcpserver.h

LIBS += -luv

MOC_DIR = temp/moc
RCC_DIR = temp/rcc
UI_DIR = temp/ui
OBJECTS_DIR = temp/obj
