#include <Light.h>


Light::Light() : _color(vec3(0.f, 0.f, 0.f)),
                 _ambientIntensity(0.f),
                 _diffuseIntensity(0.f) {}

Light::Light(const vec3 &color, float ambientIntensity, float diffuseIntensity) :
        _color(color),
        _ambientIntensity(ambientIntensity),
        _diffuseIntensity(diffuseIntensity) {}

const vec3 &Light::getColor() const {
    return _color;
}

float Light::getAmbientIntensity() const {
    return _ambientIntensity;
}

float Light::getDiffuseIntensity() const {
    return _diffuseIntensity;
}


