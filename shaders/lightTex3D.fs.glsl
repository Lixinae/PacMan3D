#version 330 core

in vec3 vPosition_vs;
in vec3 vNormal_vs;
in vec2 vTexCoords;

out vec4 fFragColor;

uniform sampler2D uTexture;

uniform vec3 uLightDir_vs;
uniform vec3 uLightColor;
uniform float uLightIntensity;

uniform vec3 uKs;
uniform vec3 uKd;
uniform float uShininess;

const float screenGamma = 2.2;

// todo -> Ajouter les variables uniform dans le les localisation dans le shader

// todo -> Sera changé lors du calcul avec les spots light

vec4 blinnPhong(){
    vec3 normal = normalize(vNormal_vs);
    vec3 wi = normalize(uLightDir_vs);
    vec3 w0 = normalize(-vPosition_vs);
    vec3 halfVector = (wi + w0)/2;
	vec3 color = ((uLightColor*uLightIntensity)/(pow(length(uLightDir_vs), 2))) * (uKd*dot(wi,normal) + uKs*pow(dot(halfVector, normal), uShininess));
	return vec4(pow(color, vec3(1.0/screenGamma)), 1.0);
	//return vec4(color, 1.0);
}


void main() {

	fFragColor = texture(uTexture, vTexCoords) *  blinnPhong();

}
