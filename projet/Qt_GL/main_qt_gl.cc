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

//Implémentation de la vue----------------------------------------------------------------------------------------------------

  VueOpenGL* v(w.get_Vue_ptr());

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

  // initiallement a (0,1,1), avec une vitesse initialle de (-5,20,20)

  // sans trace de son centre de masse

  MasseTombe mt2(v,0.5,Vecteur(0,1,1),Vecteur(-5,20,20),false);

  // on construit un cone simple (dessine avec VueOpenGL),

  // de masse volumique 0.1kg/m^3,

  // avec une hauteur de 1.5m, un rayon de 0.5m,

  // initiallement incline d'un angle de PI/6 radians par rapport a la verticale

  // avec une rotation propre initialle de 200 radians par seconde

  // avec comme point de contact (4,4,0),

  // qui ne varie pas de couleur

  // avec une trace de son centre de masse

  ConeSimple c1(v,0.039270,1.5,0.5,Vecteur(0,M_PI/6,0),Vecteur(0,0,200),Vecteur(4,4,0),null,true);

  // on construit un autre cone simple (dessine avec VueOpenGL),

  // de masse 0.075kg, de rayon 3m, de hauteur 0.75m,

  // initiallement incline d'un angle de PI/12 radians par rapport a la verticale

  // avec une precession initialle de 5 radians par seconde

  // avec une rotation propre initialle de 150 radians par seconde

  // avec comme point de contact (-4,4,0),

  // qui varie de couleur (d'un vert claire a un vert fonce)

  // sans trace de son centre de masse

  ConeSimple c2(v,0.075,3,0.75,Vecteur(0,M_PI/12,0),Vecteur(5,0,150),Vecteur(-4,4,0),theta_point,false);

  // on construit une toupie chinoise (dessine avec VueOpenGL)

  // de masse volumique 0.1kg/m^3, de hauteur tronquee 0.02m,

  // de rayon 0.15m, incline initiallement d'un angle de 0.11 radians

  // par rapport a la verticale, avec une precession initialle

  // de 25 radians par seconde, avec un point de contact en (0,4,0)




  ToupieChinoise tc1(v,masse_chinoise(0.1,0.02,0.15),0.02,0.15,Vecteur({0,0.11,0,0,0}),Vecteur({25,0,0,0,0}),Vecteur(0,4,0),phi_point);
  ToupieChinoise tc2(v,0.7,0.1,0.3,Vecteur({0,0.5,0,0,0}),Vecteur({15,0,0,0,0}),Vecteur(0,0,0));

  vector<double> r_i;

  double r(0.01);
  double L(1.5);
  double rho(0.1);

  for(int i(0); i<50 ; ++i) {
      r_i.push_back(r+i*(0.01));
  }

  SolideRevolution sr(v,rho,L,r_i,Vecteur(0,M_PI/6,0),Vecteur(0,0,200),Vecteur(),phi_point,false);

//ajout de Toupies=================================================================================================

//*****************************modifier ici****************************
//*********************************************************************

  //w.ajouter_Toupie(p1);
  //w.ajouter_Toupie(p2);
  //w.ajouter_Toupie(mt1);
  //w.ajouter_Toupie(mt2);
  //w.ajouter_Toupie(c1);
  //w.ajouter_Toupie(c2);
  w.ajouter_Toupie(tc1);
  //w.ajouter_Toupie(tc2);
  //w.ajouter_Toupie(sr);
  w.affiche(std::cout);

  //*********************************************************************
  //*********************************************************************

  w.show();
  v = nullptr;
  delete v;
  return a.exec();
}
