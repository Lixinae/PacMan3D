
#include <DirectionalLight.h>

DirectionalLight::DirectionalLight(const vec3 &color, float ambientIntensity, float diffuseIntensity,
                                   const vec3 &direction, float intensity, const vec3 &ambientColor,
                                   const vec3 &diffuseColor) :
        _baseLight(color, ambientIntensity, diffuseIntensity),
        _direction(direction),
        _intensity(intensity),
        _ambientColor(ambientColor),
        _diffuseColor(diffuseColor) {

}

float DirectionalLight::getIntensity() const {
    return _intensity;
}

const vec3 &DirectionalLight::getDirection() const {
    return _direction;
}

const vec3 &DirectionalLight::getAmbientColor() const {
    return _ambientColor;
}

const vec3 &DirectionalLight::getDiffuseColor() const {
    return _diffuseColor;
}
