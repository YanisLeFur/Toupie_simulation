QT+= core gui opengl widgets
CONFIG += c++11

win32:LIBS += -lopengl32


TARGET = testSysteme_1

INCLUDEPATH = ../general\
              ../general/outils_Maths\
              ../general/utilitaires\
              ../general/objets

VPATH += ../general\
         ../general/outils_Maths\
         ../general/objets\
         ../general/utilitaires

SOURCES += TestSysteme.cc\
    ../general/utilitaires/constant.cc \
        Systeme.cc\
        Integrateur.cc\
        Dessinable.cc\
        Vecteur.cc\
        Toupie.cc\
        Matrice.cc

HEADERS += \ \
        ../general/utilitaires/constant.h \
        Systeme.h\
        Integrateur.h\
        Dessinable.h\
        Vecteur.h\
        Toupie.h\
        Matrice.h
