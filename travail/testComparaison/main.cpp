#include "comparaison.h"
#include <iostream>
#include <QApplication>
#include "Toupie.h"
#include "Dessinable.h"
#include <cmath>
#include "Vecteur.h"
#include "constant.h"
#include "Integrateur.h"
#include <vector>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Comparaison w;

//Implementation éléments=====================================================================================================

//donnees--------------------------------------------------------------------------------------------------------------------
    QVector <double> time;

    QVector<double> cone_psi;
    QVector<double> cone_theta;
    QVector<double> cone_phi;

    QVector<double> cone_psi_point;
    QVector<double> cone_theta_point;
    QVector<double> cone_phi_point;

    QVector<double> revolution_psi;
    QVector<double> revolution_theta;
    QVector<double> revolution_phi;

    QVector<double> revolution_psi_point;
    QVector<double> revolution_theta_point;
    QVector<double> revolution_phi_point;




//essentiels------------------------------------------------------------------------------------------------------------------

    //necessaire à la construction d'une toupie
    TextViewer text(std::cout);

    //Integrateur
    IntegrateurRungeKutta RK;

    //double pas de temps entre chaque point
    double pas_de_temps(0.1);

//solide de revolution---------------------------------------------------------------------------------------------------------

    //vector des rayons différents
    std::vector<double> r_i;

    //premier rayon'
    double r(0.01);
    double hauteur_sr(1.5);
    double masse_volumique_sr(0.1);

    for(int i(0); i<50 ; ++i) {
        r_i.push_back(r+i*(0.01));
    }

    //Construction d'un solide de révolution à partir: d'un support à dessin, une masse volumique, une hauteur, un tableau des rayons différents,
    //                                              un Vecteur de paramètres, un Vecteur dérivée de paramètre, un point de contact
   SolideRevolution sr(&text,masse_volumique_sr,hauteur_sr,r_i,Vecteur(0,M_PI/6,0),Vecteur(0,0,60),Vecteur());

//toupie conique----------------------------------------------------------------------------------------------------------------

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


//Transmission des valeurs pour le plot============================================================================================


   for(size_t k(0);k<250;k++){

          time.append(k*pas_de_temps);

          cone_psi.append(cone_simple.getP().get_coord(1));
          cone_psi_point.append(cone_simple.getP_point().get_coord(1));

          cone_theta.append(cone_simple.getP().get_coord(2));
          cone_theta_point.append(cone_simple.getP_point().get_coord(2));

          cone_phi.append(cone_simple.getP().get_coord(3));
          cone_phi_point.append(cone_simple.getP_point().get_coord(3));

          revolution_psi.append(sr.getP().get_coord(1));
          revolution_psi_point.append(sr.getP_point().get_coord(1));

          revolution_theta.append(sr.getP().get_coord(2));
          revolution_theta_point.append(sr.getP_point().get_coord(2));

          revolution_phi.append(sr.getP().get_coord(3));
          revolution_phi_point.append(sr.getP_point().get_coord(3));

          RK.integre(pas_de_temps,cone_simple);
          RK.integre(pas_de_temps,sr);

        }


   w.give_datas(time, cone_psi, revolution_psi, cone_theta, revolution_theta, cone_phi, revolution_phi,
                cone_psi_point, revolution_psi_point,cone_theta_point,revolution_theta_point,cone_phi_point,revolution_phi_point);




//plot=====================================================================================================
    w.plot();
    w.show();
    return a.exec();
}
