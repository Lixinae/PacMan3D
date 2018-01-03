#version 330 core

in vec3 vPosition_vs;
in vec3 vNormal_vs;
in vec2 vTexCoords;

out vec4 fFragColor;

uniform sampler2D uTexture;

uniform vec3 uLightDir_vs;
uniform vec3 uLightPos_vs;

uniform vec3 uLightColorDirectional;
uniform vec3 uLightColorSpot;
uniform float uLightIntensityDirectional;
uniform float uLightIntensitySpot;

uniform vec3 uKs;
uniform vec3 uKd;
uniform float uShininess;

const float screenGamma = 2.2;

vec4 blinnPhongDirectionnal(){
    vec3 normal = normalize(vNormal_vs);
    vec3 wi = normalize(uLightDir_vs);
    vec3 w0 = normalize(-vPosition_vs);
    vec3 halfVector = (wi + w0)/2;
    vec3 li = uLightColorDirectional*(uLightIntensityDirectional)/(pow(length(uLightDir_vs), 8));
	vec3 color = li * (uKd*dot(wi,normal) + uKs*pow(dot(halfVector, normal), uShininess));
	return vec4(pow(color, vec3(1.0/screenGamma)), 1.0);
}

vec4 blinnPhongSpot(){
    vec3 normal = normalize(vNormal_vs);
    vec3 wi = normalize(uLightPos_vs - vPosition_vs);
    vec3 w0 = normalize(-vPosition_vs);
    vec3 halfVector = (wi + w0)/2;
    float d = distance(uLightPos_vs, vPosition_vs);
    vec3 li = uLightColorSpot*(uLightIntensitySpot / (d * d));
	vec3 color = li * (uKd*dot(wi,normal) + uKs*pow(dot(halfVector, normal), uShininess));
	return vec4(pow(color, vec3(1.0/screenGamma)), 1.0);
}


void main() {

//	fFragColor = texture(uTexture, vTexCoords) *  blinnPhongDirectionnal();
//	fFragColor = texture(uTexture, vTexCoords) *  blinnPhongSpot();
	fFragColor = texture(uTexture, vTexCoords) *  blinnPhongSpot() * blinnPhongDirectionnal();

}
