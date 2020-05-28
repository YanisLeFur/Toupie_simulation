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

    // notre support a dessin textuelle

    TextViewer text(cout);

    //Intégrateurs---------------------

    IntegrateurRungeKutta RK;
    IntegrateurNewmark NM;
    IntegrateurEulerCromer EC;

    //----------------------------------

    // pas de temps pour l'integration des toupies

    double pas_de_temps(0.01);

    // nombre de fois que la toupie sera integrer selon le pas de temps

    size_t nb_echantillons(200);

    // temps initiale de la toupie

    double temps(0);

//ConeSimple-----------------------------------------------------------------------------------------------------------------------------------

    double masse_volumique_cone(0.1);
    double hauteur_cone(1.5);
    double rayon_cone(0.5);
    Vecteur P_cone({0,M_PI/6,0});
    Vecteur P_point_cone({0,0,60});

    double m_cone(masse_cone(masse_volumique_cone,hauteur_cone,rayon_cone));

    //Construction d'une toupie cônique pour l'integrateur Euler-Cromer

    ConeSimple cone_simple_EC(&text,m_cone,hauteur_cone,rayon_cone,P_cone,P_point_cone,Vecteur({1,1,1}));

    //Construction d'une toupie cônique pour l'integrateur de Newmark

    ConeSimple cone_simple_NM(cone_simple_EC);

    //Construction d'une toupie cônique pour l'integrateur Runge-Kutta

    ConeSimple cone_simple_RK(cone_simple_EC);

//COMPARAISON DES INTEGRATEURS ET TEST DES INVARIANTS============================================================

    cout << "Nous lancons maintenant une simulation permettant de comparer ";

    cout << "nos divers Integrateurs et de verifier l'invariance de ";

    cout << "certaines de nos grandeur physique." << endl << endl;

    for (size_t i(0); i<nb_echantillons ; ++i) {
        cout << endl << "temps: " << temps+i*pas_de_temps << endl;





        // invariants du mouvement du cone

        cout << endl << "LA_a : " << cone_simple_RK.LA_a();

        cout << endl << "LA_k : " << cone_simple_RK.LA_k();

        cout << endl << "E : " << cone_simple_RK.E();

        cout << endl << "produit mixte : " << cone_simple_RK.prod_mixt()<<endl;

        EC.integre(pas_de_temps,cone_simple_EC);

        NM.integre(pas_de_temps,cone_simple_NM);
    }

//EULER-CROMER====================================================================================================

    cout<<"==================EULER-CROMER=================="<<endl;
    cout<<"================================================"<<endl;


    cout << "=========CONE SIMPLE==========" << endl<<endl;

    for (size_t i(0); i <nb_echantillons; i++){

            cout << endl << "temps: " << temps+i*pas_de_temps << endl;

            cout<<"--------------------------------------"<<endl;

            cone_simple_EC.dessine();
            cout << "eq_mouv: " << cone_simple_EC.eq_mouv() << endl;

            cout<<"--------------------------------------"<<endl;

            //invariants du mouvement du cone
            cout << endl << "LA_a: " << cone_simple_EC.LA_a();
            cout << endl << "LA_k: " << cone_simple_EC.LA_k();
            cout << endl << "E: " << cone_simple_EC.E();
            cout << endl <<"produit mixte: "<< cone_simple_EC.prod_mixt()<<endl;

            EC.integre(pas_de_temps,cone_simple_EC);
    }


    cout<<"==================NEWMARK=================="<<endl;
    cout<<"================================================"<<endl;


    cout << "=========CONE SIMPLE==========" << endl<<endl;

    for (size_t i(0); i <nb_echantillons; i++){

            cout << endl << "temps: " << temps+i*pas_de_temps << endl;

            cout<<"--------------------------------------"<<endl;

            cone_simple_NM.dessine();
            cout << "eq_mouv: " << cone_simple_NM.eq_mouv() << endl;

            cout<<"--------------------------------------"<<endl;

            //invariants du mouvement du cone
            cout << endl << "LA_a: " << cone_simple_NM.LA_a() <<endl;
            cout << endl << "LA_k: " << cone_simple_NM.LA_k();
            cout << endl << "E: " << cone_simple_NM.E();
            cout<<endl<<"produit mixte: "<<cone_simple_NM.prod_mixt()<<endl;


    }




    cout<<"==================RUNGE-KUTTA=================="<<endl;
    cout<<"================================================"<<endl;


    cout << "=========CONE SIMPLE==========" << endl<<endl;

    for (size_t i(0); i <nb_echantillons; i++){

            cout << endl << "temps: " << temps+i*pas_de_temps << endl;

            cout<<"--------------------------------------"<<endl;

            cone_simple_RK.dessine();
            cout << "eq_mouv: " << cone_simple_RK.eq_mouv() << endl;

            cout<<"--------------------------------------"<<endl;

            //invariants du mouvement du cone
            cout << endl << "LA_a: " << cone_simple_RK.LA_a() <<endl;
            cout << endl << "LA_k: " << cone_simple_RK.LA_k();
            cout << endl << "E: " << cone_simple_RK.E();
            cout<<endl<<"produit mixte: "<<cone_simple_RK.prod_mixt()<<endl;

            RK.integre(pas_de_temps,cone_simple_RK);
    }



	return 0;
}
