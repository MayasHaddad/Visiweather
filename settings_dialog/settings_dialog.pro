#-------------------------------------------------
#
# Project created by QtCreator 2011-04-27T00:52:56
#
#-------------------------------------------------

QT       += core gui network script

TARGET = settings_dialog
TEMPLATE = app


SOURCES += main.cpp\
        settingswindow.cpp \
    autocomplete.cpp

HEADERS  += settingswindow.h \
    autocomplete.h

CONFIG += mobility
MOBILITY = 

symbian {
    TARGET.UID3 = 0xec2b08cc
    # TARGET.CAPABILITY += 
    TARGET.EPOCSTACKSIZE = 0x14000
    TARGET.EPOCHEAPSIZE = 0x020000 0x800000
}
