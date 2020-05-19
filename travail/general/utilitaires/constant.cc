#include <iostream>
#include "Vecteur.h"
#include "constant.h"
using namespace std;

extern const double g(9.81);

extern const Vecteur grav({0.0,0.0,-9.81});

extern const double precision(1e-18);

extern const double PI(3.1415926535);

extern const double epsilon(1e-8);

double modulo_2pi(double angle) {
    while (angle>=2*PI) {
        angle-=2*PI;
    }
    while (angle<=0) {
        angle+=2*PI;
    }
    return angle;
}
 
