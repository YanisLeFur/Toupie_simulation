CXX = g++
CC = $(CXX)
CXXFLAGS = -std=c++11 -pedantic -Wall



all:Exercice_P9

clean:
	$(RM) *.o *~



Exercice_P9: Systeme.o Matrice.o Vecteur.o constant.o Integrateur.o Dessinable.o memoire.o Toupie.o

Systeme.o: Systeme.h Systeme.cc
Vecteur.o: Vecteur.h Vecteur.cc
Matrice.o: Matrice.h Matrice.cc
constant.o: constant.h constant.cc
Integrateur.o: Integrateur.h Integrateur.cc
Dessinable.o: Dessinable.h Dessinable.cc
memoire.o: memoire.h memoire.cc
Toupie.o: Toupie.h Toupie.cc

Exercice_P9.o: Exercice_P9.cc Systeme.h Matrice.h Vecteur.h memoire.h constant.h Integrateur.h Dessinable.h Toupie.h

