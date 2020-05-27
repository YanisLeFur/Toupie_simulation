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
    case 5:cout<<"Erreur: masse de la toupie nulle"<<endl;
    break;
    case 6:cout<<"Erreur: rayon de la toupie nul"<<endl;
    break;
    case 7:cout<<"Erreur: coefficient du tenseur d'inertie (I1) nul"<<endl;
    break;
    case 8:cout<<"Erreur: coefficient du tenseur d'inertie (I3) nul"<<endl;
    break;
    case 9:cout<<"Erreur: hauteur de la toupie nulle"<<endl;
    break;
    case 10:cout<<"Erreur: theta du Vecteur paramètre de la toupie nul"<<endl;
    break;
    case 11:cout<<"Erreur: rayon de la toupie négatif"<<endl;
    break;
    case 12:cout<<"Erreur: hauteur de la toupie négative"<<endl;
    break;
    case 13:cout<<"Erreur: le solide de révolution ne comporte aucun rayon"<<endl;
    break;
    case 14:cout<<"Erreur: tous les rayons du solide de revolution sont nuls"<<endl;
    break;
    case 15: cout<<"Erreur: distance entre le centre de masse et le point de contact est nul"<<endl;
    break;
    case 16: cout<<"Erreur: hauteur tronque superieur au rayon de la toupie chinoise "<<endl;
    }
}
