#include <iostream>
#include <cmath>
#include "Toupie.h"
#include "constant.h"
#include "Vecteur.h"
#include "Dessinable.h"
#include <cmath>

using namespace std;

int main(){

    TextViewer text(cout); //permet l'affichage textuel

//Pendule==========================================================================================================================================================

    cout << "=========PENDULE==========" << endl<<endl;
	double masse_sinus(1);

    //Construction pendule avec (Support à dessin, masse, Vecteur de paramètre, Vecteur de derivée des paramètres, Point de contact)
    //on modelise le pendule en coordonnées cylindriques
    Pendule pendule(&text,masse_sinus,Vecteur({M_PI/6,0,0}),Vecteur({0,0,60}),Vecteur(0,1,2));

    cout<<"--------------------------------------"<<endl;

    // test l'affichage  des attributsd'un pendule
    cout << pendule;

    cout<<"--------------------------------------"<<endl;

    //donne les composantes du Vecteur paramètre et dérivée des paramètre au temps t=0
    cout<<"Au temps t=0 :"<<endl;
    pendule.dessine();

    //donne les équations de mouvements/accélération du pendule au temps t=0
    cout << "Le vecteur acceleration de la toupie est " << pendule.eq_mouv() << endl;

    //donne la position du centre de masse (G) au temps t=0
    pendule.trace_G();

    cout<<"--------------------------------------"<<endl;

    //Energie potentielle du pendule
    cout<<"L'énergie potentielle du pendule est: "<<pendule.EP()<<endl;

    //Energie cinétique du pendule
    cout<<"L'énergie cinétique du pendule est: "<<pendule.EC()<<endl;

    //Energie totale du pendule
    cout<<"L'énergie totale du pendule est: "<<pendule.E()<<endl;

    cout<<"--------------------------------------"<<endl<<endl;



//ConeSimple=======================================================================================================================================================

    cout << endl << "==========CONE SIMPLE==========" << endl<<endl;
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

    cout<<"--------------------------------------"<<endl;

    // test l'affichage  des attributs d'un cone simple
    cout << cone_simple;

    cout<<"--------------------------------------"<<endl;


    //donne les composantes du Vecteur paramètre et dérivée des paramètre au temps t=0
    cout<<"Au temps t=0 :"<<endl;
    cone_simple.dessine();

    //donne les équations de mouvements/accélération d'une toupie conique au temps t=0
    cout << "Le vecteur acceleration de la toupie est " << cone_simple.eq_mouv() << endl;

    //donne la position du centre de masse (G) au temps t=0
    cone_simple.trace_G();

    cout<<"--------------------------------------"<<endl;

    //Energie totale de la toupie côniqe
    cout<<"L'énergie totale du cône est: "<<cone_simple.E()<<endl;

    cout<<"--------------------------------------"<<endl<<endl;

//Masse qui tombe==========================================================================================================================================================

    cout << endl << "==========MASSE QUI TOMBE==========" << endl<<endl;

    //Construction d'une masse en chute libre à partir: d'un support à dessin, une masse, un Vecteur de paramètres
    //                                              un Vecteur dérivée de paramètre
    MasseTombe masse_tombe(&text,1,Vecteur({10,100,1}), Vecteur({2,2,1}));

    cout<<"--------------------------------------"<<endl;
    // test l'affichage  des attributs d'une masse en chute libre
    cout << masse_tombe;

    cout<<"--------------------------------------"<<endl;

    //donne les composantes du Vecteur paramètre et dérivée des paramètre au temps t=0
    cout<<"Au temps t=0 :"<<endl;
    masse_tombe.dessine();

    //donne les équations de mouvements/accélération de la masse en chute libre
    cout << "Le vecteur acceleration de la toupie est " << masse_tombe.eq_mouv() << endl;

    //donne la position du centre de masse (G) au temps t=0
    masse_tombe.trace_G();

    cout<<"--------------------------------------"<<endl;

    //Energie potentielle de la masse en chute libre
    cout<<"L'énergie potentielle de la masse est: "<<masse_tombe.EP()<<endl;

    //Energie cinétique de la masse en chute libre
    cout<<"L'énergie cinétique de la masse est: "<<masse_tombe.EC()<<endl;

    //Energie totale de la masse en chute libre
    cout<<"L'énergie totale de la masse est: "<<masse_tombe.E()<<endl;

    cout<<"--------------------------------------"<<endl<<endl;


//Toupie Chinoise==========================================================================================================================================================

    cout << endl << "==========TOUPIE CHINOISE==========" << endl<<endl;
    double masse_volumique(0.1);
    double hauteur(0.02);
    double rayon(0.15);

    //méthode calculant la masse d'une toupie chinoise à partir d'une masse volumique, une hauteur et un rayon
    double m_chinoise(masse_chinoise(masse_volumique,hauteur,rayon));


    //Construction d'une Toupie chinoise à partir: d'un support à dessin, une masse, une hauteur, un rayon,
    //                                              un Vecteur de paramètres, un Vecteur dérivée de paramètre, un point de contact
    ToupieChinoise chinoise(&text,m_chinoise,hauteur,rayon,Vecteur({0,0.11,0,0,0}),Vecteur({50,0,0,0,0}),Vecteur({1,2,3}));

    cout<<"--------------------------------------"<<endl;
    // test l'affichage  des attributs d'une toupie chinoise
    cout << chinoise;

    cout<<"--------------------------------------"<<endl;

    //donne les composantes du Vecteur paramètre et dérivée des paramètre au temps t=0
    cout<<"Au temps t=0 :"<<endl;
    chinoise.dessine();

    //donne les équations de mouvements/accélération d'une toupie chinoise
    cout << "Le vecteur acceleration de la toupie est " << chinoise.eq_mouv() << endl;

    //donne la position du centre de masse (G) au temps t=0
    masse_tombe.trace_G();

    cout<<"--------------------------------------"<<endl;

    //Vecteur du centre de masse au centre géométrique de la toupie chinoise en fonction du référentiel de la toupie
    cout<<"Vecteur GC_G: "<<chinoise.GC_G()<<endl;

    //Vecteur du centre de masse au centre géométrique de la toupie chinoise en fonction du référentiel intertiel
    cout<<"Vecteur GC_O: "<<chinoise.GC_O()<<endl;

    //Vecteur du point de contact au centre géométrique de la toupie chinoise en fonction du référentiel de la toupie
    cout<<"Vecteur AC_G: "<<chinoise.AC_G()<<endl;

    //Vecteur du point de contact  au centre géométrique de la toupie chinoise en fonction du référentiel intertiel
    cout<<"Vecteur AC_G: "<<chinoise.AC_O()<<endl;

    //Vecteur du point de contact au centre de masse de la toupie chinoise en fonction du référentiel de la toupie
    cout<<"Vecteur AG_G: "<<chinoise.AG_G()<<endl;

    //Vecteur du point de contact  au centre de masse de la toupie chinoise en fonction du référentiel de la toupie
    cout<<"Vecteur AG_O: "<<chinoise.AG_O()<<endl;

    //vitesse du point C dans le référentiel inertiel
    cout<<"Vecteur vC_O: "<<chinoise.vC_O()<<endl;

    //dérivée du déplacement du point C (centre géométrique) dans l'axe x
     cout<<"Vecteur P4_point_point: "<<chinoise.P4_point_point()<<endl;

    //dérivée du déplacement du point C (centre géométrique) dans l'axe y
    cout<<"Vecteur P5_point_point: "<<chinoise.P5_point_point()<<endl;

    cout<<"--------------------------------------"<<endl<<endl;


//Solide de Révolution==========================================================================================================================================================

        cout << endl << "==========SOLIDE REVOLUTION==========" << endl<<endl;

        //vector des rayons différents
        vector<double> r_i;

        //premier rayon'
        double r(0.01);
        double hauteur_sr(1.5);
        double masse_volumique_sr(0.1);

        for(int i(0); i<50 ; ++i) {
            r_i.push_back(r+i*(0.01));
        }

        //Construction d'un solide de révolution à partir: d'un support à dessin, une masse volumique, une hauteur, un tableau des rayons différents,
        //                                              un Vecteur de paramètres, un Vecteur dérivée de paramètre, un point de contact
       SolideRevolution sr(&text,masse_volumique_sr,hauteur_sr,r_i,Vecteur(0,M_PI/6,0),Vecteur(0,0,200),Vecteur());

       cout<<"--------------------------------------"<<endl;
       // test l'affichage  des attributs du solide de révolution
       cout << sr;

       cout<<"--------------------------------------"<<endl;

       //donne les composantes du Vecteur paramètre et dérivée des paramètre au temps t=0
       cout<<"Au temps t=0 :"<<endl;
       sr.dessine();

       //donne les équations de mouvements/accélération du solide de révolution
       cout << "Le vecteur acceleration de la toupie est " << sr.eq_mouv() << endl;

       //donne la position du centre de masse (G) au temps t=0
       sr.trace_G();

       cout<<"--------------------------------------"<<endl;

//Toupie general==========================================================================================================================================================

       cout << endl << "==========TOUPIE GENERAL==========" << endl<<endl;

       /* Construction d'une toupie general à partir : d'un support à dessin, une masse,un Vecteur de parametres,
        *                                              un Vecteur dérivée de paramètres, des coefficients du tenseur d'inertie(I1,I3)
        *                                              une distance (entre le centre de masse et le point de contact),
        *                                              et un point de contact
        *
        * à noter: ici on construit une toupie générale avec des attributs similaires au cône vu plus haut pour vérifier que les
        * deux toupies ont les mêmes valeurs
        */
       Toupie toupie_general(&text,m_cone,P_cone,P_point_cone,3.*(m_cone/20.)*(rayon_cone*rayon_cone+1./4.*hauteur_cone*hauteur_cone),
                             3.*m_cone/10.*rayon_cone*rayon_cone,hauteur_cone*3./4.,Vecteur({1,1,1}));

       cout<<"--------------------------------------"<<endl;

       cout<<"Toupie de type general:"<<endl<<toupie_general;

       cout<<"--------------------------------------"<<endl;

       //donne les composantes du Vecteur paramètre et dérivée des paramètre au temps t=0
       cout<<"Au temps t=0 :"<<endl;
       toupie_general.dessine();

       //donne les équations de mouvements/accélération de la toupie general
       cout << "Le vecteur acceleration de la toupie est " << toupie_general.eq_mouv() << endl;

       //donne la position du centre de masse (G) au temps t=0
       toupie_general.trace_G();

       cout<<"--------------------------------------"<<endl;

       //Energie cinétique de la toupie general
       cout<<"L'énergie cinétique de la toupie general est: "<<toupie_general.EC()<<endl;

       //Energie totale de la toupie general
       cout<<"L'énergie totale de la toupie general est: "<<toupie_general.E()<<endl;

       //produit mixte de la toupie general
       cout<<"produit mixte: "<<toupie_general.prod_mixt()<<endl;

       //moment cinetique au point de contact autour de l'axe a
       cout<<"LA_a: "<<toupie_general.LA_a()<<endl;

       //moment cinetique au point de contact autour de l'axe a
        cout<<"LA_k: "<<toupie_general.LA_k()<<endl;


       cout<<"--------------------------------------"<<endl;

       //vecteur rotation omega selon le referentiel de la toupie
       cout<<"Omega_G: "<<toupie_general.omega_G()<<endl;

       //vecteur rotation omega selon le referentiel inertiel
       cout<<"Omega_O: "<<toupie_general.omega_O()<<endl;

       //derivee du vecteur rotation omega selon le referentiel de la toupie
       cout<<"Omega_point_G: "<<toupie_general.omega_point_G()<<endl;

       //derivee du vecteur rotation omega selon le referentiel inertiel
       cout<<"Omega_point_O: "<<toupie_general.omega_point_O()<<endl;

       //Moment de force au point de contact dans le referentiel de la toupie
       cout<<"MA_G: "<<toupie_general.MA_G()<<endl;

       //Moment de force au point de contact dans le referentiel d'inertie
       cout<<"MA_O: "<<toupie_general.MA_O()<<endl;

       //Moment cinetique au point de contact dans le referentiel de la toupie
       cout<<"LA_G: "<<toupie_general.LA_G()<<endl;

       //Moment cinetique au point de contact dans le referentiel d'inertie
       cout<<"LA_O: "<<toupie_general.LA_O()<<endl;

       //Moment cinetique au centre de masse dans le referentiel de la toupie
       cout<<"LG_G: "<<toupie_general.LG_G()<<endl;

       //Moment cinetique au centre de masse dans le referentiel d'inertie
       cout<<"LG_O: "<<toupie_general.LG_O()<<endl;

       cout<<"--------------------------------------"<<endl;


//Gestion des erreurs==========================================================================================================================================================
       try {
           //test d'une toupie avec une masse nulle
           Toupie toupie_erreur_1(&text,0,P_cone,P_point_cone,0,1,1,Vecteur({1,1,1}));
       }
       catch (int i) {
           cout<<"test";
       }





       try {
           //test d'une toupie avec un rayon nul
           Toupie toupie_erreur_2(&text,1,P_cone,P_point_cone,0,1,1,Vecteur({1,1,1}));
       }
       catch (int const& i) {
               if (i==5) cout<<"tesy";

       }


	return  0;
}
