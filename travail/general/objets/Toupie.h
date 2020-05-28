#pragma once
#include <memory>
#include "Vecteur.h"
#include "Dessinable.h"
#include "Matrice.h"
#include "Integrateur.h"
#include "constant.h"
#include "memoire.h"

#ifndef T
#define T

//Toupie===================================================================================================
class Toupie:public Dessinable{
	protected:
	
		double masse;
		
        Vecteur P; // {psi,theta,phi,x,y,z} mais en faite cela depends des types de toupies
		
        Vecteur P_point; // vecteurs des derivees des composantes de P
		
        double I1;
		
		double I3; 

        double distance; // distance entre le centre de masse et le point de contact

        Vecteur OA; // Vecteur OA

        Grandeur_physique grandeur; //grandeur utilisé pour l'affichage de couleur differente selon une grandeur physique

        Memoire m;

	public:
	
		~Toupie();
		
        Vecteur getP() const; // retourne vecteur position
		
        Vecteur getP_point() const; // retourne derivée vecteur position

        virtual Vecteur get_OA() const; // retourne le vecteur indiquant le point de contact

        Memoire get_m() const; //retourne les points en mémoire (pour l'affichage graphique)

        Grandeur_physique get_Grandeur() const; //retourne la grandeur physique dont la toupie utilise pour changer de couleur

        bool get_trace_on(); // retourne le bool indiquant si on veut la trace ou pas

        void changer_grandeur(Grandeur_physique); //change la grandeur physique vu précédemment
		
		void setP(Vecteur const& v);
		
		void setP_point(Vecteur const& v);

        void ajouter_point_memoire(Vecteur const&);
		
        Toupie(SupportADessin* support, double masse, Vecteur P, Vecteur P_point, double I1, double I3,double distance,Vecteur OA,Grandeur_physique grandeur=null, bool trace_on = true);
		
        virtual std::ostream& affiche(std::ostream& sortie) const; // affiche les caracteristiques de la toupies(masse,I1,I3...)
		
        virtual Vecteur eq_mouv() const = 0; // equation de mouvement de la toupie

        virtual void dessine() const override; // dessine la toupie selon le support à dessin de celle-ci

        virtual std::unique_ptr<Toupie> copie() const = 0; // copie avec retour covariant

        //std::unique_ptr<Toupie> clone() const; // permet d'avoir un retour covariant pour les unique_ptr

        Vecteur omega_G() const; // retourne la rotation instantanée dans le repere R_G

        Vecteur omega_O() const; // retourne la rotation instantanée dans le repere R_O

        Vecteur omega_point_G() const; // retourne le vecteur des derivées des coordonnées de omega dans le repere R_G

        Vecteur omega_point_O() const; // retourne le vecteur des derivées des coordonnées de omega dans le repere R_O

        Vecteur omega_e_G() const; // retourne le vecteur de rotation du repere R_G dans le repere R_G

        Vecteur omega_e_O() const; // retourne le vecteur de rotation du repere R_G dans le repere R_O

        virtual double psi_point_point() const; // derivée seconde de psi

        virtual double theta_point_point() const; // derivée seconde de theta

        virtual double phi_point_point() const; // derivée seconde de phi

        Vecteur MA_G() const; // moment de force au point A (de contact) dans le repere R_G

        Vecteur MA_O() const; // moment de force au point A (de contact) dans le repere R_O

        Matrice IG_G() const; // matrice d'inertie du centre de masse dans le repere R_G

        Matrice IG_O() const; // matrice d'inertie du centre de masse dans le repere R_O

        Matrice IA_G() const; // matrice d'inertie au point A dans le repere R_G

        Matrice IA_O() const; // matrice d'inertie au point A dans le repere R_O

        Matrice IA_point() const; // derivée de IA

        Matrice S_()const; // matrice de rotation S permettant de faire le changement de base

        Vecteur GtoO(Vecteur const G) const; // passage du repere R_G au repere R_O

