uniform sampler2D textureId;

varying vec2 ma_coordonnee_texture;
varying vec3 ma_couleur;

void main()
{
  gl_FragColor = texture2D(textureId, ma_coordonnee_texture) + vec4(ma_couleur, 1.0);

}
