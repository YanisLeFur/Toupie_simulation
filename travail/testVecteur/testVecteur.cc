#include <iostream>
#include <vector>
#include "Vecteur.h"
#include "constant.h"

using namespace std;

int main(){

//Initialisation================================================================================================

    // un vecteur en 3D :

    Vecteur vect1(1.0, 2.0, -0.1);

    // declaration d'un vector pour tester la  deuxieme methode de construction

    vector<double> v({2.6, 3.5, 4.1});

    // un autre vecteur en 3D :

    Vecteur vect2(v);

    // copie du Vecteur 1

    Vecteur vect3(vect1);

    // affichage des vecteurs

    cout << "Affichage des Vecteurs : " << endl << endl;

    cout << "Vecteur 1 : ";

    vect1.affiche(cout) << endl;

    // test de l'operateur <<

    cout << "Vecteur 2 : ";

    cout << vect2 << endl;

    cout << "Vecteur 3 : ";

    cout << vect3 << endl << endl;

    // test de l'egalite de 2 vecteurs

    cout << "Test de l'egalite de 2 Vecteurs : " << endl << endl;

    cout << "Le Vecteur 1 est ";

    // test de l'operateur ==

    if (vect1==vect2) cout << "egal au";

    else cout << "different du";

    cout << " Vecteur 2," << endl << "et est ";

    // test de l'operateur !=

    if (vect1!=vect3) cout << "different du";

    else cout << "egal au";

    cout << " Vecteur 3." << endl << endl;

    // test de l'operateur +

    cout << "Test l'addition et sa commutativite : " << endl << endl;

    cout << vect1 << " + " << vect2 << " = " << vect1+vect2 << endl;

    //test la commutativite de l'addition

    cout << vect2 << " + " << vect1 << " = " << vect2+vect1 << endl << endl;

    // construction du vecteur nul de dimension 3 (constructeur par default)

    cout << "Construction du Vecteur nul et test de ses proprietes : " << endl << endl;

    Vecteur vect4;

    cout << "Vecteur 4 : ";

    cout << vect4 << endl;

    // test l'element neutre pour l'addition

    cout << vect1 << " + " << vect4 << " = " << vect1+vect4 << endl;

    cout << vect4 << " + " << vect1 << " = " << vect4+vect1 << endl << endl;

    // test de l'operateur -

    cout << "Test de la soustraction : " << endl << endl;

    cout << vect1 << " - " << vect2 << " = " << vect1-vect2 << endl;

    // test si la soustraction d'un vecteur a lui meme retourne le vecteur nul

    cout << vect2 << " - " << vect2 << " = " << vect2-vect2 << endl << endl;

    // construction d'un vecteur de dimension 2

    cout << "Construction d'un Vecteur de dimension 2 : " << endl << endl;

    Vecteur vect5({1,2});

    cout << "Vecteur 5 : ";

    cout << vect5 << endl << endl;

    // addition de deux vecteurs de dimensions differentes

    cout << "Addition de deux Vecteurs de dimensions differentes : " << endl << endl;

    try {
        cout << vect2 << " + " << vect5 << " = " << vect2+vect5 << endl;
    }

    catch(int const& i){
        switch(i){
            case 1:cout << endl << endl << "Erreur: division par 0 impossible" << endl << endl;
            case 2:cout << endl << endl << "Erreur: dimension differente de 3" << endl << endl;
            case 3:cout << endl << endl << "Erreur: dimensions des vecteurs incompatibles" << endl << endl;
        }
    }

    try {
        cout << vect5 << " + " << vect2 << " = " << vect5+vect2 << endl;
    }

    catch(int const& i){
        switch(i){
            case 1:cout << endl << endl << "Erreur: division par 0 impossible" << endl << endl;
            case 2:cout << endl << endl << "Erreur: dimension differente de 3" << endl << endl;
            case 3:cout << endl << endl << "Erreur: dimensions des vecteurs incompatibles" << endl << endl;
        }
    }

    // test de l'opppose d'un vecteur

    cout << "Test de l'opppose d'un Vecteur : " << endl << endl;

    cout << "- " << vect1 << " = " << -vect1 << endl;

    cout << "- " << -vect2 << " + " << vect1 << " = "  << -vect2+vect1 << endl << endl;

    //Vecteur vect4(4);      // le vecteur nul en 4D
    Vecteur vect10(1.,2.,3.), vect6(4.,5.,6.), vect7(7.,8.,9.), vect8({1.,3.});
    Vecteur vect9({1,2}); //Vecteur 2D


//Affichage des Vecteurs=========================================================================================


    cout << "Vecteur 2 : " << vect2 << endl;
    cout << "Vecteur 3 : " << vect3 << endl;
    cout << "Vecteur 4 : " << vect4 << endl;
    cout << "Vecteur 9 : " << vect9 << endl;
    cout << "=================================================" << endl;

//test méthode augmente=========================================================================================

    cout << "En augmentant le vecteur " << vect4 << " d'une dimension avec la composante " << 5.3 << " on obtiens : " << endl;
    vect4.augmente(5.3);
    cout << vect4 << endl;
    cout << "=================================================" << endl;

// Opérations arithmétiques======================================================================================

    cout << "La composante " << 3 << " du vecteur " << vect2 << " est : " << endl;
    cout << vect2.get_coord(3) << endl;                                            // test de la methode get_coord

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

    cout << "L'oppose du vecteur " << vect4 << " est : " << -vect4 << endl;                // test de l'operateur -

    cout << "Le vecteur unitaire dans la direction du vecteur " << vect2 << " est : " << ~vect2 << endl; // test de l'operateur ~


    cout << "Si on additionne le vecteur " << vect3 << " au vecteur " << vect1 << endl;
    vect1+=vect3;                                                                          // test l'operateur +=
    cout << " on obtiens : " << vect1 << endl;

    cout << "Si on soustrais le vecteur " << vect3 << " au vecteur " << vect2 << endl;
    vect2-=vect3;                                                                          // test l'operateur -=
    cout << " on obtiens : " << vect2 << endl;

    cout << "Si on multiplie le vecteur " << vect3 << " par le scalaire " << 5 << endl;
    vect3*=5;                                                                              // test l'operateur *=
    cout << " on obtiens : " << vect3 << endl;


    cout << "Si on multiplie le vecteur " << vect3 << " par le vecteur (produit vectoriel) " << vect2 << endl;
    vect3 ^= vect2;                                                                          // test l'operateur ^=
    cout << " on obtiens : " << vect3 << endl;

    cout<<"================================================="<<endl;

    cout << "Vecteur 5 : " << vect5 << endl;
    cout << "Vecteur 6 : " << vect6 << endl;
    cout << "Vecteur 7 : " << vect7 << endl;
    cout << "Vecteur 8 : " << vect8 << endl;

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





// test gestion des erreurs======================================================================================

    try {                       // recherche composante de dimension inferieur ou égale à 0

        cout << "La composante " << -1 << " du vecteur " << vect2 << " est : " << endl;
        cout << vect2.get_coord(-1) << endl;
    }

    catch(int const& i){
        switch(i){
            case 1:cerr << "Erreur: division par 0 impossible" << endl;
            case 2:cerr << "Erreur: dimension differente de 3" << endl;
            case 3:cerr << "Erreur: dimension incompatible avec celle du vecteur" << endl;
        }
    }

    try {                       // recherche composante de dimension superieur au vecteur

    cout << "La composante " << 5 << " du vecteur " << vect2 << " est : " << endl;
    cout << vect2.get_coord(5) << endl;

    }

    catch(int const& i){
        switch(i){
            case 1:cerr << "Erreur: division par 0 impossible" << endl;
            case 2:cerr << "Erreur: dimension differente de 3" << endl;
            case 3:cerr << "Erreur: dimension incompatible avec celle du vecteur" << endl;
        }
    }


    try {                      // test l'addition de 2 vecteurs de dimensions differente

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


    try {                            // test le produit vectoriel avec un vecteur qui n'est pas de dimension 3

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

    try {                                     // test l'addition de 2 vecteurs de dimension differente

    cout << "Vecteur 5 + Vecteur 8: ";
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



        return 0;
}
