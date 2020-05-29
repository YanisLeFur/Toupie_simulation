#include <iostream>
#include "Matrice.h"
#include "Vecteur.h"
#include "constant.h"
using namespace std;

int main(){
    // construction des matrices =========================================================================================

    cout << "Construction des Matrices : " << endl << endl;

    // test du constructeur par default qui cree la matrice identite

    Matrice I;

    // test du constructeur qui prend 3 doubles et qui cree une matrice diagonale

    Matrice diag(1, 2, 3);

    // test du constructeur qui prend 9 doubles et qui cree une matrice ligne par ligne

    Matrice mat(1.1, 1.2, 1.3,
                2.1, 2.2, 2.3,
                3.1, 3.2, 3.3);

    Matrice mat2(1, 2, 0,
                 3, 4, 0,
                 0, 0, 1);

    // une copie de la matrice mat

    Matrice mat3(mat);

    // affichage des matrices =========================================================================================

    cout << "Affichage des Matrices : " << endl << endl;

    cout << "I : " << endl << endl << I << endl << endl;

    cout << "diag : " << endl << endl << diag << endl << endl;

    cout << "mat : " << endl << endl << mat << endl << endl;

    cout << "mat2 : " << endl << endl << mat2 << endl << endl;

    cout << "mat3 : " << endl << endl << mat3 << endl << endl;

    // test de l'egalite de deux matrices =========================================================================================

    cout << "Test de l'egalite de deux Matrices : " << endl << endl;

    cout << "La matrice mat est ";

    // test de l'operateur ==

    if (mat==mat2)  cout << "egale a la";

    else cout << "differente de la";

    cout << " matrice  mat2," << endl << "et est ";

    // test de l'operateur !=

    if (mat!=mat3) cout << "differente de la";

    else cout << "egale a la";

    cout << " matrice mat3." << endl << endl;

    // test du calcul du determinant =========================================================================================

    cout << "Test du calcul du determinant : " << endl << endl;

    cout << "det(I) = " << I.det() << endl << endl;

    cout << "det(diag) = " << diag.det() << endl << endl;

    cout << "det(mat) = " << mat.det() << endl << endl;

    cout << "det(mat2) = " << mat2.det() << endl << endl;

    // test de l'inverse =========================================================================================

    cout << "Test de l'inverse : " << endl << endl;

    cout << "(I)^-1 = " << endl << endl << I.inv() << endl << endl;

    cout << "(diag)^-1 = " << endl << endl << diag.inv() << endl << endl;

    cout << "(mat2)^-1 = " << endl << endl << mat2.inv() << endl << endl;

    // test du calcul de l'inverse d'une matrice singuliere =========================================================================================

    cout << "Test du calcul de l'inverse d'une Matrice singuliere : " << endl << endl;

    // on choisi ici de ne pas retourner la matrice nul

    // dans le cas d'un determinant quasi-nul

    // et plutot de lancer une erreur

    // en effet si la matrice est non inversible,

    // essayer de prendre son inverse est une erreur

    // qui devrait arreter la simulation physique

    try{
        cout << "(mat)^-1 = " << mat.inv() << endl << endl;
    }

    catch(int const& i){
        affiche_erreur(i);
    }

    // test de l'addition de deux matrices =========================================================================================

    cout << "Test de l'addition de deux Matrices : " << endl << endl;

    cout << "mat + mat = " << endl << endl << mat+mat << endl << endl;

    // test de la soustraction de deux matrices =========================================================================================

    cout << "Test de la soustraction de deux Matrices : " << endl << endl;

    cout << "mat - mat = " << endl << endl << mat-mat << endl << endl;

    cout << "diag - I = " << endl << endl << diag-I << endl << endl;

    // test de l'oppose d'une matrice =========================================================================================

    cout << "Test de l'oppose d'une Matrice : " << endl << endl;

    cout << "L'oppose additif de " << endl << endl << mat << endl << "est" << endl << endl << -mat << endl;

    cout << "-mat2 + mat = " << endl << endl << -mat2+mat << endl << endl;

    // test de la multiplication d'une matrice par un scalaire =========================================================================================

    cout << "Test de la multiplication d'une Matrice par un scalaire : " << endl << endl;

    cout << "4.4 * diag = " << endl << endl << 4.4*diag << endl << endl;

    cout << "2 * mat = " << endl << endl << 2*mat << endl << endl;

    // construction de deux vecteurs pour tester la multiplication d'une matrice avec un vecteur =========================================================================================

    cout << "Construction de deux Vecteurs pour tester la multiplication d'une Matrice avec un Vecteur : " << endl << endl;

    Vecteur v(5.5, 6.6, 7.7);

    Vecteur v2({1,2});

    // affichage des vecteurs =========================================================================================

    cout << "Affichage des Vecteurs : " << endl << endl;

    cout << "v = " << v << endl << endl;

    cout << "v2 = " << v2 << endl << endl;

    // test de la multiplication d'une matrice et d'un vecteur de dimension 3 =========================================================================================

    cout << "Test de la multiplication d'une Matrice et d'un Vecteur de dimension 3 : " << endl << endl;

    cout << "mat * v = " << mat*v << endl << endl;

    // test de la multiplication d'une matrice et d'un vecteur de dimension differente de 3 =========================================================================================

    cout << "Test de la multiplication d'une Matrice et d'un Vecteur de dimension differente de 3 : " << endl << endl;

    try {
        cout << "mat * v2 = " << mat*v2;
    }

    catch(int const& i){
        affiche_erreur(i);
    }

    // test de la multiplication matricielle =========================================================================================

    cout << "Test de la multiplication matricielle : " << endl << endl;

    cout << "mat * mat = " << endl << endl << mat*mat << endl << endl;

    // test de l'inverse multiplicatif d'une matrice

    cout << "mat2 * (mat2)^-1 = " << endl << endl << mat2*mat2.inv() << endl << endl;

    // test de la transposee d'une matrice =========================================================================================

    cout << "Test de la transposee d'une Matrice : " << endl << endl;

    cout << "(mat)^T = " << endl << endl << mat.transp() << endl << endl;

	return 0;
}
