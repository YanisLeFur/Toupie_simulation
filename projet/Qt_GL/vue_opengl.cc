#include "vue_opengl.h"
#include "vertex_shader.h" // Identifiants Qt de nos différents attributs
#include "Toupie.h"
#include "Vecteur.h"
#include <cmath>
#include <QGLContext>
#include <QOpenGLFunctions>


// Dessin des objets===============================================================================================

//ConeSimple-------------------------------------------------------------------------------------------------------
void VueOpenGL::dessine(ConeSimple const& a_dessiner)
{
    QMatrix4x4 matrice;

    // dessine les axes cartesiens du repere

    dessineAxes(matrice);

    // dessine le plateforme du repere

    dessinePlateforme(matrice);

    // psi = a_dessiner.getP().get_coord(1)
    // theta = a_dessiner.getP().get_coord(2)
    // phi = a_dessiner.getP().get_coord(3)

    // Ax = a_dessiner.get_OA().get_coord(1)
    // Ay = a_dessiner.get_OA().get_coord(2)
    // Az = a_dessiner.get_OA().get_coord(3)

    // translate le dessin au point de contact de la toupie

    matrice.translate(a_dessiner.get_OA().get_coord(1),
                      a_dessiner.get_OA().get_coord(2),
                      a_dessiner.get_OA().get_coord(3));

    // precession autour de l'axe z

    matrice.rotate(a_dessiner.getP().get_coord(1)*360/(2*M_PI),0.0,0.0,1.0);

    // nutation autour de l'axe nodale

    matrice.rotate(a_dessiner.getP().get_coord(2)*360/(2*M_PI),1.0,0.0,0.0);

    // rotation propre autour de l'axe a

    matrice.rotate(a_dessiner.getP().get_coord(3)*360/(2*M_PI),0.0,0.0,1.0);

    // on dessine maintenant le cone au bon endroit

    // avec les bonnes rotations

    // avec la bonne hauteur et le bon rayon

    // les dernier 4 attributs sont pour la variation de couleur

    // en dependance d'une grandeur physique

    dessineCone(matrice,
                a_dessiner.get_hauteur(),
                a_dessiner.get_rayon(),
                a_dessiner.get_Grandeur(),
                a_dessiner.getP_point().get_coord(1),
                a_dessiner.getP_point().get_coord(2),
                a_dessiner.getP_point().get_coord(3));

    // donne la possibilité à l'utilisateur d'activer la vue tangentielle

    if (Vue_Tangentielle) vue_tangentielle(a_dessiner);
}
//ToupieChinoise----------------------------------------------------------------------------------------------------
void VueOpenGL::dessine(ToupieChinoise const& a_dessiner)
{
    QMatrix4x4 matrice;

    // dessine les axes cartesiens du repere

    dessineAxes(matrice);

    // dessine le plateforme du repere

    dessinePlateforme(matrice);

    // psi = a_dessiner.getP().get_coord(1)
    // theta = a_dessiner.getP().get_coord(2)
    // phi = a_dessiner.getP().get_coord(3)

    // Ax = a_dessiner.get_OA().get_coord(1)
    // Ay = a_dessiner.get_OA().get_coord(2)
    // Az = a_dessiner.get_OA().get_coord(3)
    // R = a_dessiner.get_rayon()

    // la toupie chinoise etant dessine par rapport

    // a son centre geometrique C

    // en plus de translater horizontalement le dessin

    // il nous faut une translation verticale

    // correspondant au rayon R

    matrice.translate(a_dessiner.get_OA().get_coord(1),
                      a_dessiner.get_OA().get_coord(2),
                      a_dessiner.get_OA().get_coord(3)+a_dessiner.get_rayon());

    // precession autour de l'axe z

    matrice.rotate(a_dessiner.getP().get_coord(1)*360/(2*M_PI),0.0,0.0,1.0);

    // nutation autour de l'axe nodale

    matrice.rotate(a_dessiner.getP().get_coord(2)*360/(2*M_PI),1.0,0.0,0.0);

    // rotation propre autour de l'axe a

    matrice.rotate(a_dessiner.getP().get_coord(3)*360/(2*M_PI),0.0,0.0,1.0);

    // on change la taille du dessin par rapport

    // au rayon de la toupie chinoise

    matrice.scale(a_dessiner.get_rayon());

    // on dessine maintenant la toupie chinoise au bon endroit

    // avec les bonnes rotations,

    // les dernier 4 attributs sont pour la variation de couleur

    // en dependance d'une grandeur physique

    dessineSphereCoupe(matrice,
                       a_dessiner.get_Grandeur(),
                       a_dessiner.getP_point().get_coord(1),
                       a_dessiner.getP_point().get_coord(2),
                       a_dessiner.getP_point().get_coord(3));
}

