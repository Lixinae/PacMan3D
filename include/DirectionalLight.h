#ifndef PACMAN3D_DIRECTIONALLIGHT_H
#define PACMAN3D_DIRECTIONALLIGHT_H

#include <Light.h>

using namespace glm;

/**
 * Lumiere directionnel
 **/
class DirectionalLight : public Light {

private:
	vec3 _direction;


public:
	DirectionalLight(const vec3 &color, const vec3 &_direction, float intensity);

	const vec3 &getDirection() const;

};


#endif
