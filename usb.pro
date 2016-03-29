TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH     += "/usr/include/libusb-1.0/"
DEPENDPATH      += "/usr/include/libusb-1.0/"
#LIBS            += "/usr/include/libusb-1.0/"
PRE_TARGETDEPS  += "/usr/include/libusb-1.0/"

SOURCES += main.c
