#include "vue_opengl.h"
#include "vertex_shader.h" // Identifiants Qt de nos différents attributs
#include "Toupie.h"
#include "Vecteur.h"
#include <cmath>
#include <QGLContext>
#include <QOpenGLFunctions>

//memoire=================================================================================================
void Memoire::ajouter_point(Vecteur const& P){

    if (points.size()>=taille){
        points.pop_front();
    }
    points.push_back(P);
}
//=========================================================================================================
std::deque<Vecteur> Memoire::GetPoints(){
    return points;
}
//=========================================================================================================
Memoire::Memoire(size_t taille)
    :taille(taille){}

// VueOpenGL===============================================================================================

void VueOpenGL::dessine(Toupie const& a_dessiner) {
    QMatrix4x4 matrice;
    dessineAxes(matrice);
    double psi(a_dessiner.getP().get_coord(1));
    double theta(a_dessiner.getP().get_coord(2));
    double phi(a_dessiner.getP().get_coord(3));
    matrice.rotate(psi*360/(2*M_PI),0.0,0.0,1.0);
    matrice.rotate(theta*360/(2*M_PI),1.0,0.0,0.0);
    matrice.rotate(phi*360/(2*M_PI),0.0,0.0,1.0);
    dessineCone(matrice);
}
//=========================================================================================================
void VueOpenGL::dessine(ConeSimple const& a_dessiner)
{
    QMatrix4x4 matrice;
    dessineAxes(matrice);
    double psi(a_dessiner.getP().get_coord(1));
    double theta(a_dessiner.getP().get_coord(2));
    double phi(a_dessiner.getP().get_coord(3));
    matrice.rotate(psi*360/(2*M_PI),0.0,0.0,1.0);
    matrice.rotate(theta*360/(2*M_PI),1.0,0.0,0.0);
    matrice.rotate(phi*360/(2*M_PI),0.0,0.0,1.0);
    dessineCone(matrice);
}
//=========================================================================================================
void VueOpenGL::dessine(ToupieChinoise const& a_dessiner)
{
    QMatrix4x4 matrice;
    dessineAxes(matrice);
    double psi(a_dessiner.getP().get_coord(1));
    double theta(a_dessiner.getP().get_coord(2));
    double phi(a_dessiner.getP().get_coord(3));
    matrice.rotate(psi*360/(2*M_PI),0.0,0.0,1.0);
    matrice.rotate(theta*360/(2*M_PI),1.0,0.0,0.0);
    matrice.rotate(phi*360/(2*M_PI),0.0,0.0,1.0);
    dessineSphereCoupe(matrice);
}

