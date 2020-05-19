#pragma once
#include "Vecteur.h"
#include "Toupie.h"

#ifndef I
#define I

class Integrateur{
	public:
        virtual void integre(double const& pas_de_temps,Toupie& evolue) = 0; // integre la toupie
		
        virtual Integrateur* copie() const = 0; // permet de créer un nouveau pointeur pointant vers le meme integrateur

        virtual std::ostream& affiche(std::ostream& sortie) const = 0; // affiche le nom de l'integrateur
};

class IntegrateurEulerCromer: public Integrateur{
	public:
	    virtual void integre(double const& pas_de_temps,Toupie& evolue) override;
	    
        virtual Integrateur* copie() const override;

        virtual std::ostream& affiche(std::ostream& sortie) const override;
};

std::ostream& operator<<(std::ostream& sortie,IntegrateurEulerCromer const& etre_affiche);

class IntegrateurNewmark: public Integrateur{
    public:
        virtual void integre(double const& pas_de_temps,Toupie& evolue) override;

        virtual Integrateur* copie() const override;

        virtual std::ostream& affiche(std::ostream& sortie) const override;

private:
    Vecteur q;
    Vecteur r;
    Vecteur s;
    Vecteur P_precedent;
    Vecteur P_point_precedent;
};

std::ostream& operator<<(std::ostream& sortie,IntegrateurNewmark const& etre_affiche);

class IntegrateurRungeKutta: public Integrateur {
    public:

    virtual void integre(double const& pas_de_temps,Toupie& evolue) override;

    virtual Integrateur* copie() const override;

    virtual std::ostream& affiche(std::ostream& sortie) const override;

    private:

    Vecteur k1,k1_,k2,k2_,k3,k3_,k4,k4_;
};

#endif
