#-------------------------------------------------
#
# Project created by QtCreator 2011-04-26T18:20:28
#
#-------------------------------------------------

folder_01.source = c:\\Visiweather1\\rcs
folder_01.target = .
DEPLOYMENTFOLDERS = folder_01

QT       += core gui xmlpatterns network declarative

TARGET = interface_qml
TEMPLATE = app




SOURCES += main.cpp\
        qml_interface.cpp \
    receiver.cpp \
    dataloader.cpp

HEADERS  += qml_interface.h \
    receiver.h \
    dataloader.h

CONFIG += mobility
MOBILITY = 

symbian {
    TARGET.UID3 = 0xec7d4d2d
     TARGET.CAPABILITY += NetworkServices
    TARGET.EPOCSTACKSIZE = 0x14000
    TARGET.EPOCHEAPSIZE = 0x020000 0x800000
}

include(qmlapplicationviewer.pri)
qtcAddDeployment()
