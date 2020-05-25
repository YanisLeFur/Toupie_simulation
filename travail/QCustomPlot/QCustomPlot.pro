QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
INCLUDEPATH = ../general/objets\
              ../general/outils_Maths\
              ../general/utilitaires\
              ../general\


SOURCES += \
    main.cpp \
    mainwindow.cpp \
    qcustomplot.cpp\
    ../general/objets/Toupie.cc\
    ../general/outils_Maths/Vecteur.cc\
    ../general/Dessinable.cc\
    ../general/utilitaires/constant.cc\
    ../general/outils_Maths/Integrateur.cc\
    ../general/outils_Maths/Matrice.cc\
    ../general/utilitaires/memoire.cc\

HEADERS += \
    mainwindow.h \
    qcustomplot.h\
    ../general/objets/Toupie.h\
    ../general/outils_Maths/Vecteur.h\
    ../general/Dessinable.h\
    ../general/utilitaires/constant.h\
    ../general/outils_Maths/Integrateur.h\
    ../general/outils_Maths/Matrice.h\
    ../general/utilitaires/memoire.h\

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
