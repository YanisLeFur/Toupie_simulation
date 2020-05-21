#pragma once
#include <memory>
#include "Vecteur.h"
#include "Dessinable.h"
#include "Matrice.h"
#include "Integrateur.h"

#ifndef T
#define T

//enum invariants{energie,produit_mixte,moment_cinetique};

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

	public:
	
		~Toupie();
		
        Vecteur getP() const; // retourne vecteur position
		
        Vecteur getP_point() const; // retourne derivée vecteur position

        Vecteur get_OA() const; // retourne le vecteur indiquant le point de contact
		
		void setP(Vecteur const& v);
		
		void setP_point(Vecteur const& v);
		
        Toupie(SupportADessin* support, double masse, Vecteur P, Vecteur P_point, double I1, double I3,double distance,Vecteur A);
		
        virtual std::ostream& affiche(std::ostream& sortie) const; // affiche les caracteristique de la toupies(masse,I1,I3...)
		
        virtual Vecteur eq_mouv() const; // equation de mouvement de la toupie

        virtual void dessine() const override; // dessine la toupie selon le support à dessin de celle-ci
		
        virtual std::unique_ptr<Toupie> copie() const; // copie avec retour covariant

        std::unique_ptr<Toupie> clone() const; // permet d'avoir un retour covariant pour les unique_ptr

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

        Vecteur AG() const; // vecteur AG calculer avec des considerations geometriques

        Vecteur G_G() const; // vecteur du centre du referentiel R_G au point G exprime dans le referentiel R_G

        virtual Vecteur G_O() const; // vecteur du centre du referentiel R_O au point G exprime dans le referentiel R_O

        Vecteur P_G() const; // vecteur du poids de la toupie dans le referentiel R_G

        Vecteur P_O() const; // vecteur du poids de la toupie dans le referentiel R_O

        virtual double EC() const; // energie cinetique

        virtual double E() const; // energie totale

        double prod_mixt() const; // le produit mixte (omega^L)*a

        virtual void trace_G() const override;

};

std::ostream& operator<<(std::ostream&,Toupie const& etre_affiche);

//CONESIMPLE===================================================================================================

class ConeSimple:public Toupie{
	private:
	
		double hauteur;
		
		double rayon;
		
		
    public:
	
        ConeSimple(SupportADessin* support, double m, double h, double r, Vecteur P, Vecteur P_point,Vecteur OA);
		
		std::ostream& affiche(std::ostream& sortie) const override;

        double get_hauteur() const;

        double get_rayon() const;
		
		Vecteur eq_mouv() const override;
		
		virtual void dessine() const override;
		
		virtual std::unique_ptr<Toupie> copie() const override;
		
		std::unique_ptr<ConeSimple> clone() const;

        virtual void trace_G() const override;
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

    ToupieChinoise(SupportADessin* support, double m, double h, double R, Vecteur P, Vecteur P_point,Vecteur OA);

    std::ostream& affiche(std::ostream& sortie) const override;

    virtual void dessine() const override;

    virtual std::unique_ptr<Toupie> copie() const override;

    std::unique_ptr<ToupieChinoise> clone() const;

    virtual Vecteur eq_mouv() const override;

    virtual double psi_point_point() const override; // derivée seconde de psi

    virtual double theta_point_point() const override; // derivée seconde de theta

    virtual double phi_point_point() const override; // derivée seconde de phi

    double P4_point_point() const;

    double P5_point_point() const;

    Vecteur vC_O() const;

    virtual void trace_G() const override;

};

double masse_chinoise(double masse_volumique, double h, double R);

double rho_chinoise(double m, double h, double R);

double alpha_chinoise(double h, double R);

double integrale_z_carre(double m, double h, double R);

double I1_chinoise(double m, double h, double R);

double I3_chinoise(double m, double h, double R);


std::ostream& operator<<(std::ostream&,ToupieChinoise const& etre_affiche);

//MasseTombe================================================================
class MasseTombe:public Toupie{
	public:
	
	MasseTombe(SupportADessin* support, double m,Vecteur P,Vecteur P_point);
	
	std::ostream& affiche (std::ostream& sortie) const override;
	
	Vecteur eq_mouv() const override;
	
	virtual void dessine() const override;
	
	virtual std::unique_ptr<Toupie> copie() const override;
		
	std::unique_ptr<MasseTombe> clone() const;

    virtual double EC() const override;

    double EP() const;

    virtual double E() const override;

    virtual Vecteur G_O() const override;

    virtual void trace_G() const override;
};	

std::ostream& operator<<(std::ostream&,MasseTombe const& etre_affiche);


//Pendule================================================================
class Pendule:public Toupie{
private:

    double longueur;

public:

    double get_l() const;//donne la longeur du fil

    Pendule(SupportADessin* support, double m,Vecteur P,Vecteur P_point,double longueur);

    std::ostream& affiche (std::ostream& sortie) const override;

    Vecteur eq_mouv() const override;

    virtual void dessine() const override;

    virtual std::unique_ptr<Toupie> copie() const override;

    std::unique_ptr<Pendule> clone() const;

    virtual double EC() const override;

    double EP() const;

    virtual double E() const override;

    virtual Vecteur G_O() const override;

    virtual void trace_G() const override;

};

std::ostream& operator<<(std::ostream&,Pendule const& etre_affiche);

#endif
