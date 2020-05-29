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

  VueOpenGL():Vue_Tangentielle(false){} // por initialiser la vue (tangentielle ou non), par default non-tangentielle

  void changer_vue();

  // méthodes de (ré-)initialisation
  void init();
  void initializePosition();

  // méthode set
  void setProjection(QMatrix4x4 const& projection)
  { prog.setUniformValue("projection", projection); }

  // Méthodes set
  void translate(double x, double y, double z);
  void rotate(double angle, double dir_x, double dir_y, double dir_z);
  
  // méthode utilitaire offerte pour simplifier
  void dessineCube(QMatrix4x4 const& point_de_vue = QMatrix4x4() );

  //methode rajoutée pour dessiner d'autres formes
  void dessineCylindre(QMatrix4x4 const& point_de_vue = QMatrix4x4(), double z_0 = 0, double z_1 = 0, double r_i = 0);

  void dessineSolideRevolution(QMatrix4x4 const& point_de_vue = QMatrix4x4(), double L=0, std::vector<double> r_i = std::vector<double>(0));

  void dessineCone(QMatrix4x4 const& point_de_vue = QMatrix4x4(), double h = 1.5, double r = 0.5,
                   Grandeur_physique=phi_point,double =0,double =0,double=0);

  void dessineAxes(QMatrix4x4 const& point_de_vue, bool en_couleur = true);

  void dessinePlateforme(QMatrix4x4 const& point_de_vue);

  void dessinePolygon(QMatrix4x4 const& point_de_vue, double h, double r);

  void dessineSphere(QMatrix4x4 const& point_de_vue,
                       Grandeur_physique grandeur=null,double =0,double =0,double =0);

 //permet de représenter graphiquement la toupie chinoise
  void dessineSphereCoupe(QMatrix4x4 const& point_de_vue,
                       Grandeur_physique grandeur=null,double =0,double =0,double =0);

//dessin graphique des toupies à partir de leurs paramètres et des formes crées plus haut
  virtual void dessine(ConeSimple const&) override;

  virtual void dessine(Pendule const&) override;

  virtual void dessine(MasseTombe const&) override;

  virtual void dessine(Toupie const&) override;

  virtual void dessine(ToupieChinoise const&) override;

  virtual void dessine(SolideRevolution const&) override;

  //trace graphique du centre de masse des toupies
  virtual void trace_G(Toupie&) override;

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
