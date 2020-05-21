QT+= core gui opengl widgets
CONFIG += c++11

win32:LIBS += -lopengl32


TARGET = testIntegrateur

INCLUDEPATH = ../general\
              ../general/outils_Maths\
              ../general/objets\
              ../general/utilitaires

VPATH += ../general\
        ../general/outils_Maths\
        ../general/objets\
        ../general/utilitaires

SOURCES += TestIntegrateur.cc\
    Integrateur.cc \
    Matrice.cc \
    Vecteur.cc \
    Toupie.cc \
    constant.cc \
    Dessinable.cc\
    memoire.cc\



HEADERS += \ \
    Integrateur.h \
    Matrice.h \
    Vecteur.h \
    Toupie.h \
    constant.h\
    Dessinable.h\
    memoire.h\
