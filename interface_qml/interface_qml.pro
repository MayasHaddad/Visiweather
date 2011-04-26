#-------------------------------------------------
#
# Project created by QtCreator 2011-04-26T18:20:28
#
#-------------------------------------------------

QT       += core gui

TARGET = interface_qml
TEMPLATE = app

 QT += gui declarative

SOURCES += main.cpp\
        qml_interface.cpp

HEADERS  += qml_interface.h

CONFIG += mobility
MOBILITY = 

symbian {
    TARGET.UID3 = 0xec7d4d2d
    # TARGET.CAPABILITY += 
    TARGET.EPOCSTACKSIZE = 0x14000
    TARGET.EPOCHEAPSIZE = 0x020000 0x800000
}

RESOURCES +=