//SolideRevolution---------------------------------------------------------------------------------------------------

void VueOpenGL::dessine(const SolideRevolution& a_dessiner)
{
    QMatrix4x4 matrice;

    // dessine les axes cartesiens du repere

    dessineAxes(matrice);

    // dessine le plateforme du repere

    dessinePlateforme(matrice);

    // psi = a_dessiner.getP().get_coord(1)
    // theta = a_dessiner.getP().get_coord(2)
    // phi = a_dessiner.getP().get_coord(3)

    // Ax = a_dessiner.get_OA().get_coord(1)
    // Ay = a_dessiner.get_OA().get_coord(2)
    // Az = a_dessiner.get_OA().get_coord(3)

    // L = a_dessiner.get_L()
    // r_i = a_dessiner.get_r_i()

    // translate le dessin au point de contact de la toupie

    matrice.translate(a_dessiner.get_OA().get_coord(1),
                      a_dessiner.get_OA().get_coord(2),
                      a_dessiner.get_OA().get_coord(3));

    // precession autour de l'axe z

    matrice.rotate(a_dessiner.getP().get_coord(1)*360/(2*M_PI),0.0,0.0,1.0);

    // nutation autour de l'axe nodale

    matrice.rotate(a_dessiner.getP().get_coord(2)*360/(2*M_PI),1.0,0.0,0.0);

    // rotation propre autour de l'axe a

    matrice.rotate(a_dessiner.getP().get_coord(3)*360/(2*M_PI),0.0,0.0,1.0);

    // on dessine maintenant le solide de revolution au bon endroit

    // avec les bonnes rotations

    // avec la bonne hauteur et les bons rayons

    // les dernier 4 attributs sont pour la variation de couleur

    // en dependance d'une grandeur physique

    dessineSolideRevolution(matrice,a_dessiner.get_L(),
                            a_dessiner.get_r_i(),
                            a_dessiner.get_Grandeur(),
                            a_dessiner.getP_point().get_coord(1),
                            a_dessiner.getP_point().get_coord(2),
                            a_dessiner.getP_point().get_coord(3));
}

//Pendule-----------------------------------------------------------------------------------------------------------