//=========================================================================================================
void VueOpenGL::dessine(Pendule const& a_dessiner)
{
  QMatrix4x4 matrice;
  dessineAxes(matrice);

  glBegin(GL_LINES);

  prog.setAttributeValue(SommetId, 0.0, 0.0, 0.0);
  prog.setAttributeValue(SommetId,
                         a_dessiner.get_l()*sin(a_dessiner.getP().get_coord(2)),
                                                                              0,
                         -a_dessiner.get_l()*cos(a_dessiner.getP().get_coord(2)));

  glEnd();

  matrice.translate(a_dessiner.get_l()*sin(a_dessiner.getP().get_coord(2)),
                                                                         0,
                   -a_dessiner.get_l()*cos(a_dessiner.getP().get_coord(2)));
  matrice.scale(0.25);
  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); // passe en mode "plein"

  dessineSphere(matrice);
}
//=========================================================================================================
void VueOpenGL::dessine(MasseTombe const& a_dessiner) {
    QMatrix4x4 matrice;
    glBegin(GL_LINES);
    dessineAxes(matrice);
    matrice.translate(a_dessiner.getP().get_coord(1),
                      a_dessiner.getP().get_coord(2),
                      a_dessiner.getP().get_coord(3));
    matrice.scale(0.25);

    dessineSphere(matrice,0.0);

    glEnd();
}
//=========================================================================================================
void VueOpenGL::trace_G(ConeSimple const& c){
    QMatrix4x4 point_de_vue;
    prog.setUniformValue("vue_modele", matrice_vue * point_de_vue);
    m.ajouter_point(c.G_O());
    if (m.GetPoints().size()>=2){
        glBegin(GL_LINES);
        for(size_t i(0);i<m.GetPoints().size()-1;i++){
            prog.setAttributeValue(CouleurId, 1.0, 0.0, 0.0);
            prog.setAttributeValue(SommetId, m.GetPoints()[i].get_coord(1), m.GetPoints()[i].get_coord(2), m.GetPoints()[i].get_coord(3));
            prog.setAttributeValue(SommetId, m.GetPoints()[i+1].get_coord(1), m.GetPoints()[i+1].get_coord(2), m.GetPoints()[i+1].get_coord(3));
        }
        glEnd();
    }
}
//=========================================================================================================
void VueOpenGL::trace_G(Toupie const& t){}
//=========================================================================================================
void VueOpenGL::trace_G(Pendule const& p){}
//=========================================================================================================
void VueOpenGL::trace_G(MasseTombe const& m){}
//=========================================================================================================
void VueOpenGL::dessineAxes (QMatrix4x4 const& point_de_vue, bool en_couleur)
{
  prog.setUniformValue("vue_modele", matrice_vue * point_de_vue);

  glBegin(GL_LINES);

  // axe X
  if (en_couleur) {
    prog.setAttributeValue(CouleurId, 1.0, 0.0, 0.0); // rouge
  } else {
    prog.setAttributeValue(CouleurId, 1.0, 1.0, 1.0); // blanc
  }
  prog.setAttributeValue(SommetId, 0.0, 0.0, 0.0);
  prog.setAttributeValue(SommetId, 1.0, 0.0, 0.0);

  // axe Y
  if (en_couleur) prog.setAttributeValue(CouleurId, 0.0, 1.0, 0.0); // vert
  prog.setAttributeValue(SommetId, 0.0, 0.0, 0.0);
  prog.setAttributeValue(SommetId, 0.0, 1.0, 0.0);

  // axe Z
  if (en_couleur) prog.setAttributeValue(CouleurId, 0.0, 0.0, 1.0); // bleu
  prog.setAttributeValue(SommetId, 0.0, 0.0, 0.0);
  prog.setAttributeValue(SommetId, 0.0, 0.0, 1.0);

  glEnd();
}
//=========================================================================================================
SupportADessin* VueOpenGL::copie() const {}
//=========================================================================================================
void VueOpenGL::init()
{
    // Initialisation des shaders

    prog.addShaderFromSourceFile(QOpenGLShader::Vertex,   ":/vertex_shader.glsl");
    prog.addShaderFromSourceFile(QOpenGLShader::Fragment, ":/fragment_shader.glsl");

    prog.bindAttributeLocation("sommet",  SommetId);
    prog.bindAttributeLocation("coordonnee_texture", CoordonneeTextureId);

    prog.link();
    prog.bind();

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);

    // Préparation d'une première texture à partir d'une image (cat.jpeg).
    QGLContext* context =  const_cast<QGLContext*>(QGLContext::currentContext());
    textureDeChat = context->bindTexture(QPixmap(":/cat.jpeg"), GL_TEXTURE_2D);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
    // Autres variantes au lieu de GL_MIRRORED_REPEAT : GL_REPEAT, GL_CLAMP_TO_EDGE

    // Préparation d'une seconde texture.
    // S'il y devait y en avoir plus, on ferait bien sûr une fonction ;-)
    textureFractale = context->bindTexture(QPixmap(":/mandelbrot.jpeg"), GL_TEXTURE_2D);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);


  sphere.initialize();
  sphere_coupe.initialize();
  initializePosition();
}
//=========================================================================================================
void VueOpenGL::initializePosition()
{
  // position initiale
  matrice_vue.setToIdentity();
  matrice_vue.translate(0.0, 0.0, -4.0);
  matrice_vue.rotate(-90.0, 1.0, 0.0, 0.0);
}
//=========================================================================================================
void VueOpenGL::translate(double x, double y, double z)
{
  /* Multiplie la matrice de vue par LA GAUCHE.
   * Cela fait en sorte que la dernière modification apportée
   * à la matrice soit appliquée en dernier (composition de fonctions).
   */
  QMatrix4x4 translation_supplementaire;
  translation_supplementaire.translate(x, y, z);
  matrice_vue = translation_supplementaire * matrice_vue;
}
//=========================================================================================================
void VueOpenGL::rotate(double angle, double dir_x, double dir_y, double dir_z)
{
  // Multiplie la matrice de vue par LA GAUCHE
  QMatrix4x4 rotation_supplementaire;
  rotation_supplementaire.rotate(angle, dir_x, dir_y, dir_z);
  matrice_vue = rotation_supplementaire * matrice_vue;
}
//=========================================================================================================
void VueOpenGL::dessineCube (QMatrix4x4 const& point_de_vue)
{
  prog.setUniformValue("vue_modele", matrice_vue * point_de_vue);

  glBegin(GL_QUADS);
  // face coté X = +1
  prog.setAttributeValue(CouleurId, 1.0, 0.0, 0.0); // rouge
  prog.setAttributeValue(SommetId, +1.0, -1.0, -1.0);
  prog.setAttributeValue(SommetId, +1.0, +1.0, -1.0);
  prog.setAttributeValue(SommetId, +1.0, +1.0, +1.0);
  prog.setAttributeValue(SommetId, +1.0, -1.0, +1.0);

  // face coté X = -1
  prog.setAttributeValue(CouleurId, 0.0, 1.0, 0.0); // vert
  prog.setAttributeValue(SommetId, -1.0, -1.0, -1.0);
  prog.setAttributeValue(SommetId, -1.0, -1.0, +1.0);
  prog.setAttributeValue(SommetId, -1.0, +1.0, +1.0);
  prog.setAttributeValue(SommetId, -1.0, +1.0, -1.0);

  // face coté Y = +1
  prog.setAttributeValue(CouleurId, 0.0, 0.0, 1.0); // bleu
  prog.setAttributeValue(SommetId, -1.0, +1.0, -1.0);
  prog.setAttributeValue(SommetId, -1.0, +1.0, +1.0);
  prog.setAttributeValue(SommetId, +1.0, +1.0, +1.0);
  prog.setAttributeValue(SommetId, +1.0, +1.0, -1.0);

  // face coté Y = -1
  prog.setAttributeValue(CouleurId, 0.0, 1.0, 1.0); // cyan
  prog.setAttributeValue(SommetId, -1.0, -1.0, -1.0);
  prog.setAttributeValue(SommetId, +1.0, -1.0, -1.0);
  prog.setAttributeValue(SommetId, +1.0, -1.0, +1.0);
  prog.setAttributeValue(SommetId, -1.0, -1.0, +1.0);

  // face coté Z = +1
  prog.setAttributeValue(CouleurId, 1.0, 1.0, 0.0); // jaune
  prog.setAttributeValue(SommetId, -1.0, -1.0, +1.0);
  prog.setAttributeValue(SommetId, +1.0, -1.0, +1.0);
  prog.setAttributeValue(SommetId, +1.0, +1.0, +1.0);
  prog.setAttributeValue(SommetId, -1.0, +1.0, +1.0);

  // face coté Z = -1
  prog.setAttributeValue(CouleurId, 1.0, 0.0, 1.0); // magenta
  prog.setAttributeValue(SommetId, -1.0, -1.0, -1.0);
  prog.setAttributeValue(SommetId, -1.0, +1.0, -1.0);
  prog.setAttributeValue(SommetId, +1.0, +1.0, -1.0);
  prog.setAttributeValue(SommetId, +1.0, -1.0, -1.0);

  glEnd();
}
//=========================================================================================================
void VueOpenGL::dessineCone(QMatrix4x4 const& point_de_vue){
    prog.setUniformValue("vue_modele", matrice_vue * point_de_vue);
    prog.setUniformValue("textureId", 0);

    /// Attribut la texture 'textureDeChat' à la texture numéro 0 du shader
    QOpenGLFunctions *glFuncs = QOpenGLContext::currentContext()->functions();
    glFuncs->glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, textureDeChat);

    double h(1.5);
    double r(0.5);
    double slices(50);
    double theta(2*M_PI/slices);

    glBegin(GL_POLYGON);

    /*prog.setAttributeValue(CoordonneeTextureId, 0.5, 0.5);
    prog.setAttributeValue(SommetId, 0.0,0.0,h);
    prog.setAttributeValue(CoordonneeTextureId,r*cos(theta),r*sin(theta));
    prog.setAttributeValue(SommetId, r*cos(theta),r*sin(theta),h);*/

    for(unsigned int i(0);i<=slices;i++){
    //if(i%2==0){

        prog.setAttributeValue(CoordonneeTextureId,r*cos(i*theta)+0.5,r*sin(i*theta)+0.5);
        prog.setAttributeValue(SommetId, r*cos(i*theta),r*sin(i*theta),h);
    //
    //}
    /*else{
        prog.setAttributeValue(CouleurId, 0.0, 1.0, 0.0);
        prog.setAttributeValue(SommetId, 0.0,0.0,h);
        prog.setAttributeValue(SommetId, r*cos(i*theta),r*sin(i*theta),h);    //y=h!!
        prog.setAttributeValue(SommetId, r*cos((i+1)*theta),r*sin((i+1)*theta),h);
    }*/

   }
   glEnd();



    glBegin(GL_TRIANGLES);
    for(unsigned int i(0);i<=slices;i++){
    if(i%2==0){
       prog.setAttributeValue(CouleurId, 0.0, 0.0, 1.0); // bleu
       prog.setAttributeValue(SommetId, 0.0,0.0,0.0);
       prog.setAttributeValue(SommetId, r*cos(i*theta),r*sin(i*theta),h);
       prog.setAttributeValue(SommetId, r*cos((i+1)*theta),r*sin((i+1)*theta),h);
    }
    else{
        prog.setAttributeValue(CouleurId, 0.0, 1.0, 0.0); // green
        prog.setAttributeValue(SommetId, 0.0,0.0,0.0);
        prog.setAttributeValue(SommetId, r*cos(i*theta),r*sin(i*theta),h);
        prog.setAttributeValue(SommetId, r*cos((i+1)*theta),r*sin((i+1)*theta),h);
    }
   }
    glEnd();
}

