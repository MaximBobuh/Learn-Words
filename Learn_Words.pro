QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Learn_Words
TEMPLATE = app

CONFIG += c++11

INCLUDEPATH += $${_PRO_FILE_PWD_}/Widgets
INCLUDEPATH += $${_PRO_FILE_PWD_}/Widgets/Resources
INCLUDEPATH += $${_PRO_FILE_PWD_}/Data

DEPENDPATH += $$INCLUDEPATH

SOURCES += main.cpp \
     Widgets/DictionaryView.cpp\
     Widgets/ProfileSelectWidget.cpp\
     Widgets/ProfileWidget.cpp\
     Widgets/WordWidget.cpp

HEADERS  += \
     Widgets/AdditionalFunctions.h\
     Widgets/DictionaryView.h\
     Widgets/ProfileSelectWidget.h\
     Widgets/ProfileWidget.h\
     Widgets/WordWidget.h\
     Data/DictionaryModel.h\
     Data/Reader.h\
     Data/WordData.h\