void VueOpenGL::dessine(Pendule const& a_dessiner)
{
    QMatrix4x4 matrice;

    // dessine les axes cartesiens du repere

    dessineAxes(matrice);

    // dessine le plateforme du repere

    dessinePlateforme(matrice);

    // Ax = a_dessiner.get_OA().get_coord(1)
    // Ay = a_dessiner.get_OA().get_coord(2)
    // Az = a_dessiner.get_OA().get_coord(3)

    // on dessine le fil du pendule entre le point d'accrochement

    glBegin(GL_LINES);

    // entre le point d'accrochement

    prog.setAttributeValue(SommetId, a_dessiner.get_OA().get_coord(1),
                                     a_dessiner.get_OA().get_coord(2),
                                     a_dessiner.get_OA().get_coord(3));

    // et la masse de la pendule

    prog.setAttributeValue(SommetId,
                           a_dessiner.get_OA().get_coord(1)+a_dessiner.getP().get_coord(1)*sin(a_dessiner.getP().get_coord(2)),
                           a_dessiner.get_OA().get_coord(2),
                           a_dessiner.get_OA().get_coord(3)-a_dessiner.getP().get_coord(1)*cos(a_dessiner.getP().get_coord(2)));

    glEnd();

    // translate le dessin au point d'accrochement du pendule

    matrice.translate(a_dessiner.get_OA().get_coord(1),
                      a_dessiner.get_OA().get_coord(2),
                      a_dessiner.get_OA().get_coord(3));


    // translate la masse du pendule selon un angle theta

    // et la longueur du pendule

    matrice.translate(a_dessiner.getP().get_coord(1)*sin(a_dessiner.getP().get_coord(2)),
                                                                                       0,
                     -a_dessiner.getP().get_coord(1)*cos(a_dessiner.getP().get_coord(2)));

    // reduit la taille de la sphere qui represente la masse du pendule

    // pour mieux simuler un point materiel

    matrice.scale(0.10);

    // rempli la sphere (on ne peut pas voir a travers)

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    // on dessine maintenant la sphere au bon endroit

    dessineSphere(matrice);
}
//MasseTombe-------------------------------------------------------------------------------------------------------

void VueOpenGL::dessine(MasseTombe const& a_dessiner) {
    QMatrix4x4 matrice;

    // commence le dessin de la masse tombante

    glBegin(GL_LINES);

    // dessine les axes cartesiens du repere

    dessineAxes(matrice);

    // dessine le plateforme du repere

    dessinePlateforme(matrice);

    // Px = a_dessiner.get_OA().get_coord(1)
    // Py = a_dessiner.get_OA().get_coord(2)
    // Pz = a_dessiner.get_OA().get_coord(3)

    // on translate le dessin au point ou la masse se trouve

    matrice.translate(a_dessiner.getP().get_coord(1),
                      a_dessiner.getP().get_coord(2),
                      a_dessiner.getP().get_coord(3));

    // reduit la taille de la sphere qui represente la masse tombante

    // pour mieux simuler un point materiel

    matrice.scale(0.25);

    // on dessine maintenant la sphere qui represente le point materiel

    // au bon endroit

    dessineSphere(matrice);

    // on conclut le dessin de la sphere

    glEnd();
}

//Trace des Toupies=================================================================================================

//ConeSimple--------------------------------------------------------------------------------------------------------

void VueOpenGL::trace_G(ConeSimple& c){
    QMatrix4x4 point_de_vue;

    // pour enlever la texture

    prog.setUniformValue("textureId", 5);

    // pour donner le bon point de vue

    prog.setUniformValue("vue_modele", matrice_vue * point_de_vue);

    // on ajoute un nouveau point qu'on veut dessiner a la memoire

    c.ajouter_point_memoire(c.OG_O());

    // dessine une ligne si on a plus que 2 points en memoire

    if (c.get_m().GetPoints().size()>=2) {

        // commence a dessiner des lignes

        glBegin(GL_LINES);

        for(size_t i(0);i<c.get_m().GetPoints().size()-1;i++){

            // dessine la ligne d'une certaine couleur

            prog.setAttributeValue(CouleurId, 1.0, 0.0, 0.0);

            // entre 2 points consecutifs dans la memoire

            prog.setAttributeValue(SommetId, c.get_m().GetPoints()[i].get_coord(1), c.get_m().GetPoints()[i].get_coord(2), c.get_m().GetPoints()[i].get_coord(3));
            prog.setAttributeValue(SommetId, c.get_m().GetPoints()[i+1].get_coord(1), c.get_m().GetPoints()[i+1].get_coord(2), c.get_m().GetPoints()[i+1].get_coord(3));
        }

        // arrete de dessiner des lignes

        glEnd();
    }
}

//Pendule-----------------------------------------------------------------------------------------------------------

