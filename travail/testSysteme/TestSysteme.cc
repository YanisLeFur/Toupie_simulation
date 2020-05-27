#include <iostream>
#include "Systeme.h"
#include "Dessinable.h"
#include "Vecteur.h"
#include "Integrateur.h"
#include "Toupie.h"
#include "Matrice.h"
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

    //le systeme prends pour integrateur de référence celui de Newmark
    Systeme systeme(EC);

    //pas de temps pour l'integration des toupies
    double pas_de_temps(0.01);

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

    //Place les toupies déclarées plus haut dans le systeme lui aussi déclaré tout en haut
    systeme.ajouter_Toupie(pendule);
    systeme.ajouter_Toupie(cone_simple);
    systeme.ajouter_Toupie(masse_tombe);
    systeme.ajouter_Toupie(chinoise);
    systeme.ajouter_Toupie(sr);
    systeme.ajouter_Toupie(toupie_general);


    //affiche toutes les toupies dans le systeme
    cout<<systeme;


    //evolution du systme
    cout<<"Le système évolue et se dessine à chaque pas (dt="<<pas_de_temps<<") :"<<endl;
    //evolution du systeme selon un pas de temps et un nombre de fois ici 11.
    try {
       systeme.evolue(pas_de_temps,11);
    }catch (int i) {
        switch(i) {
          case 1:cout << "Erreur: division par 0 impossible" << endl;
          break;
          case 2:cout << "Erreur: dimension du vecteur differente de 3" << endl;
          break;
          case 3:cout << "Erreur: dimension incompatible avec celle du vecteur" << endl;
          break;
          case 4:cout<<"Erreur: masse de la toupie nulle"<<endl;
          break;
          case 5:cout<<"Erreur: rayon de la toupie nul"<<endl;
          break;
          case 6:cout<<"Erreur: coefficient du tenseur d'inertie (I1) nul"<<endl;
          break;
          case 7:cout<<"Erreur: coefficient du tenseur d'inertie (I3) nul"<<endl;
          break;
          case 8:cout<<"Erreur: hauteur de la toupie nulle"<<endl;
          break;
          case 9:cout<<"Erreur: theta du Vecteur paramètre de la toupie nul"<<endl;
          break;
          case 10:cout<<"Erreur: rayon de la toupie négatif"<<endl;
          break;
          case 11:cout<<"Erreur: hauteur de la toupie négative"<<endl;
          break;
          case 12:cout<<"Erreur: le solide de révolution ne comporte aucun rayon"<<endl;
          break;
          case 13:cout<<"Erreur: tous les rayons du solide de revolution sont nuls"<<endl;
          break;
          case 14: cout<<"Erreur distance entre le centre de masse et le point de contact est nul"<<endl;
          break;
        }
    }







    return 0;
}
