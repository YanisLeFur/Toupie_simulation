#include <QApplication>
#include "glwidget.h"
#include "Toupie.h"
#include "Dessinable.h"
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(int argc, char* argv[]) {

  QApplication a(argc, argv);

//Creation du Widget-------------------------------------------------------------------------------------------------------------

  GLWidget w;

  // crée une fenêtre plus grande dès l'execution

  w.setMinimumSize(1080,720);

//Nos support a dessin----------------------------------------------------------------------------------------------------

  VueOpenGL* v(w.get_Vue_ptr());
  TextViewer text(cout);

//Nos integrateurs-----------------------------------------------------------------------------------------------------------

  // notre widget contient un systeme qui utilise un integrateur

  // de Runge-Kutta par default (car c'est le plus performant)

  // si l'utilisateur voudrais utiliser un autre integrateur

  // il suffit d'utiliser la methode changer_integrateur

  // du widget (par exemple w.changer_integrateur(EC))

  IntegrateurEulerCromer EC;
  IntegrateurNewmark NM;
  IntegrateurRungeKutta RK;

//Implémentation des objets----------------------------------------------------------------------------------------------------  

  // on construit un pendule (dessine avec VueOpenGL), de masse 1kg

  // de longueur 2m, inclinee initiallement

  // a un angle de 3PI/4 radians par rapport a la verticale

  // avec une vitesse initialle nul, accroche en (1,0,5)

  // avec une trace de son centre de masse

  Pendule p1(v,1,Vecteur(2,3*M_PI/4,0),Vecteur(0,0,0),Vecteur(1,0,5),true);

  // on construit un autre pendule (toujours dessine sur VueOpenGL), de masse 2kg

  // de longueur 1m, inclinee initiallement

  // a un angle de PI/2 radians par rapport a la verticale

  // avec une vitesse tangentielle initialle, accroche en (-1.5,-1,4)

  // sans trace de son centre de masse

  Pendule p2(v,2,Vecteur(1,M_PI/2,0),Vecteur(0,0.5,0),Vecteur(-1.5,-1,4),false);

  // on construit une masse tombante (dessine avec VueOpenGL), de masse 1kg,

  // initiallement a l'origine, avec une vitesse initialle de (-3,25,25)

  // avec une trace de son centre de masse

  MasseTombe mt1(v,1,Vecteur(0,0,0),Vecteur(3,25,25),true);

  // on construit une autre masse tombante, de masse 0.5kg,

  // initiallement a (-20,-24,5), avec une vitesse initialle de (12,0,15)

  // sans trace de son centre de masse

  MasseTombe mt2(v,0.5,Vecteur(-20,24,5),Vecteur(12,0,15),false);

  // on construit un cone simple (dessine avec VueOpenGL),

  // de masse volumique 0.1kg/m^3,

  // avec une hauteur de 1.5m, un rayon de 0.5m,

  // initiallement incline d'un angle de PI/6 radians par rapport a la verticale

  // avec une rotation propre initialle de 200 radians par seconde

  // avec comme point de contact (4,4,0),

  // qui ne varie pas de couleur

  // avec une trace de son centre de masse

  ConeSimple c1(v,masse_cone(0.1,1.5,0.5),1.5,0.5,Vecteur(0,M_PI/6,0),Vecteur(0,0,200),Vecteur(4,4,0),null,true);

  // on construit un autre cone simple (dessine avec VueOpenGL),

  // de masse 0.075kg, de rayon 3m, de hauteur 0.75m,

  // initiallement incline d'un angle de PI/12 radians par rapport a la verticale

  // avec une precession initialle de 5 radians par seconde

  // avec une rotation propre initialle de 150 radians par seconde

  // avec comme point de contact (-4,4,0),

  // qui varie de couleur (d'un vert claire a un vert fonce) en dependance

  // de la grandeur de sa vitesse angulaire de nutation (theta point)

  // sans trace de son centre de masse

  ConeSimple c2(v,0.075,3,0.75,Vecteur(0,M_PI/12,0),Vecteur(5,0,150),Vecteur(-4,4,0),theta_point,false);

  // on construit une toupie chinoise (dessine avec VueOpenGL)

  // de masse volumique 0.1kg/m^3, de hauteur tronquee 0.25m,

  // de rayon 2m, incline initiallement d'un angle de 0.5 radians

  // par rapport a la verticale, avec une precession initialle

  // de 20 radians par seconde, avec un point de contact initiallement en (-5,6,0)

  // qui varie de couleur (d'un bleu claire a un bleu fonce) en dependance

  // de la grandeur de la vitesse de rotation propre (phi point)

  // sans trace de son centre de masse

  ToupieChinoise tc1(v,masse_chinoise(0.1,0.25,2),0.25,2,Vecteur({0,0.5,0,0,0}),Vecteur({20,0,0,0,0}),Vecteur(-5,6,0),phi_point,false);

  // on construit une autre toupie chinoise (dessine avec VueOpenGL)

  // avec une masse de 0.7kg, une hauteur tronquee de 0.1m, un rayon 0.3m,

  // incline initiallement d'un angle de 0.5 radians

  // par rapport a la verticale, avec une precession initialle

  // de 15 radians par seconde, avec un point de contact initiallement en (3,4,0)

  // qui ne varie pas de couleur, avec la trace de son centre de masse

  ToupieChinoise tc2(v,0.7,0.1,0.3,Vecteur({0,0.5,0,0,0}),Vecteur({15,0,5,0,0}),Vecteur(5,4,0),null,true);

  // on construit maintenant un solide de revolution

  // (dessine sur VueOpenGL), avec une masse volumique de 0.1kg/m^3,

  // une hauteur de 1.5m, un ensemble de rayons correspondant

  // a la forme d'un cone de hauteur 1.5m et de rayon 0.5m,

  // initiallement incline d'un angle de PI/6 radians par rapport a la verticale,

  // avec une rotation propre initialle de 200 radians par seconde

  // avec comme point de contact (4,4,0),

  // qui ne varie pas de couleur

  // avec une trace de son centre de masse

  vector<double> r_i_1;

  double r_0_1(0.001);

  for(int i(0); i<500 ; ++i) {
      r_i_1.push_back(r_0_1+i*(0.001));
  }

  SolideRevolution sr1(v,0.1,1.5,r_i_1,Vecteur(0,M_PI/6,0),Vecteur(0,0,200),Vecteur(0,3,0),null,true);

  // on construit un autre solide de revolution (dessine par VueOpenGL),

  // avec une masse volumique de 0.1kg/m^3,

  // une hauteur de 4m, et un vecteur de rayon donnant une forme interessante,

  // initiallement incline d'un angle de PI/12 radians par rapport a la verticale,

  // avec une precession initialle de 5 radians par seconde,

  // avec une rotation propre initialle de 200 radians par seconde,

  // avec un point de contact en (-4,-4,0),

  // qui ne varie pas de couleur

  // sans trace de son centre de masse

  vector<double> r_i_2;

  double r_0_2(0.0183);

  for(int i(0); i<400; ++i) {
      r_i_2.push_back(r_0_2+exp(-pow(((i*0.01)-2),2)));
  }

  SolideRevolution sr2(v,0.1,4,r_i_2,Vecteur(0,M_PI/12,0),Vecteur(5,0,200),Vecteur(0,3,0),theta_point,false);

  // construction d'un ConeSimple et un Solide de Revolution pour

  // la comparaison entre une toupie de type ConeSimple

  // et une toupie generale (SolideRevolution)

  ConeSimple c3(v,masse_cone(0.1,1.5,0.5),1.5,0.5,Vecteur(0,M_PI/6,0),Vecteur(0,0,200),Vecteur(0,3,0),null,false);

  SolideRevolution sr3(v,0.1,1.5,r_i_1,Vecteur(0,M_PI/6,0),Vecteur(0,0,200),Vecteur(0,3,0),null,false);

  // construction d'un ConeSimple identique a c3

  // avec un support a dessin textuel

  ConeSimple c4(&text,masse_cone(0.1,1.5,0.5),1.5,0.5,Vecteur(0,M_PI/6,0),Vecteur(0,0,200),Vecteur(0,3,0),null,false);


//*********************************************************************
//*********************************************************************


//Nos Simulations Differentes=================================================================================================

  // Nous presentons ici 8 simulations differentes.

  // Pour les executer, il suffit de demasquer

  // l'ajout des toupies de la simulation voulu

  // et de masquer les autres simulations.

  // On fait ceci car la performance de la simulation

  // est reduite par l'ajout de trop d'objets.

  // Les toupies utilise dans la simulation sont afficher

  // textuellement a cote de la simulation graphique (sur cout)


//Simulation 1 : Nos Cones Simples==============================================================================================

  // on presente ici les 2 ConeSimples decrits plus haut


  w.ajouter_Toupie(c1);
  w.ajouter_Toupie(c2);


//Simulation 2 : Nos Toupies Chinoises===========================================================================================

  // on presente ici les 2 ToupieChinoises decrites plus haut

  // celle de droite a une vitesse initialle importante

  // qui lui permet de se deplacer plus vite


  //w.ajouter_Toupie(tc1);
  //w.ajouter_Toupie(tc2);


//Simulation 3 : Comparaison entre un ConeSimple==================================================================================
//et un Solide de Revolution (Toupie Generale)====================================================================================

  // comparaison graphique d'un ConeSimple

  // et notre modele d'une toupie generale


  //w.ajouter_Toupie(c3);
  //w.ajouter_Toupie(sr3);


//Simulation 4 : Nos Solides de Revolutions=======================================================================================

  // NB : a simuler un par un pour des raisons de lag

  // on presente ici les 2 Solides de Revolution decrits plus haut

  // cone


  //w.ajouter_Toupie(sr1);


  // cree par une revolution de la courbe Gaussienne autour de l'axe z


  //w.ajouter_Toupie(sr2);


//Simulation 5 : La vue tangentielle sur un ConeSimple==================================================================================

  // appuyer sur la touche V pour activer

  // et desactiver la vue tangentielle

  // on choisi ici de ne pas prendre la rotation propre

  // en compte car on ne peut rien y voir


  //w.ajouter_Toupie(c2);


//Simulation 6 : Affichage graphique et textuelle======================================================================================

  // simulation simultanement graphique et textuelle

  // d'une toupie conique


  //w.ajouter_Toupie(c3);
  //w.ajouter_Toupie(c4);


//Simulation 7 : Nos Pendules============================================================================================================

  // on presente ici les 2 Pendules decrits plus haut


  //w.ajouter_Toupie(p1);
  //w.ajouter_Toupie(p2);


//Simulation 8 : Nos Masse Tombante======================================================================================================

  // on presente ici les 2 Masses Tombantes decrites plus haut


  //w.ajouter_Toupie(mt1);
  //w.ajouter_Toupie(mt2);


//*********************************************************************
//*********************************************************************

  // affiche les toupies simules

  w.affiche(cout);

  // on affiche le widget

  w.show();

  // on gere la memoire du pointeur sur le VueOpenGL

  // du Widget

  return a.exec();
}
