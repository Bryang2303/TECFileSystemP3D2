#-------------------------------------------------
#
# Project created by QtCreator 2021-06-21T18:31:37
#
#-------------------------------------------------

QT       += core gui network xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TEC_File_System_P3D2
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        widget.cpp \
    socketcliente.cpp \
    filesmanagement.cpp \
    controllernode.cpp \
    huffman.cpp \
    tecfsdisk.cpp \
    disknode.cpp

HEADERS += \
        widget.h \
    socketcliente.h \
    filesmanagement.h \
    controllernode.h \
    huffman.h \
    tecfsdisk.h \
    disknode.h

FORMS += \
        widget.ui
QMAKE_CXXFLAGS += -std=gnu++14

GENERATE_QHP           = YES
QCH_FILE               = <project>.qch
QHP_NAMESPACE          = <namespace>
QHP_VIRTUAL_FOLDER     = doc
QHG_LOCATION           = qhelpgenerator
