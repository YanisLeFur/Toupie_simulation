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

    size_t nb_echantillons(20);

    // temps initiale de la toupie

    double temps(0);

//ConeSimple-----------------------------------------------------------------------------------------------------------------------------------

    double masse_volumique_cone(0.1);
    double hauteur_cone(1.5);
    double rayon_cone(0.5);
    Vecteur P_cone({0,M_PI/6,0});
    Vecteur P_point_cone({0,0,60});


        //méthode calculant la masse d'un cône à partir d'une masse volumique, une hauteur et un rayon
        double m_cone(masse_cone(masse_volumique_cone,hauteur_cone,rayon_cone));

        //Construction d'une toupie cônique pour l'integrateur Euler-Cromer
        ConeSimple cone_simple_EC(&text,m_cone,hauteur_cone,rayon_cone,P_cone,P_point_cone,Vecteur({1,1,1}));

        //Construction d'une toupie cônique pour l'integrateur de Newmark
        ConeSimple cone_simple_NM(cone_simple_EC);

        //Construction d'une toupie cônique pour l'integrateur Runge-Kutta
        ConeSimple cone_simple_RK(cone_simple_EC);

//ToupieChinoise-----------------------------------------------------------------------------------------------------------------------------------

        double masse_volumique(0.1);
        double hauteur(0.02);
        double rayon(0.15);

        //méthode calculant la masse d'une toupie chinoise à partir d'une masse volumique, une hauteur et un rayon
        double m_chinoise(masse_chinoise(masse_volumique,hauteur,rayon));


        //Construction d'une Toupie chinoise pour l'integrateur Euler-Cromer
        ToupieChinoise chinoise_EC(&text,m_chinoise,hauteur,rayon,Vecteur({0,0.11,0,0,0}),Vecteur({50,0,0,0,0}),Vecteur({1,2,3}));

        //Construction d'une Toupie chinoise pour l'integrateur de Newmark
        ToupieChinoise chinoise_NM(chinoise_EC);

        //Construction d'une Toupie chinoise pour l'integrateur Runge-Kutta
        ToupieChinoise chinoise_RK(chinoise_EC);


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
            cout << endl << "LA_a: " << cone_simple_EC.LA_a() <<endl;
            cout << endl << "LA_k: " << cone_simple_EC.LA_k();
            cout << endl << "E: " << cone_simple_EC.E();
            cout<<endl<<"produit mixte: "<<cone_simple_EC.prod_mixt()<<endl;

            EC.integre(pas_de_temps,cone_simple_EC);
    }

    cout << "=========TOUPIE CHINOISE==========" << endl<<endl;

    for (size_t i(0); i <nb_echantillons; i++){

            cout << endl << "temps: " << temps+i*pas_de_temps << endl;

            cout<<"--------------------------------------"<<endl;

            chinoise_EC.dessine();
            cout << "equations de mouvements: " << chinoise_EC.eq_mouv() << endl;

            cout<<"--------------------------------------"<<endl;

            //invariants du mouvement du cone
            cout << endl << "LA_a: " << chinoise_EC.LA_a() <<endl;
            cout << endl << "LA_k: " << chinoise_EC.LA_k();
            cout << endl << "E: " << chinoise_EC.E();
            cout<<endl<<"produit mixte: "<<chinoise_EC.prod_mixt()<<endl;
            EC.integre(pas_de_temps,chinoise_EC);
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

            NM.integre(pas_de_temps,cone_simple_NM);
    }

    cout << "=========TOUPIE CHINOISE==========" << endl<<endl;

    for (size_t i(0); i <nb_echantillons; i++){

            cout << endl << "temps: " << temps+i*pas_de_temps << endl;

            cout<<"--------------------------------------"<<endl;

            chinoise_NM.dessine();
            cout << "equations de mouvements: " << chinoise_NM.eq_mouv() << endl;

            cout<<"--------------------------------------"<<endl;

            //invariants du mouvement du cone
            cout << endl << "LA_a: " << chinoise_NM.LA_a() <<endl;
            cout << endl << "LA_k: " << chinoise_NM.LA_k();
            cout << endl << "E: " << chinoise_NM.E();
            cout<<endl<<"produit mixte: "<<chinoise_NM.prod_mixt()<<endl;
            NM.integre(pas_de_temps,chinoise_NM);
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

    cout << "=========TOUPIE CHINOISE==========" << endl<<endl;

    for (size_t i(0); i <nb_echantillons; i++){

            cout << endl << "temps: " << temps+i*pas_de_temps << endl;

            cout<<"--------------------------------------"<<endl;

            chinoise_RK.dessine();
            cout << "equations de mouvements: " << chinoise_RK.eq_mouv() << endl;

            cout<<"--------------------------------------"<<endl;

            //invariants du mouvement du cone
            cout << endl << "LA_a: " << chinoise_RK.LA_a() <<endl;
            cout << endl << "LA_k: " << chinoise_RK.LA_k();
            cout << endl << "E: " << chinoise_RK.E();
            cout<<endl<<"produit mixte: "<<chinoise_RK.prod_mixt()<<endl;
            RK.integre(pas_de_temps,chinoise_RK);
    }

	return 0;
}
