#ifndef VUEOPENGL_H
#define VUEOPENGL_H

#include <QOpenGLShaderProgram> // Classe qui regroupe les fonctions OpenGL liées aux shaders
#include <QOpenGLFunctions>
#include <QMatrix4x4>
#include "Dessinable.h"
#include "Toupie.h"
#include "glsphere.h"
#include "glchinoise.h"
#include "constant.h"


//VueOpenGl================================================
class VueOpenGL : public SupportADessin {
 public:

  VueOpenGL():Vue_Tangentielle(false){} // pour initialiser la vue (tangentielle ou non), par default non-tangentielle

  void changer_vue(); // pour changer de vue (tangentielle ou non)

  // méthodes de (ré-)initialisation

  void init();
  void initializePosition();

  // méthode set

  void setProjection(QMatrix4x4 const& projection)
  { prog.setUniformValue("projection", projection); }

  // Méthodes set

  void translate(double x, double y, double z);
  void rotate(double angle, double dir_x, double dir_y, double dir_z);

  // methodes rajoutées pour dessiner d'autres formes

  // dessine un cylindre avec sa base a z_0, son sommet a z_1, de rayon r_i

  // utilise pour les solides de revolution

  // les dernier 4 attributs sont pour la variation de couleur

  // en dependance d'une grandeur physique

  void dessineCylindre(QMatrix4x4 const& point_de_vue = QMatrix4x4(), double z_0 = 0, double z_1 = 0, double r_i = 0,
                       Grandeur_physique grandeur = null, double psi_point_ = 0, double theta_point_ = 0, double phi_point_ = 0);

  // dessine un solide de revolution avec une hauteur L,

  // un tableau de rayon r_i

  // les dernier 4 attributs sont pour la variation de couleur

  // en dependance d'une grandeur physique

  void dessineSolideRevolution(QMatrix4x4 const& point_de_vue = QMatrix4x4(), double L=0, std::vector<double> r_i = std::vector<double>(0),
          Grandeur_physique grandeur = null,double psi_point_ = 0,double theta_point_ = 0,double phi_point_ = 0);

  // dessine un cone avec une hauteur h et un rayon r

  // les dernier 4 attributs sont pour la variation de couleur

  // en dependance d'une grandeur physique

  void dessineCone(QMatrix4x4 const& point_de_vue = QMatrix4x4(), double h = 1.5, double r = 0.5,
                   Grandeur_physique=phi_point,double =0,double =0,double=0);

  // dessine des axes cartesiens a l'origine pour pouvoir se reperer

  // les axes x, y et z sont respectivement colorier en rouge, vert et bleu

  void dessineAxes(QMatrix4x4 const& point_de_vue, bool en_couleur = true);

  void dessinePlateforme(QMatrix4x4 const& point_de_vue);

  void dessinePolygon(QMatrix4x4 const& point_de_vue, double h, double r,
                      Grandeur_physique grandeur,double psi_point_,double theta_point_,double phi_point_);

  void dessineSphere(QMatrix4x4 const& point_de_vue,
                       Grandeur_physique grandeur=null,double =0,double =0,double =0);

 //permet de représenter graphiquement la toupie chinoise
  void dessineSphereCoupe(QMatrix4x4 const& point_de_vue,
                       Grandeur_physique grandeur=null,double =0,double =0,double =0);

//dessin graphique des toupies à partir de leurs paramètres et des formes crées plus haut
  virtual void dessine(ConeSimple const&) override;

  virtual void dessine(Pendule const&) override;

  virtual void dessine(MasseTombe const&) override;

  virtual void dessine(ToupieChinoise const&) override;

  virtual void dessine(SolideRevolution const&) override;

  //trace graphique du centre de masse des toupies

  virtual void trace_G(ConeSimple&) override;

  virtual void trace_G(MasseTombe&) override;

  virtual void trace_G(Pendule&) override;

  virtual void trace_G(ToupieChinoise&) override;

  virtual void trace_G(SolideRevolution&) override;

//point de vue placé sur
  void vue_tangentielle(ConeSimple const&);

  // méthode(s) de dessin (héritée(s) de SupportADessin)
  virtual SupportADessin* copie() const override;

  private:

  // Un shader OpenGL encapsulé dans une classe Qt
  QOpenGLShaderProgram prog;
  GLSphere sphere;
  GLSphereCoupe sphere_coupe;

  // Caméra
  QMatrix4x4 matrice_vue;

   //textures
  GLuint textureDeChat;
  GLuint textureBois;
  GLuint textureOptique;

  // avoir la vue tangentielle ou pas
  bool Vue_Tangentielle;
};

#endif
