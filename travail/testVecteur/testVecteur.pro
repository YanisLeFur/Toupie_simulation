QT+= core gui opengl widgets
CONFIG += c++11

win32:LIBS += -lopengl32


TARGET = testVecteur_1

INCLUDEPATH = ../general/outils_Maths\
              ../general/utilitaires

VPATH += ../general/outils_Maths\
              ../general/utilitaires

SOURCES += TestVecteur.cc\
    Vecteur.cc \
    constant.cc \



HEADERS += \ \
    Vecteur.h \
    constant.h
