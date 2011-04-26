#-------------------------------------------------
#
# Project created by QtCreator 2011-04-19T21:45:50
#
#-------------------------------------------------

QT       += core gui

TARGET = Visiweather
TEMPLATE = app

SOURCES += main.cpp\
        visiweather.cpp

HEADERS  += visiweather.h

FORMS    += \
    visiweather.ui

CONFIG += mobility
MOBILITY = 

symbian {
    TARGET.UID3 = 0xe20d1884
    # TARGET.CAPABILITY += 
    TARGET.EPOCSTACKSIZE = 0x14000
    TARGET.EPOCHEAPSIZE = 0x020000 0x800000
}

OTHER_FILES +=

RESOURCES +=
