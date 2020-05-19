#include <iostream>
#include <vector>
#include "Vecteur.h"
#include "constant.h"

using namespace std;

int main(){

// un vecteur en 3D :
Vecteur vect1(1.0, 2.0, -0.1);

// un autre vecteur en 3D :
vector<double> v({1.0, 2.0, 4.1});
Vecteur vect2(v);

Vecteur vect3(vect1);  // copie de V1

Vecteur vect4(4);      // le vecteur nul en 4D

Vecteur vect9({1,2});

// affichage des vecteurs

cout << "Vecteur 1 : ";
vect1.affiche(cout) << endl;
cout << "Vecteur 2 : " << vect2 << endl;
cout << "Vecteur 3 : " << vect3 << endl;
cout << "Vecteur 4 : " << vect4 << endl;
cout << "Vecteur 9 : " << vect9 << endl;

cout << "=================================================" << endl;

cout << "En augmentant le vecteur " << vect4 << " d'une dimension avec la composante " << 5.3 << " on obtiens : " << endl;
vect4.augmente(5.3);     // test de la methode augmente
cout << vect4 << endl;

cout << "=================================================" << endl;

try {

cout << "La composante " << -1 << " du vecteur " << vect2 << " est : " << endl;
cout << vect2.get_coord(-1) << endl; // argument pour la dimension plus petit que la dimension du vecteur

}

catch(int const& i){
    switch(i){
        case 1:cerr << "Erreur: division par 0 impossible" << endl;
        case 2:cerr << "Erreur: dimension differente de 3" << endl;
        case 3:cerr << "Erreur: dimension incompatible avec celle du vecteur" << endl;
    }
}

try {

cout << "La composante " << 5 << " du vecteur " << vect2 << " est : " << endl;
cout << vect2.get_coord(5) << endl; // argument pour la dimension plus grand que la dimension du vecteur

}

catch(int const& i){
    switch(i){
        case 1:cerr << "Erreur: division par 0 impossible" << endl;
        case 2:cerr << "Erreur: dimension differente de 3" << endl;
        case 3:cerr << "Erreur: dimension incompatible avec celle du vecteur" << endl;
    }
}

cout << "La composante " << 3 << " du vecteur " << vect2 << " est : " << endl;
cout << vect2.get_coord(3) << endl; // test de la methode get_coord

cout << "================================================="<< endl;

cout << "Le vecteur 1 est ";
if (vect1==vect2) {                    // test de l'operateur ==
    cout << "egal au";
} else {
    cout << "different du";
}
cout << " vecteur 2," << endl << "et est ";
if (vect1!=vect4) {                    // test de l'operateur !=
    cout << "different du";
} else {
    cout << "egal au";
}
cout << " vecteur 4." << endl;

cout<<"================================================="<<endl;

cout << "L'oppose du vecteur " << vect4 << " est : " << -vect4 << endl; // test de l'operateur -

cout << "Le vecteur unitaire dans la direction du vecteur " << vect2 << " est : " << ~vect2 << endl; // test de l'operateur ~

try {                                              // test le lancement d'erreur pour l'addition de 2 vecteurs de dimensions differente

cout << "Si on additionne le vecteur " << vect3 << " au vecteur " << vect4 << endl;
vect2+=vect4;
cout << " on obtiens : " << vect2 << endl;

}

catch(int const& i){
    switch(i){
        case 1:cerr << "Erreur: division par 0 impossible" << endl;
        case 2:cerr << "Erreur: dimension differente de 3" << endl;
        case 3:cerr << "Erreur: dimension incompatible avec celle du vecteur" << endl;
    }
}

cout << "Si on additionne le vecteur " << vect3 << " au vecteur " << vect1 << endl;
vect1+=vect3;                                                                          // test l'operateur +=
cout << " on obtiens : " << vect1 << endl;

cout << "Si on soustrais le vecteur " << vect3 << " au vecteur " << vect2 << endl;
vect2-=vect3;                                                                          // test l'operateur -=
cout << " on obtiens : " << vect2 << endl;

cout << "Si on multiplie le vecteur " << vect3 << " par le scalaire " << 5 << endl;
vect3*=5;                                                                              // test l'operateur *=
cout << " on obtiens : " << vect3 << endl;

try {                             // test le lancement d'erreur pour le produit vectoriel avec un vecteur qui n'est pas de dimension 3

cout << "Si on multiplie le vecteur " << vect3 << " par le vecteur (produit vectoriel) " << vect4 << endl;
vect3^=vect4;
cout << " on obtiens : " << vect3 << endl;

}

catch(int const& i){
    switch(i){
        case 1:cerr << "Erreur: division par 0 impossible" << endl;
        case 2:cerr << "Erreur: dimension differente de 3" << endl;
        case 3:cerr << "Erreur: dimension incompatible avec celle du vecteur" << endl;
    }
}

cout << "Si on multiplie le vecteur " << vect3 << " par le vecteur (produit vectoriel) " << vect3 << endl;
vect3^=vect3;                                                                          // test l'operateur ^=
cout << " on obtiens : " << vect3 << endl;

cout<<"================================================="<<endl;

Vecteur vect5(1.,2.,3.), vect6(4.,5.,6.), vect7(7.,8.,9.), vect8({1.,3.});

cout << "Vecteur 5 : " << vect5 << endl;
cout << "Vecteur 6 : " << vect6 << endl;
cout << "Vecteur 7 : " << vect7 << endl;
cout << "Vecteur 8 : " << vect8 << endl;

try {                                             // test le lancement d'erreurs pour l'addition de 2 vecteurs de dimension differente

cout << "Vecteur 5+8: ";
cout << vect5+vect8;
cout << endl;

}

catch(int const& i){
    switch(i){
        case 1:cerr << "Erreur: division par 0 impossible" << endl;
        case 2:cerr << "Erreur: dimension differente de 3" << endl;
        case 3:cerr << "Erreur: dimension incompatible avec celle du vecteur" << endl;
    }
}

cout << "Vecteur 6+7: ";
cout << vect6+vect7;                                                                    // test l'operateur +
cout << endl;

cout << "Vecteur 7+6: ";
cout << vect7+vect6;                                                                    // test la commutativite de l'addition
cout << endl;

cout << "Vecteur 7-5: ";
cout << vect7-vect5;                                                                    // test l'operateur -
cout << endl;

cout << "<Vecteur 5, Vecteur 6>: ";
cout << vect5*vect6;                                                                    // test l'operateur * (produit scalaire)
cout << endl;

cout << "<Vecteur 6, Vecteur 5>: ";
cout << vect6*vect5;                                                                    // test la commutativite du produit scalaire
cout << endl;

cout << "Vecteur 6 ^ Vecteur 7 : ";
cout << (vect6 ^ vect7);                                                                // test l'operateur ^
cout << endl;

cout << "Vecteur 7 ^ Vecteur 6 : ";
cout << (vect7 ^ vect6);                                                                // test l'alternation du produit vectoriel
cout << endl;

cout << "||Vecteur 8|| : ";
cout << vect8.norme();                                                                  // la norme d'un vecteur
cout << endl;

cout << "||Vecteur 8||^2 : ";
cout << vect8.norme2();                                                                 // la norme d'un vecteur au carre
cout << endl;

    return 0;
}
