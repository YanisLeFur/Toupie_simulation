greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport
CONFIG += c++11

win32:LIBS += -lopengl32


TARGET = testVecteur_1

INCLUDEPATH = ../general/outils_Maths\
              ../general/utilitaires\
              ../general/objets\
              ../general/CustomPlot\
              ../general/

VPATH += ../general/outils_Maths\
         ../general/utilitaires\
         ../general/objets\
         ../general/CustomPlot\
        ../general\

SOURCES += TestCustomPlot.cc\
           Toupie.cc\
           Dessinable.cc\




HEADERS += \ \
        Toupie.h\
        Dessinable.h\
