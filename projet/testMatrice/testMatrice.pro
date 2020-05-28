QT+= core gui opengl widgets
CONFIG += c++11

win32:LIBS += -lopengl32


TARGET = testMatrice_1

INCLUDEPATH = ../general/outils_Maths\
              ../general/utilitaires

VPATH += ../general/outils_Maths\
         ../general/utilitaires

SOURCES += testMatrice.cc\
    Matrice.cc \
    Vecteur.cc \
    constant.cc \



HEADERS +=\ \
    Matrice.h \
    Vecteur.h \
    constant.h
