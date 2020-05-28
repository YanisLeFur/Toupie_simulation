TEMPLATE = lib
CONFIG += c++11
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

INCLUDEPATH= ../general\
              ../general/outils_Maths\
              ../general/objets\
              ../general/utilitaires\
              ../general/customplot

VPATH = utilitaires\
        objets\
        outils_Maths\
        customplot\

HEADERS += \
    Systeme.h \
    constant.h\
    Vecteur.h \
    Toupie.h \
    Matrice.h \
    Integrateur.h \
    Dessinable.h \
    Systeme.h \
    memoire.h\
   # qcustomplot.h\
   # mainwindow.h\
    #ui_mainwindow.h

SOURCES += \
    Dessinable.cc\
    Systeme.cc\
    Vecteur.cc \
    Integrateur.cc \
    Matrice.cc \
    Toupie.cc \
    constant.cc \
    memoire.cc\
   # qcustomplot.cpp\
   # mainwindow.cpp\


FORMS += \
   #../general/customplot/mainwindow.ui\

DISTFILES += \
    general.pro.autosave

SUBDIRS += \
    utilitaires/utilitaires.pro \
    utilitaires/utilitaires.pro