void VueOpenGL::trace_G(Pendule& p){
    QMatrix4x4 point_de_vue;

    // pour enlever la texture

    prog.setUniformValue("textureId", 5);

    // pour donner le bon point de vue

    prog.setUniformValue("vue_modele", matrice_vue * point_de_vue);

    // on ajoute un nouveau point qu'on veut dessiner a la memoire

    Vecteur v(p.getP().get_coord(1)*sin(p.getP().get_coord(2)),p.getP().get_coord(3),-p.getP().get_coord(1)*cos(p.getP().get_coord(2)));    
    p.ajouter_point_memoire(v+p.get_OA());

    // dessine une ligne si on a plus que 2 points en memoire

    if (p.get_m().GetPoints().size()>=2){

        // commence a dessiner des lignes

        glBegin(GL_LINES);

        for(size_t i(0);i<p.get_m().GetPoints().size()-1;i++){

            // dessine la ligne d'une certaine couleur

            prog.setAttributeValue(CouleurId, 1.0, 0.0, 1.0);

            // entre 2 points consecutifs dans la memoire

            prog.setAttributeValue(SommetId, p.get_m().GetPoints()[i].get_coord(1), p.get_m().GetPoints()[i].get_coord(2), p.get_m().GetPoints()[i].get_coord(3));
            prog.setAttributeValue(SommetId, p.get_m().GetPoints()[i+1].get_coord(1), p.get_m().GetPoints()[i+1].get_coord(2), p.get_m().GetPoints()[i+1].get_coord(3));
        }

        // arrete de dessiner des lignes

        glEnd();
    }
}

//ToupieChinoise--------------------------------------------------------------------------------------------------------

void VueOpenGL::trace_G(ToupieChinoise& tc)
{
    QMatrix4x4 point_de_vue;

    // pour enlever la texture

    prog.setUniformValue("textureId", 5);

    // pour donner le bon point de vue

    prog.setUniformValue("vue_modele", matrice_vue * point_de_vue);

    // on ajoute un nouveau point a la memoire

    tc.ajouter_point_memoire(tc.AG_O()+tc.get_OA());

    // dessine une ligne si on a plus que 2 points en memoire

    if (tc.get_m().GetPoints().size()>=2){

        // commence a dessiner des lignes

        glBegin(GL_LINES);

        for(size_t i(0);i<tc.get_m().GetPoints().size()-1;i++){

            // dessine la ligne d'une certaine couleur

            prog.setAttributeValue(CouleurId, 1.0, 1.0, 0.0);

            // entre 2 points consecutifs dans la memoire

            prog.setAttributeValue(SommetId, tc.get_m().GetPoints()[i].get_coord(1), tc.get_m().GetPoints()[i].get_coord(2), tc.get_m().GetPoints()[i].get_coord(3));
            prog.setAttributeValue(SommetId, tc.get_m().GetPoints()[i+1].get_coord(1), tc.get_m().GetPoints()[i+1].get_coord(2), tc.get_m().GetPoints()[i+1].get_coord(3));
        }

        // arrete de dessiner des lignes

        glEnd();
    }
}
//SolideRevolution--------------------------------------------------------------------------------------------------------
void VueOpenGL::trace_G(SolideRevolution & sr)
{
    QMatrix4x4 point_de_vue;
    prog.setUniformValue("textureId", 5);
    prog.setUniformValue("vue_modele", matrice_vue * point_de_vue);
    sr.ajouter_point_memoire(sr.OG_O());
    if (sr.get_m().GetPoints().size()>=2){
        glBegin(GL_LINES);
        for(size_t i(0);i<sr.get_m().GetPoints().size()-1;i++){
            prog.setAttributeValue(CouleurId, 1.0, 0.0, 1.0);
            prog.setAttributeValue(SommetId, sr.get_m().GetPoints()[i].get_coord(1), sr.get_m().GetPoints()[i].get_coord(2), sr.get_m().GetPoints()[i].get_coord(3));
            prog.setAttributeValue(SommetId, sr.get_m().GetPoints()[i+1].get_coord(1), sr.get_m().GetPoints()[i+1].get_coord(2), sr.get_m().GetPoints()[i+1].get_coord(3));
        }
        glEnd();
    }
}

