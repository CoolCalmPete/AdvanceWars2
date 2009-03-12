######################################################################
# Automatically generated by qmake (2.01a) Do Feb 12 16:23:37 2009
######################################################################

TEMPLATE = app
TARGET = netwars
DEPENDPATH += . ../ ../lib
INCLUDEPATH += . ../ ../lib

CONFIG += debug
CONFIG += no_keywords

DEFINES += TIXML_USE_TICPP TIXML_USE_STL
LIBS += ../*.a
LIBS += -lboost_signals-mt

# Input
HEADERS +=	BuyMenu.h \
			GameDialog.h \
			GameScene.h \
            MainWindow.h \
			PathGraphicsItem.h \
			PixmapDrawing.h \
			Sprites.h \
			UnitActionMenuButton.h \
			UnitActionMenu.h \
			UnitGraphicsItem.h \
			UnitUnloadMenuButton.h \
			UnitUnloadMenu.h \

FORMS +=	buyMenu.ui \
			gameDialog.ui \
			mainWindow.ui \

SOURCES +=	BuyMenu.cpp \
			GameDialog.cpp \
			GameScene.cpp \
			main.cpp \
			MainWindow.cpp \
			PixmapDrawing.cpp \
			Sprites.cpp \
			UnitGraphicsItem.cpp \
			UnitActionMenu.cpp \
			UnitUnloadMenu.cpp \

RESOURCES += data.qrc
