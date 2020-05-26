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



//Implémentation éléments====================================================================================================================


        TextViewer text(cout);      //permet l'affichage textuel

        //Intégrateurs---------------------
        IntegrateurRungeKutta RK;
        IntegrateurNewmark NM;
        IntegrateurEulerCromer EC;
        //----------------------------------

        //pas de temps pour l'integration des toupies
        double pas_de_temps(0.01);

        double nb_echantillons(50);
        double temps(0);

//Pendule--------------------------------------------------------------------------------------------------------------------------------------

        double masse_sinus(1);

        //Construction pendule avec (Support à dessin, masse, Vecteur de paramètre, Vecteur de derivée des paramètres, Point de contact)
        //on modelise le pendule en coordonnées cylindriques
        Pendule pendule(&text,masse_sinus,Vecteur({M_PI/6,0,0}),Vecteur({0,0,60}),Vecteur(0,1,2));


//ConeSimple-----------------------------------------------------------------------------------------------------------------------------------

        double masse_volumique_cone(0.1);
        double hauteur_cone(1.5);
        double rayon_cone(0.5);
        Vecteur P_cone({0,M_PI/6,0});
        Vecteur P_point_cone({0,0,60});


        //méthode calculant la masse d'un cône à partir d'une masse volumique, une hauteur et un rayon
        double m_cone(masse_cone(masse_volumique_cone,hauteur_cone,rayon_cone));

        //Construction d'une toupie cônique avec:  un support à dessin, une masse, des coefficient d'un tenseur d'inertie (I1,I3),
        //                                         un Vecteur de paramètre, un Vecteur de dérivée des paramètre et un point de contact
        ConeSimple cone_simple(&text,m_cone,hauteur_cone,rayon_cone,P_cone,P_point_cone,Vecteur({1,1,1}));


//MasseTombe--------------------------------------------------------------------------------------------------------------------------------------

        //Construction d'une masse en chute libre à partir: d'un support à dessin, une masse, un Vecteur de paramètres
        //                                              un Vecteur dérivée de paramètre
        MasseTombe masse_tombe(&text,1,Vecteur({10,100,1}), Vecteur({2,2,1}));

//ToupieChinoise-----------------------------------------------------------------------------------------------------------------------------------

        double masse_volumique(0.1);
        double hauteur(0.02);
        double rayon(0.15);

        //méthode calculant la masse d'une toupie chinoise à partir d'une masse volumique, une hauteur et un rayon
        double m_chinoise(masse_chinoise(masse_volumique,hauteur,rayon));


        //Construction d'une Toupie chinoise à partir: d'un support à dessin, une masse, une hauteur, un rayon,
        //                                              un Vecteur de paramètres, un Vecteur dérivée de paramètre, un point de contact
        ToupieChinoise chinoise(&text,m_chinoise,hauteur,rayon,Vecteur({0,0.11,0,0,0}),Vecteur({50,0,0,0,0}),Vecteur({1,2,3}));


//SolideRevolution---------------------------------------------------------------------------------------------------------------------------------

        //vector des rayons différents
        vector<double> r_i;

        //premier rayon
        double r(0.01);
        double hauteur_sr(1.5);
        double masse_volumique_sr(0.1);

        for(int i(0); i<50 ; ++i) {
            r_i.push_back(r+i*(0.01));
        }

        //Construction d'un solide de révolution à partir: d'un support à dessin, une masse volumique, une hauteur, un tableau des rayons différents,
        //                                              un Vecteur de paramètres, un Vecteur dérivée de paramètre, un point de contact
       SolideRevolution sr(&text,masse_volumique_sr,hauteur_sr,r_i,Vecteur(0,M_PI/6,0),Vecteur(0,0,200),Vecteur());

//Toupie_general-----------------------------------------------------------------------------------------------------------------------------------

        Toupie toupie_general(&text,m_cone,P_cone,P_point_cone,3.*(m_cone/20.)*(rayon_cone*rayon_cone+1./4.*hauteur_cone*hauteur_cone),
                              3.*m_cone/10.*rayon_cone*rayon_cone,hauteur_cone*3./4.,Vecteur({1,1,1}));


//==================================================================================================================================================

	
    cout << "Pendule: " << endl;

    for (int i(0); i <nb_echantillons; i++){
        cout << endl << "temps: " << temps+i*pas_de_temps << endl;
        EC.integre(pas_de_temps,pendule);
        cout << endl << "EC: " << pendule.EC();
        cout << endl << "EP: " << pendule.EP();
        cout << endl << "E: " << pendule.E();
        pendule.dessine();
    }

    cout << "===================================" << endl;


///MASSE TOMBE==================================================================	
	
    cout << "Masse qui tombe: " << endl;
	
    for (int i(0); i <nb_echantillons; i++){
        RK.integre(pas_de_temps,masse_tombe);
        text.dessine(masse_tombe);
        cout << "EC: " << masse_tombe.EC() << endl;
        cout << "EP: " << masse_tombe.EP() << endl;
        cout << "E: " << masse_tombe.E() << endl;
    }

///CONE SIMPLE==================================================================
	
    cout << "Cone simple: " << endl;

    cout << "IG_G: " << endl << cone_simple.IG_G() << endl;

    cout << "IA_G: " << endl << cone_simple.IA_G() << endl;

    cout << "S_: " << endl << cone_simple.S_() << endl;

    cout << "P_G: " << cone_simple.S_()*cone_simple.P_O() << endl;

    cout << "P_O: " << cone_simple.P_O() << endl;

    cout << "AG_G: " << cone_simple.AG_G() << endl;

    cout << "AG_O: " << cone_simple.AG_O() << endl;

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
            cout << endl << "temps: " << temps+i*pas_de_temps << endl;
            cout << endl << "LA_a: " << cone_simple.LA_a() <<endl;
            RK.integre(pas_de_temps,cone_simple);

            cone_simple.dessine();



            cout << endl << "LA_a: " << cone_simple.LA_a();

            cout << endl << "LA_k: " << cone_simple.LA_k();

            cout << endl << "EC: " << cone_simple.EC();

            cout << endl << "E: " << cone_simple.E();
    }

///TOUPIE CHINOISE=====================================================

    cout << chinoise << endl;

    for (int i(0); i <nb_echantillons; i++){
        cout << endl << "temps: " << temps+i*pas_de_temps << endl;
        chinoise.dessine();
        EC.integre(pas_de_temps,chinoise);
        cout << "EC: " << chinoise.EC() << endl;
        cout << "E: " << chinoise.E() << endl;
    }

	return 0;
}