        Vecteur OtoG(Vecteur const O) const; // passage du repere R_O au repere R_G

        Vecteur LG_G() const; // moment cinetique au point G dans le repere R_G

        Vecteur LG_O() const; // moment cinetique au point G dans le repere R_O
        
        Vecteur LA_G() const; // moment cinetique au point A dans le repere R_G

        Vecteur LA_O() const; // moment cinetique au point A dans le repere R_O

        double LA_k() const; // projection du moment cinetique sur k

        double LA_a() const; // projection du moment cinetique de A sur a

        Vecteur AG_G() const; // vecteur du centre du referentiel R_G au point A exprime dans le referentiel R_G

        virtual Vecteur AG_O() const; // vecteur du centre du referentiel R_O au point A exprime dans le referentiel R_O

        virtual Vecteur OG_G() const; // vecteur du centre du referentiel R_G au point G exprime dans le referentiel R_G

        virtual Vecteur OG_O() const; // vecteur du centre du referentiel R_O au point G exprime dans le referentiel R_O

        Vecteur P_G() const; // vecteur du poids de la toupie dans le referentiel R_G

        Vecteur P_O() const; // vecteur du poids de la toupie dans le referentiel R_O

        virtual double EC() const; // energie cinetique

        virtual double E() const; // energie totale

        double prod_mixt() const; // le produit mixte (omega^L)*a

        virtual void trace_G() override;

};

std::ostream& operator<<(std::ostream&,Toupie const& etre_affiche);

//CONESIMPLE===================================================================================================

class ConeSimple:public Toupie{
	private:
	
		double hauteur;
		
		double rayon;
		
		
    public:
	
        ConeSimple(SupportADessin* support, double m, double h, double r, Vecteur P, Vecteur P_point,Vecteur OA, Grandeur_physique grandeur=null, bool trace_on = true);
		
		std::ostream& affiche(std::ostream& sortie) const override;

        double get_hauteur() const;

        double get_rayon() const;
		
        Vecteur eq_mouv() const override;  //equation du mouvement du cone
		
        virtual void dessine() const override; //retourne les parametres et dérivées des parametres
		
        virtual std::unique_ptr<Toupie> copie() const override;
		
		std::unique_ptr<ConeSimple> clone() const;

        virtual void trace_G() override;
};

double masse_cone(double masse_volumique,double hauteur,double rayon);//calcule la masse du cone a partir d'une masse volumique,une hauteur et un rayon associés au cone

std::ostream& operator<<(std::ostream&,ConeSimple const& etre_affiche);

//ToupieChinoise============================================================

class ToupieChinoise:public Toupie{
    private:

    double h;

    double R;

    double psi() const;

    double theta() const;

    double phi() const;

    double psi_point() const;

    double theta_point() const;

    double phi_point() const;

    double f1() const;

    double f2() const;

    double f3() const;

    public:

    ToupieChinoise(SupportADessin* support, double m, double h, double R, Vecteur P, Vecteur P_point, Vecteur OA, Grandeur_physique grandeur=null, bool trace_on = true);

    std::ostream& affiche(std::ostream& sortie) const override;

    virtual void dessine() const override;

    virtual std::unique_ptr<Toupie> copie() const override;

    std::unique_ptr<ToupieChinoise> clone() const;

    virtual  Vecteur get_OA() const override;  //retourne le point de contact

    virtual Vecteur eq_mouv() const override;

    virtual double psi_point_point() const override; // derivée seconde de psi

    virtual double theta_point_point() const override; // derivée seconde de theta

    virtual double phi_point_point() const override; // derivée seconde de phi

    double P4_point_point() const;  // dérivée du déplacement en x du centre géométrique de la toupie chinoise

    double P5_point_point() const; // dérivée du déplacement en y du centre géométrique de la toupie chinoise

    Vecteur GC_G() const;  //Vecteur du centre de masse au centre géométrique dans le référentiel de la toupie

    Vecteur GC_O() const;   //Vecteur du centre de masse au centre géométrique dans le référentiel inertiel

