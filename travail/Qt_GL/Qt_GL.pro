QT += core gui opengl widgets
CONFIG += c++11

win32:LIBS += -lopengl32


TARGET = Qt_Gl

LIBS += -L../general -lgeneral
PRE_TARGETDEPS += #../general/libgeneral.a
                  ../general/libgeneral.dylib


INCLUDEPATH = ../general\
              ../general/outils_Maths\
              ../general/objets\
              ../general/utilitaires
SOURCES += \
    ../general/objets/Toupie.cc \
    ../general/outils_Maths/Vecteur.cc \
    ../general/utilitaires/constant.cc\
    main_qt_gl.cc \
    glwidget.cc \
    vue_opengl.cc \
    glchinoise.cpp \
    glsphere.cpp \
    ../general/outils_Maths/integrateur.cc\
    ../general/utilitaires/memoire.cc\
    ../general/Dessinable.cc\


HEADERS += \
    ../general/objets/Toupie.h \
    ../general/outils_Maths/Vecteur.h \
    ../general/utilitaires/constant.h\
    glchinoise.h \
    glsphere.h \
    glwidget.h \
    vertex_shader.h \
    vue_opengl.h \
    glsphere.h \
    ../general/dessinable.h \
    ../general/outils_Maths/integrateur.h\
    ../general/utilitaires/memoire.h\
    ../general/Dessinable.h\

RESOURCES += \
    resource.qrc
