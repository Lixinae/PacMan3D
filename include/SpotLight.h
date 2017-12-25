#ifndef PACMAN3D_SPOTLIGHT_H
#define PACMAN3D_SPOTLIGHT_H

#include <Light.h>

// todo -> Implement
using namespace glm;

class SpotLight : public Light {

    glm::vec3 _position;

    struct {
        float _constant;
        float _linear;
        float _exp;
    } _Attenuation;

};

#endif //PACMAN3D_SPOTLIGHT_H
