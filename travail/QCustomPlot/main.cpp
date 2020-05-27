#include "mainwindow.h"
#include <iostream>
#include <QApplication>
#include "Toupie.h"
#include "Dessinable.h"
#include <cmath>
#include "Vecteur.h"
#include "constant.h"
#include "Integrateur.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    TextViewer t(std::cout);
    IntegrateurRungeKutta RK;
    IntegrateurNewmark NM;
    IntegrateurEulerCromer EC;

//Toupie à plot ========================================================================================================
    ConeSimple c1(&t,0.039270,1.5,0.5,Vecteur({0,M_PI/6,0}),Vecteur({0,0,200}),Vecteur(4,4,0),null);
//======================================================================================================================

//Plot invariants avec Runge-Kutta====================================================================================================
    QVector<double> time;
    QVector<double> y_energie_RK;
    QVector<double> y_prod_mixt_RK;
    QVector<double> y_LA_a_RK;
    QVector<double> y_LA_k_RK;

    for(size_t k(0);k<250;k++){
       y_prod_mixt_RK.append(c1.prod_mixt());
       y_energie_RK.append(c1.E());
       y_LA_a_RK.append(c1.LA_a());
       y_LA_k_RK.append(c1.LA_k());
        RK.integre(0.1,c1);
        time.append(0.1*k);

    }
//======================================================================================================================

//Plot invariants avec Newmark==========================================================================================
    QVector<double> y_energie_NM;
    QVector<double> y_prod_mixt_NM;
    QVector<double> y_LA_a_NM;
    QVector<double> y_LA_k_NM;

    for(size_t k(0);k<250;k++){
       y_prod_mixt_NM.append(c1.prod_mixt());
       y_energie_NM.append(c1.E());
       y_LA_a_NM.append(c1.LA_a());
       y_LA_k_NM.append(c1.LA_k());
       NM.integre(0.1,c1);

        }
//======================================================================================================================

//Plot invariants avec Euler-Cromer==========================================================================================
    QVector<double> y_energie_EC;
    QVector<double> y_prod_mixt_EC;
    QVector<double> y_LA_a_EC;
    QVector<double> y_LA_k_EC;

    for(size_t k(0);k<250;k++){
       y_prod_mixt_EC.append(c1.prod_mixt());
       y_energie_EC.append(c1.E());
       y_LA_a_EC.append(c1.LA_a());
       y_LA_k_EC.append(c1.LA_k());
       EC.integre(0.1,c1);

     }
//======================================================================================================================

    w.give_datas(time, y_energie_RK, y_prod_mixt_RK, y_LA_a_RK, y_LA_k_RK,
               y_energie_NM, y_prod_mixt_NM, y_LA_a_NM, y_LA_k_NM,
               y_energie_EC, y_prod_mixt_EC, y_LA_a_EC, y_LA_k_EC);
    w.plot();
    w.show();
    return a.exec();
}
