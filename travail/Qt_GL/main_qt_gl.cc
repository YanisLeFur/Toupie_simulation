#include <QApplication>
#include "glwidget.h"
#include "Toupie.h"
#include "iostream"

int main(int argc, char* argv[])
{
  QApplication a(argc, argv);
  GLWidget w;
  VueOpenGL* v(w.get_Vue_ptr());
  ///Pendule p(v,1,Vecteur({0,3*PI/4,0}),Vecteur({0,0,0}),2);
  ///MasseTombe mt(v,1,Vecteur({0,0,0}),Vecteur({0,5,5}));
  ConeSimple c(v,0.039270,1.5,0.5,Vecteur({0,PI/6,0}),Vecteur({0,0,200}),Vecteur());
  ///w.ajouter_Toupie(p);
  ///w.ajouter_Toupie(mt);
  w.ajouter_Toupie(c);
  ///w.affiche(std::cout);
  w.show();

  return a.exec();
}
