
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


public:
    DirectionalLight(const vec3 &color, float ambientIntensity, float diffuseIntensity,
                     const vec3 &_direction, float intensity);

    float getIntensity() const;

    const vec3 &getDirection() const;

};


#endif //PACMAN3D_DIRECTIONALLIGHT_H
