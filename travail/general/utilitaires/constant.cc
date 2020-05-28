#include <iostream>
#include "Vecteur.h"
#include "constant.h"
#include <cmath>
using namespace std;

extern const double g(9.81);

extern const Vecteur grav({0.0,0.0,-9.81});

extern const double precision(1e-15);

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
    case 1:cout << endl << endl << "Erreur : division par 0 impossible" << endl << endl;
    break;
    case 2:cout << endl << endl << "Erreur : dimension differente de 3" << endl << endl;
    break;
    case 3:cout << endl << endl << "Erreur : dimensions des vecteurs incompatibles" << endl << endl;
    break;
    case 4:cout << endl << endl << "Erreur : la composante voulu n'existe pas" << endl << endl;
    break;
    case 5:cout << endl << endl << "Erreur : masse de la toupie negative ou nulle"<< endl <<endl;
    break;
    case 6:cout << endl << endl << "Erreur : rayon de la toupie negatif ou nul"<< endl <<endl;
    break;
    case 7:cout << endl << endl << "Erreur : coefficient du tenseur d'inertie (I1) negatif ou nul"<< endl << endl;
    break;
    case 8:cout << endl << endl << "Erreur : coefficient du tenseur d'inertie (I3) negatif ou nul"<< endl << endl;
    break;
    case 9:cout << endl << endl << "Erreur : hauteur de la toupie negatif ou nulle"<< endl << endl;
    break;
    case 10:cout << endl << endl << "Erreur : theta du Vecteur de parametre de la toupie nul"<< endl << endl;
    break;
    case 11:cout << endl << endl << "Erreur : le solide de révolution ne comporte aucun rayon"<< endl << endl;
    break;
    case 12:cout << endl << endl << "Erreur : un des rayons du solide de revolution est negatif ou nul"<< endl << endl;
    break;
    case 13:cout << endl << endl << "Erreur : distance entre le centre de masse et le point de contact est negatif ou nul"<< endl << endl;
    break;
    case 14:cout << endl << endl << "Erreur : hauteur tronque superieur au rayon de la toupie chinoise"<< endl << endl;
    break;
    case 15:cout << endl << endl << "Erreur : hauteur tronque negative" << endl << endl;
    break;
    case 16:cout << endl << endl << "Erreur : masse volumique du solide de revolution est negative ou nulle" << endl << endl;
    break;
    case 17:cout << endl << endl << "Erreur : longueur du pendule negatif ou nul" << endl << endl;
    break;
    case 18:cout << endl << endl << "Erreur : cone simple avec un vecteur de parametre ou de derivee de dimension differente de 3" << endl << endl;
    break;
    case 19:cout << endl << endl << "Erreur : toupie chinoise avec un vecteur de parametre ou de derivee de dimension differente de 5" << endl << endl;
    break;
    case 20:cout << endl << endl << "Erreur : solide de revolution avec un vecteur de parametre ou de derivee de dimension differente de 3" << endl << endl;
    break;
    case 21:cout << endl << endl << "Erreur : masse qui tombe avec un vecteur de parametre ou de derivee de dimension differente de 3" << endl << endl;
    break;
    case 22:cout << endl << endl << "Erreur : pendule avec un vecteur de parametre ou de derivee de dimension differente de 3" << endl << endl;
    break;
    case 23:cout << endl << endl << "Erreur : point de contact du referentiel R_O de dimension differente de 3" << endl << endl;
    break;
    case 24:cout << endl << endl << "Erreur : coordonnee z du point de contact negatif" << endl << endl; // pour l'affichage graphique
    }
}
