#include <iostream>
#include <cmath>
#include "Toupie.h"
#include "constant.h"
#include "Vecteur.h"
#include "Dessinable.h"
using namespace std;

int main(){
    TextViewer text(cout);

    cout << "=========TOUPIE SINUS==========" << endl;
	double masse_sinus(1);
    Pendule toupie_sinus(&text,masse_sinus,Vecteur({PI/6,0,0,0,0,0}),Vecteur({0,0,60,0,0,0}),1); // test la construction d'une toupie normale
        cout << toupie_sinus << endl; // test l'affichage d'une toupie normale
    toupie_sinus.dessine();
        Vecteur P_point_point_sinus(toupie_sinus.eq_mouv());
	cout << "Le vecteur acceleration de la toupie est " << P_point_point_sinus << endl;

    cout << endl << "==========CONE SIMPLE==========" << endl;
	double masse_volumique_cone(0.1);
	double hauteur_cone(1.5);
	double rayon_cone(0.5);
	double m_cone(masse_cone(masse_volumique_cone,hauteur_cone,rayon_cone)); // test la fonction masse_cone
	Vecteur P_cone({PI/6,0,0});
	Vecteur P_point_cone({0,0,60});
    ConeSimple cone_simple(&text,m_cone,1,1,P_cone,P_point_cone,Vecteur()); // test la construction d'un cone simple
	cout << cone_simple << endl; // test l'affichage d'un cone simple
	
	Vecteur P_point_point_cone(cone_simple.eq_mouv());
	cout << "Le vecteur acceleration de la toupie est " << P_point_point_cone << endl;

	return  0;
}
