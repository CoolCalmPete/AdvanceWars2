######################################################################
# Automatically generated by qmake (2.01a) Do Feb 12 16:23:37 2009
######################################################################

TEMPLATE = app
TARGET = netwars
DEPENDPATH += . ../ ../lib
INCLUDEPATH += . ../ ../lib

CONFIG += no_keywords

DEFINES += TIXML_USE_TICPP TIXML_USE_STL
LIBS += ../*.a
LIBS += -lboost_signals-mt

# Input
HEADERS += MainWindow.h MapWidget.h Sprites.h
FORMS += mainWindow.ui
SOURCES += main.cpp MainWindow.cpp MapWidget.cpp Sprites.cpp
RESOURCES += data.qrc