void VueOpenGL::trace_G(Toupie &){}
//MasseTombe--------------------------------------------------------------------------------------------------------
void VueOpenGL::trace_G(MasseTombe& mt){
    QMatrix4x4 point_de_vue;
    prog.setUniformValue("textureId", 5);
    prog.setUniformValue("vue_modele", matrice_vue * point_de_vue);
    mt.ajouter_point_memoire(mt.OG_O());
    if (mt.get_m().GetPoints().size()>=2){
        glBegin(GL_LINES);
        for(size_t i(0);i<mt.get_m().GetPoints().size()-1;i++){
            prog.setAttributeValue(CouleurId, 0.0, 0.0, 1.0);
            prog.setAttributeValue(SommetId, mt.get_m().GetPoints()[i].get_coord(1), mt.get_m().GetPoints()[i].get_coord(2), mt.get_m().GetPoints()[i].get_coord(3));
            prog.setAttributeValue(SommetId, mt.get_m().GetPoints()[i+1].get_coord(1), mt.get_m().GetPoints()[i+1].get_coord(2), mt.get_m().GetPoints()[i+1].get_coord(3));
        }
        glEnd();
    }
}
//============================================================================================================================

void VueOpenGL::vue_tangentielle(ConeSimple const& c)
{
    double psi(c.getP().get_coord(1));
    double theta(c.getP().get_coord(2));
    //double phi(c.getP().get_coord(3));

    double Ax(c.get_OA().get_coord(1));
    double Ay(c.get_OA().get_coord(2));
    double Az(c.get_OA().get_coord(3));

    double h(c.get_hauteur());
    double r(c.get_rayon());

    matrice_vue.setToIdentity();

    matrice_vue.rotate(-90.0, 1.0, 0.0, 0.0); // rotation pour avoir z vers le haut

    matrice_vue.translate(0,0,-h); // on monte du sol a la hauteur de la toupie

    matrice_vue.rotate(-(psi*360/(2*M_PI)+180), 0.0, 0.0, 1.0); // on s'oriente par rapport a psi

    matrice_vue.translate(r*cos(psi),r*sin(psi),0); // on se deplace sur le bord de la toupie en bougeant une distance d'un rayon

    matrice_vue.rotate(-(theta*360/(2*M_PI)-30), cos(psi), sin(psi), 0.0); // on s'oriente par rapport a theta

    //matrice_vue.rotate(-(phi*360/(2*M_PI)), cos(psi)*sin(theta), sin(psi)*sin(theta), cos(theta)); // on s'oriente par rapport a phi

    //on ne fait pas la rotation selon phi car c'est impossible de voir quoi que ce soit

    matrice_vue.translate(-Ax,-Ay,-Az); // translation pour amener la camera sur la toupie

}
//=========================================================================================================

void VueOpenGL::dessineAxes(QMatrix4x4 const& point_de_vue, bool en_couleur)
{
  prog.setUniformValue("vue_modele", matrice_vue * point_de_vue);
  prog.setUniformValue("textureId", 5);//donne une texture vide aux axes
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

void VueOpenGL::dessinePlateforme(const QMatrix4x4 &point_de_vue)
{
    prog.setUniformValue("vue_modele", matrice_vue * point_de_vue);

    //initialise la texture du bois 
    prog.setUniformValue("textureId", 0);
    QOpenGLFunctions *glFuncs = QOpenGLContext::currentContext()->functions();
    glFuncs->glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, textureBois);

    glBegin(GL_POLYGON);

    double r(100);
    double slices(50);
    double theta(2*M_PI/slices);

    for(unsigned int i(0);i<=slices;i++){
        prog.setAttributeValue(CouleurId, 0.0, 0.0, 0.0);
        prog.setAttributeValue(CoordonneeTextureId,r*cos(i*theta)+0.5,r*sin(i*theta)+0.5);
        prog.setAttributeValue(SommetId, r*cos(i*theta),r*sin(i*theta),0);
   }

    glEnd();
}