//=========================================================================================================
void VueOpenGL::dessineSphere (QMatrix4x4 const& point_de_vue,
                               double rouge, double vert, double bleu)
{
  prog.setUniformValue("vue_modele", matrice_vue * point_de_vue);
  prog.setAttributeValue(CouleurId, rouge, vert, bleu);  // met la couleur
  sphere.draw(prog, SommetId);                           // dessine la sphère
}
//=========================================================================================================
void VueOpenGL::dessineSphereCoupe (QMatrix4x4 const& point_de_vue,
                               double rouge, double vert, double bleu)
{

    prog.setUniformValue("textureId", 5);

    prog.setUniformValue("vue_modele", matrice_vue * point_de_vue);
    prog.setAttributeValue(CouleurId, rouge,vert,bleu);  // met la couleur
    sphere_coupe.draw(prog, SommetId);


   prog.setUniformValue("textureId", 0);
   QOpenGLFunctions *glFuncs = QOpenGLContext::currentContext()->functions();
   glFuncs->glActiveTexture(GL_TEXTURE0);
   glBindTexture(GL_TEXTURE_2D, textureDeChat);

   double slices(25);
   double beta(2*M_PI/slices);
   double r(0.5877);

  glBegin(GL_POLYGON);

  for(unsigned int i(0);i<=25;i++){
    prog.setAttributeValue(CouleurId, 0.0,0.0,0.0);
    prog.setAttributeValue(CoordonneeTextureId,r*cos(i*beta)+0.5,r*sin(i*beta)+0.5);
    prog.setAttributeValue(SommetId, r*cos(i*beta),r*sin(i*beta),abs(cos((20*M_PI)/25)));
  }

  glEnd();

}
//=========================================================================================================
