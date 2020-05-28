attribute vec3 sommet;
attribute vec2 coordonnee_texture;
attribute vec3 couleur;

uniform mat4 projection;
uniform mat4 vue_modele;

varying vec2 ma_coordonnee_texture;
varying vec3 ma_couleur;

void main()
{
  gl_Position = projection * vue_modele * vec4(sommet, 1.0);
  ma_coordonnee_texture = coordonnee_texture;
  ma_couleur = couleur;
}