void VueOpenGL::dessinePolygon(const QMatrix4x4 &point_de_vue, double h, double r,Grandeur_physique grandeur,double psi_point_,double theta_point_,double phi_point_)
{
    prog.setUniformValue("vue_modele", matrice_vue * point_de_vue);

    glBegin(GL_POLYGON);

    double slices(50);
    double theta(2*M_PI/slices);

    for(unsigned int i(0);i<=slices;++i){
        prog.setAttributeValue(CouleurId,0.0,0.0,0.0);
        switch (grandeur) {

            case psi_point: prog.setAttributeValue(CouleurId, 0.2+abs(psi_point_)/2.0, 0.0, 0.0);
            break;
            case theta_point: prog.setAttributeValue(CouleurId, 0.0, 0.2+abs(theta_point_)/2.0, 0.0);
            break;
            case phi_point: prog.setAttributeValue(CouleurId, 0.0, 0.0, 0.2+abs(phi_point_)/2.0);
            break;
            case null:
                if(i<slices/2.){prog.setAttributeValue(CouleurId, 1.0,0.0, 1.0-i/(slices));}
                else{prog.setAttributeValue(CouleurId, 1.0,0.0, 1.0-(50-i)/(slices)); }
            break;
        }
        prog.setAttributeValue(SommetId, r*cos(i*theta),r*sin(i*theta),h);
   }

   glEnd();
}
//=========================================================================================================

// l'attribut prog d'un VueOpenGL n'a pas de constructeur de copie

// donc on ne peut retourner de copie d'un VueOpenGL

SupportADessin* VueOpenGL::copie() const {}

