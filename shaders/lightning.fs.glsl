#version 330 core


in vec3 vPosition_vs;
in vec3 vNormal_vs;
in vec2 vTexCoords;

out vec4 fFragColor;


uniform sampler2D uTexture;


const float screenGamma = 2.2; // Assume the monitor is calibrated to the sRGB color space
const vec3 specularColor = vec3(1.0, 1.0, 1.0);

// todo -> Ajouter les variables uniform dans le les localisation dans le shader

// Variable uniform propre a la matière de l'objet
uniform float uShininess;

// Variable uniform pour la directionnal light
uniform vec3 uLightDirection;
uniform vec3 uAmbiantColor;
uniform vec3 uDiffuseColor;
uniform vec3 uLightColor;
uniform float uLightIntensity; // Intensité de la lumiere

// todo -> Sera changé lors du calcul avec les spots light

vec4 blinnPhong(){
    vec3 normal = normalize(vNormal_vs);
    vec3 lightDir = uLightDirection;
    float distance = length(lightDir);
    distance = distance * distance;
    lightDir = normalize(lightDir);
    float lambertian = max(dot(lightDir,normal), 0.0);
    float specular = 0.0;

    if(lambertian > 0.0) {
        vec3 viewDir = normalize(-vPosition_vs);
        // this is blinn phong
        vec3 halfDir = normalize(lightDir + viewDir);
        float specAngle = max(dot(halfDir, normal), 0.0);
        specular = pow(specAngle, uShininess);
    }


    vec3 colorLinear = uAmbiantColor +
                       uDiffuseColor * lambertian * uLightColor * uLightIntensity / distance +
                         specularColor * specular * uLightColor * uLightIntensity / distance;
    // apply gamma correction (assume ambientColor, diffuseColor and specColor
    // have been linearized, i.e. have no gamma correction in them)
    vec3 colorGammaCorrected = pow(colorLinear, vec3(1.0/screenGamma));
    // use the gamma corrected color in the fragment
    vec4 outColor = vec4(colorGammaCorrected, 1.0);
    return outColor;
}


void main() {

    vec4 color = blinnPhong();
	fFragColor = texture(uTexture, vTexCoords) * color;

}