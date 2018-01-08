#version 330 core

in vec3 vPosition_vs;
in vec3 vNormal_vs;
in vec2 vTexCoords;

out vec4 fFragColor;

uniform sampler2D uTexture;

//uniform vec3 uLightDir_vs;
uniform vec3 uLightPos_vs;
uniform vec3 uLightPosSpotCamera_vs;

uniform vec3 uLightColorSpotCamera;
uniform vec3 uLightColorSpot;
uniform float uLightIntensitySpotCamera;
uniform float uLightIntensitySpot;

uniform vec3 uKs;
uniform vec3 uKd;
uniform float uShininess;

const float screenGamma = 2.2;

//vec3 blinnPhongDirectionnal(){
//    vec3 normal = normalize(vNormal_vs);
//    vec3 wi = normalize(uLightDir_vs);
//    vec3 w0 = normalize(-vPosition_vs);
//    vec3 halfVector = (wi + w0)/2;
//    vec3 li = uLightColorDirectional*(uLightIntensityDirectional)/(pow(length(uLightDir_vs), 2));
//
//	vec3 diffuse = uKd*dot(wi,normal);
//    vec3 specular = uKs*pow(dot(halfVector, normal), uShininess);
//    vec3 color = li * (diffuse + specular);
//	return color;
//}

vec3 blinnPhongSpot(vec3 lightPos,vec3 lightColor,float intensity){
    vec3 normal = normalize(vNormal_vs);
    vec3 wi = normalize(lightPos - vPosition_vs);
    vec3 w0 = normalize(-vPosition_vs);
    vec3 halfVector = (wi + w0)/2;
    float d = distance(lightPos, vPosition_vs);
    vec3 li = lightColor*(intensity / (d * d));
    vec3 diffuse = uKd*dot(wi,normal);
    vec3 specular = uKs*pow(dot(halfVector, normal), uShininess);
    vec3 color = li * (diffuse + specular);
    return color;
}


void main() {
    vec3 bpSpot = blinnPhongSpot(uLightPos_vs,uLightColorSpot,uLightIntensitySpot);
    vec3 bpSpotCamera = blinnPhongSpot(uLightPosSpotCamera_vs,uLightColorSpotCamera,uLightIntensitySpotCamera);
    vec3 light = bpSpot + bpSpotCamera ; //+ blinnPhongDirectionnal();
	fFragColor = texture(uTexture, vTexCoords) * vec4(light,1.0) ;

}