//=========================================================================================================
void VueOpenGL::changer_vue()
{
    Vue_Tangentielle = not Vue_Tangentielle;
}

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

    //préparation seconde texture
    textureBois= context->bindTexture(QPixmap(":/wood-texture.jpg"), GL_TEXTURE_2D);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
    
    //préparation troisieme texture
    textureOptique= context->bindTexture(QPixmap(":/optical_illusion.jpg"), GL_TEXTURE_2D);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);

   
  //initialise la sphère (resp. sphère tronquée) à l'aide de la class GlSphere (resp. GLSphereCoupe)
  sphere.initialize();
  sphere_coupe.initialize();
  
  //initialisation de la matrice du point de vue
  initializePosition();
}
//=========================================================================================================
void VueOpenGL::initializePosition()
{
  // position initiale
  matrice_vue.setToIdentity();
  matrice_vue.translate(0.0, 0.0, -4.0);
  matrice_vue.rotate(-90.0, 1.0, 0.0, 0.0);
  matrice_vue.translate(0.0, 0.0, -4.0);
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

void VueOpenGL::dessineCylindre(const QMatrix4x4 &point_de_vue, double z_0, double z_1, double r_i,Grandeur_physique grandeur,double psi_point_,double theta_point_,double phi_point_)
{
    prog.setUniformValue("vue_modele", matrice_vue * point_de_vue);

    double slices(50);
    double theta(2*M_PI/slices);

    for(unsigned int i(0);i<slices;++i){
        glBegin(GL_POLYGON);
        prog.setAttributeValue(CouleurId,0.0,0.0,0.0);
        switch (grandeur) {

            case psi_point: prog.setAttributeValue(CouleurId, 0.2+abs(psi_point_)/2.0, 0.0, 0.0);
            break;
            case theta_point: prog.setAttributeValue(CouleurId, 0.0, 0.2+abs(theta_point_)/2.0, 0.0);
            break;
            case phi_point: prog.setAttributeValue(CouleurId, 0.0, 0.0, 0.2+abs(phi_point_)/2.0);
            break;
            case null:
                if(i<slices/2.){prog.setAttributeValue(CouleurId, 1.0,0.0, 1.0-i/(slices));}
                else{prog.setAttributeValue(CouleurId, 1.0,0.0, 1.0-(50-i)/(slices)); }
            break;
        }
        prog.setAttributeValue(SommetId, r_i*sin(i*theta),r_i*cos(i*theta),z_0);
        prog.setAttributeValue(SommetId, r_i*sin(i*theta),r_i*cos(i*theta),z_1);
        prog.setAttributeValue(SommetId, r_i*sin((i+1)*theta),r_i*cos((i+1)*theta),z_1);
        prog.setAttributeValue(SommetId, r_i*sin((i+1)*theta),r_i*cos((i+1)*theta),z_0);
        glEnd();
    }
}

void VueOpenGL::dessineSolideRevolution(const QMatrix4x4 &point_de_vue, double L, std::vector<double> r_i,Grandeur_physique grandeur,double psi_point_,double theta_point_,double phi_point_)
{
    prog.setUniformValue("vue_modele", matrice_vue * point_de_vue);

    double N(r_i.size());

    dessineCylindre(point_de_vue,0,L/(2*N),r_i[0],grandeur,psi_point_,theta_point_,phi_point_);

    dessinePolygon(point_de_vue,L/(2*N),r_i[0],grandeur,psi_point_,theta_point_,phi_point_);

    for(size_t i(1); i<N; ++i) {
        double z_0(((2*i-1)/2.0)*L/N);
        double z_1(((2*(i+1)-1)/2.0)*L/N);
        dessineCylindre(point_de_vue,z_0,z_1,r_i[i],grandeur,psi_point_,theta_point_,phi_point_);
        dessinePolygon(point_de_vue,z_1,r_i[i],grandeur,psi_point_,theta_point_,phi_point_);
    }
}
//=========================================================================================================
void VueOpenGL::dessineCone(QMatrix4x4 const& point_de_vue,double hauteur, double rayon,
                            Grandeur_physique grandeur,double psi_point_,double theta_point_,double phi_point_){


    prog.setUniformValue("vue_modele", matrice_vue * point_de_vue);

    // Attribut la texture 'textureDeChat' à la texture numéro 0 du shader
    QOpenGLFunctions *glFuncs = QOpenGLContext::currentContext()->functions();
    glFuncs->glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, textureOptique);

    double h(hauteur);
    double r(rayon);
    double slices(50);
    double theta(2*M_PI/slices);

    prog.setUniformValue("textureId", 5);
    glBegin(GL_TRIANGLES);

    //apro
    for(unsigned int i(0);i<=slices;++i){
        prog.setAttributeValue(CouleurId,0.0,0.0,0.0);
        switch (grandeur) {

            case psi_point: prog.setAttributeValue(CouleurId, 0.2+abs(psi_point_)/2.0, 0.0, 0.0);
            break;
            case theta_point: prog.setAttributeValue(CouleurId, 0.0, 0.2+abs(theta_point_)/2.0, 0.0);
            break;
            case phi_point: prog.setAttributeValue(CouleurId, 0.0, 0.0, 0.2+abs(phi_point_)/2.0);
            break;
            case null:
                if(i<slices/2.){prog.setAttributeValue(CouleurId, 0.0,0.8, 1.0-i/(slices));}
                else{prog.setAttributeValue(CouleurId, 0.0,0.8, 1.0-(50-i)/(slices)); }
            break;
        }

       prog.setAttributeValue(SommetId, 0.0,0.0,0.0);
       prog.setAttributeValue(SommetId, r*cos((i+1)*theta),r*sin((i+1)*theta),h);
       prog.setAttributeValue(SommetId, r*cos(i*theta),r*sin(i*theta),h);


   }
    glEnd();

    //aproxime un cercle et application dessus de la texture précédemment mise en place
    prog.setUniformValue("textureId", 0);
    glBegin(GL_POLYGON);

    for(unsigned int i(0);i<=slices;i++){

        prog.setAttributeValue(CouleurId, 0.0, 0.0, 0.0);
        prog.setAttributeValue(CoordonneeTextureId,0.5*cos(i*theta)+0.5,0.5*sin(i*theta)+0.5);
        prog.setAttributeValue(SommetId, r*cos(i*theta),r*sin(i*theta),h);

   }
   glEnd();
}

