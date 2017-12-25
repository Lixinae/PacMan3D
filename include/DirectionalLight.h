
#ifndef PACMAN3D_DIRECTIONALLIGHT_H
#define PACMAN3D_DIRECTIONALLIGHT_H

#include <Light.h>

using namespace glm;

/**
 * Lumiere directionnel
 **/
class DirectionalLight : public Light {

private:
    Light _baseLight;

    float _intensity;
    vec3 _direction;
    vec3 _ambientColor;
    vec3 _diffuseColor;


public:
    DirectionalLight(const vec3 &color, float ambientIntensity, float diffuseIntensity,
                     const vec3 &_direction, float intensity, const vec3 &ambientColor, const vec3 &diffuseColor);

    float getIntensity() const;

    const vec3 &getDirection() const;

    const vec3 &getAmbientColor() const;

    const vec3 &getDiffuseColor() const;
};


#endif //PACMAN3D_DIRECTIONALLIGHT_H
