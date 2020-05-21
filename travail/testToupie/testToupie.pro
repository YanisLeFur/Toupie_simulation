QT+= core gui opengl widgets
CONFIG += c++11

win32:LIBS += -lopengl32


TARGET = testToupie_1

INCLUDEPATH =../general\
              ../general/outils_Maths\
              ../general/objets\
              ../general/utilitaires

VPATH +=../general\
         ../general/outils_Maths\
         ../general/objets\
         ../general/utilitaires

SOURCES += TestToupie.cc\
    Vecteur.cc \
    Toupie.cc \
    constant.cc \
    Dessinable.cc \
    Matrice.cc \
    memoire.cc\



HEADERS += \ \
    Vecteur.h \
    Toupie.h \
    constant.h\
    Dessinable.h \
    Matrice.h \
    memoire.h\