//=========================================================================================================
void VueOpenGL::dessineSphere (QMatrix4x4 const& point_de_vue,
                              Grandeur_physique grandeur,double psi_point_,double theta_point_,double phi_point_)
{
  prog.setUniformValue("vue_modele", matrice_vue * point_de_vue);
  //prends une texture vide pour pouvoir dessiner en couleur
  prog.setUniformValue("textureId", 5);

  //fais varier la couleur de la sphère en fonction des grandeurs physiques rentrées en paramètre
  switch (grandeur) {

      case psi_point: prog.setAttributeValue(CouleurId, 0.2+abs(psi_point_)/2.0, 0.0, 0.0);
      break;
      case theta_point: prog.setAttributeValue(CouleurId, 0.0, 0.2+abs(theta_point_)/2.0, 0.0);
      break;
      case phi_point: prog.setAttributeValue(CouleurId, 0.0, 0.0, 0.2+abs(phi_point_)/2.0);
      break;
      case null:prog.setAttributeValue(CouleurId,0.0,1.0,1.0);
      break;
  }
  // dessine la sphère avec GLSphère
  sphere.draw(prog, SommetId);                           
}
//=========================================================================================================
void VueOpenGL::dessineSphereCoupe (QMatrix4x4 const& point_de_vue,
                               Grandeur_physique grandeur,double psi_point_,double theta_point_,double phi_point_)
{
    //prends une texture vide pour pouvoir dessiner en couleur
    prog.setUniformValue("textureId", 5);

    prog.setUniformValue("vue_modele", matrice_vue * point_de_vue);
  //fais varier la couleur de la sphère en fonction des grandeurs physiques rentrées en paramètre
    switch (grandeur) {

        case psi_point: prog.setAttributeValue(CouleurId, 0.2+abs(psi_point_)/2.0, 0.0, 0.0);
        break;
        case theta_point: prog.setAttributeValue(CouleurId, 0.0, 0.2+abs(theta_point_)/2.0, 0.0);
        break;
        case phi_point: prog.setAttributeValue(CouleurId, 0.0, 0.0, 0.2+abs(phi_point_)/2.0);
        break;
        case null:prog.setAttributeValue(CouleurId, 0.0,1.0,1.0);
        break;
    }
    // dessine la sphère tronqué avec GLSphèreCoupé
    sphere_coupe.draw(prog, SommetId);

   //initialise la texture de chat à la texture 0 et initialise la texture de l'objet à la texture 0
   prog.setUniformValue("textureId", 0);
   QOpenGLFunctions *glFuncs = QOpenGLContext::currentContext()->functions();
   glFuncs->glActiveTexture(GL_TEXTURE0);
   glBindTexture(GL_TEXTURE_2D, textureDeChat);

   double slices(25);
   double beta(2*M_PI/slices);
   double r(0.5877);

   //approxime un cercle avec la texture precedemment mise sur le haut de la sphere tronque
  glBegin(GL_POLYGON);
  for(unsigned int i(0);i<=25;i++){
    prog.setAttributeValue(CouleurId, 0.0,0.0,0.0);
    prog.setAttributeValue(CoordonneeTextureId,r*cos(i*beta)+0.5,r*sin(i*beta)+0.5);
    prog.setAttributeValue(SommetId, r*cos(i*beta),r*sin(i*beta),abs(cos((20*M_PI)/25)));
  }

  glEnd();

}
//=========================================================================================================

void VueOpenGL::dessine(const Toupie &){}