    Vecteur AC_G() const;   //Vecteur du point de contact au centre géométrique dans le référentiel de la toupie

    Vecteur AC_O() const;   //Vecteur du point de contact au centre géométrique dans le référentiel de la inertiel

    Vecteur AG_G() const;   //Vecteur du point de contact au centre de masse dans le référentiel de la toupie

    Vecteur AG_O() const override;   //Vecteur du point de contact au centre masse dans le référentiel de la inertiel

    Vecteur vC_O() const; //vitesse du point C dans le repère inertiel

    virtual void trace_G() override;  //done la trace du centre de masse de la toupie chinoise

};

double masse_chinoise(double masse_volumique, double h, double R);

double rho_chinoise(double m, double h, double R);

double alpha_chinoise(double h, double R);

double integrale_z_carre(double m, double h, double R);

double I1_chinoise(double m, double h, double R); //retourne le coefficient I1 du tenseur d'inertie de la toupie chinoise

double I3_chinoise(double m, double h, double R); //retourne le coefficient I3 du tenseur d'inertie de la toupie chinoise


std::ostream& operator<<(std::ostream&,ToupieChinoise const& etre_affiche);

//SolideRevolution==========================================================

class SolideRevolution:public Toupie {
    private:

    double rho; // masse volumique

    double L; // hauteur

    std::vector<double> r_i; // ensemble de distances a l'axe

    public:

    SolideRevolution(SupportADessin* support, double rho, double L, std::vector<double> r_i, Vecteur P, Vecteur P_point, Vecteur OA, Grandeur_physique grandeur=null, bool trace_on = true);

    std::ostream& affiche(std::ostream& sortie) const override;

    virtual void dessine() const override;

    virtual std::unique_ptr<Toupie> copie() const override;

    std::unique_ptr<SolideRevolution> clone() const;

    virtual void trace_G() override;

    double get_L() const;

    std::vector<double> get_r_i() const;

    virtual Vecteur eq_mouv() const override;
};

std::ostream& operator<<(std::ostream&,SolideRevolution const& etre_affiche);

double masse_solide_revolution(double rho, double L, std::vector<double>  const& r_i);

double d_solide_revolution(double L, std::vector<double>  const& r_i);

double I1_solide_revolution(double rho, double L, std::vector<double>  const& r_i);

double I3_solide_revolution(double rho, double L, std::vector<double>  const& r_i);

//MasseTombe================================================================
class MasseTombe:public Toupie{
	public:
	
    MasseTombe(SupportADessin* support, double m, Vecteur P, Vecteur P_point, bool trace_on = true);
	
	std::ostream& affiche (std::ostream& sortie) const override;
	
	Vecteur eq_mouv() const override;
	
	virtual void dessine() const override;
	
	virtual std::unique_ptr<Toupie> copie() const override;
		
	std::unique_ptr<MasseTombe> clone() const;

    virtual double EC() const override;

    double EP() const;

    virtual double E() const override;

    virtual Vecteur OG_O() const override;

    virtual void trace_G() override;
};	

std::ostream& operator<<(std::ostream&,MasseTombe const& etre_affiche);


//Pendule================================================================

// le vecteur de degres de liberte est (r,theta,z) ou on utilise les coordonnes cylindriques

class Pendule:public Toupie{

public:

    Pendule(SupportADessin* support, double m, Vecteur P, Vecteur P_point,Vecteur OA, bool trace_on = true);

    std::ostream& affiche (std::ostream& sortie) const override;

    Vecteur eq_mouv() const override;

    virtual void dessine() const override;

    virtual std::unique_ptr<Toupie> copie() const override;

    std::unique_ptr<Pendule> clone() const;

    virtual double EC() const override;

    double EP() const;

    virtual double E() const override;

    virtual Vecteur AG_O() const override;

    virtual void trace_G() override;

};

std::ostream& operator<<(std::ostream&,Pendule const& etre_affiche);

#endif
