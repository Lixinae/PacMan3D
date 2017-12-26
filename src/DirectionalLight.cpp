
#include <DirectionalLight.h>

DirectionalLight::DirectionalLight(const vec3 &color, float ambientIntensity, float diffuseIntensity,
                                   const vec3 &direction, float intensity) :
        _baseLight(color, ambientIntensity, diffuseIntensity),
        _direction(direction),
        _intensity(intensity), {

}

float DirectionalLight::getIntensity() const {
    return _intensity;
}

const vec3 &DirectionalLight::getDirection() const {
    return _direction;
}
