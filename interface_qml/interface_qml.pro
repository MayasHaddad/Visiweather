#-------------------------------------------------
#
# Project created by QtCreator 2011-04-26T18:20:28
#
#-------------------------------------------------

QT       += core gui xmlpatterns network declarative

TARGET = interface_qml
TEMPLATE = app


SOURCES += main.cpp\
        qml_interface.cpp \
    receiver.cpp

HEADERS  += qml_interface.h \
    receiver.h

CONFIG += mobility
MOBILITY = 

symbian {
    TARGET.UID3 = 0xec7d4d2d
     TARGET.CAPABILITY += NetworkServices
    TARGET.EPOCSTACKSIZE = 0x14000
    TARGET.EPOCHEAPSIZE = 0x020000 0x800000
}

RESOURCES +=
