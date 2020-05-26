#include <iostream>
#include "Vecteur.h"
#include "constant.h"
#include <cmath>
using namespace std;

extern const double g(9.81);

extern const Vecteur grav({0.0,0.0,-9.81});

extern const double precision(1e-15);

//extern const double PI(3.1415926535);

extern const double epsilon(1e-8);

double modulo_2pi(double angle) {
    while (angle>=2*M_PI) {
        angle-=2*M_PI;
    }
    while (angle<=0) {
        angle+=2*M_PI;
    }
    return angle;
}


void affiche_erreur(const int &i)
{
    switch(i){
    case 1:cout << endl << endl << "Erreur: division par 0 impossible" << endl << endl;
    break;
    case 2:cout << endl << endl << "Erreur: dimension differente de 3" << endl << endl;
    break;
    case 3:cout << endl << endl << "Erreur: dimensions des vecteurs incompatibles" << endl << endl;
    break;
    case 4:cout << endl << endl << "Erreur: la composante voulu n'existe pas" << endl << endl;
    break;
    }
}
