#include <iostream>
#include <fstream>
#include "Integrateur.h"
#include "Toupie.h"
#include "Vecteur.h"
#include "constant.h"
#include "Dessinable.h"
#include  "Matrice.h"
#include <cmath>

using namespace std;

int main(){

	double dt(0.01);
    double nb_echantillons(50);
    double temps(0);

	cout<<"==========EULER-CROMER=========="<<endl;


	IntegrateurEulerCromer EC;
    IntegrateurNewmark N;
    IntegrateurRungeKutta RK;
	
///PENDULE==================================================================
    /*TextViewer text1(cout);
    double masse_sinus(1);
    Vecteur P_sinus({1,PI/6,0,0,0,0});
    Vecteur P_point_sinus({0,0,0,0,0,0});
    Pendule sinus(&text1,masse_sinus,P_sinus,P_point_sinus,1);
	
    cout << "Pendule: " << endl;

    for (int i(0); i <nb_echantillons; i++){
        cout << endl << "temps: " << temps+i*dt << endl;
		EC.integre(dt,sinus);
        cout << endl << "EC: " << sinus.EC();
        cout << endl << "EP: " << sinus.EP();
        cout << endl << "E: " << sinus.E();
        text1.dessine(sinus);
    }

    cout << "===================================" << endl;*/


///MASSE TOMBE==================================================================	
    /*TextViewer text2(cout);
    Vecteur P ({10,100,0});
    Vecteur P_point({2,2,0});
    MasseTombe simple(&text2,1,P,P_point);
	
    cout << "Masse qui tombe: " << endl;
	
    for (int i(0); i <nb_echantillons; i++){
        RK.integre(dt,simple);
        text2.dessine(simple);
        cout << "EC: " << simple.EC() << endl;
        cout << "EP: " << simple.EP() << endl;
        cout << "E: " << simple.E() << endl;
    }*/

///CONE SIMPLE==================================================================
    TextViewer text3(cout);
	double masse_volumique(0.1);
	double hauteur(1.5);
	double rayon(0.5);
    Vecteur P_cone({0,M_PI/6,0});
    Vecteur P_point_cone({0,0,60});
    ConeSimple cone_simple(&text3,masse_cone(masse_volumique,hauteur,rayon),hauteur,rayon,P_cone,P_point_cone,Vecteur({0,0,0}));
	
    cout << "Cone simple: " << endl;

    cout << "IG_G: " << endl << cone_simple.IG_G() << endl;

    cout << "IA_G: " << endl << cone_simple.IA_G() << endl;

    cout << "S_: " << endl << cone_simple.S_() << endl;

    cout << "P_G: " << cone_simple.S_()*cone_simple.P_O() << endl;

    cout << "P_O: " << cone_simple.P_O() << endl;

    cout << "G_G: " << cone_simple.G_G() << endl;

    cout << "G_O: " << cone_simple.G_O() << endl;

    cout << "omega_G: " << cone_simple.omega_G() << endl;

    cout << "omega_O: " << cone_simple.omega_O() << endl;

    cout << "omega_e_G: " << cone_simple.omega_e_G() << endl;

    cout << "omega_e_O: " << cone_simple.omega_e_O() << endl;

    cout << "IG_O: " << endl <<cone_simple.IG_O() << endl;

    cout << "IA_O: " << endl << cone_simple.IA_O() << endl;

    cout << "MA_G: " << cone_simple.MA_G() << endl;

    cout << "MA_O: " << cone_simple.MA_O() << endl;

    cout << "LA_G: " << cone_simple.LA_G() << endl;

    cout << "LA_O: " << cone_simple.LA_O() << endl;

    cout << "LG_G: " << cone_simple.LG_G() << endl;

    cout << "LG_O: " << cone_simple.LG_O() << endl;

    cout << "Devrait etre 0: " << cone_simple.LG_O()-cone_simple.S_().transp()*cone_simple.LG_G() << endl;

    cout << "omega_point_G: " << cone_simple.omega_point_G() << endl;

    cout << "eq_mouv: " << cone_simple.eq_mouv() << endl;

    cout << "Energie: " << cone_simple.E() << endl;

    for (int i(0); i <nb_echantillons; i++){
            cout << endl << "temps: " << temps+i*dt << endl;
            cout << endl << "LA_a: " << cone_simple.LA_a() <<endl;
            RK.integre(dt,cone_simple);

            //text3.dessine(cone_simple);

            //text3.dessine(copie2);



            cout << endl << "LA_a: " << cone_simple.LA_a();

            cout << endl << "LA_k: " << cone_simple.LA_k();

            cout << endl << "EC: " << cone_simple.EC();

            cout << endl << "E: " << cone_simple.E();

            cout << endl << "AG: " << cone_simple.AG();
    }

///TOUPIE CHINOISE=====================================================

    Vecteur P_chinoise({0,0.11,0,0,0});
    Vecteur P_point_chinoise({50,0,0,0,0});
    double masse_volumique_chinoise(0.1);
    double hauteur_chinoise(0.02);
    double rayon_chinoise(0.15);
    ToupieChinoise tc(&text3,masse_cone(masse_volumique_chinoise,hauteur_chinoise,rayon_chinoise),hauteur_chinoise,rayon_chinoise,P_chinoise,P_point_chinoise,Vecteur({0,0,0}));

    cout << tc << endl;

    for (int i(0); i <nb_echantillons; i++){
        cout << endl << "temps: " << temps+i*dt << endl;
        text3.dessine(tc);
        EC.integre(dt,tc);
        //cout << "EC: " << tc.EC() << endl;
        //cout << "EP: " << tc.EP() << endl;
        //cout << "E: " << tc.E() << endl;
    }

	return 0;
}
