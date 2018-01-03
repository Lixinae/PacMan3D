#ifndef PACMAN3D_LIGHT_H
#define PACMAN3D_LIGHT_H

#include <glm/vec3.hpp>

using namespace glm;

/**
 * Lumiere de base -> sera utilisé dans tous les lumieres
 */
class Light {
private:
	vec3 _color;
	float _intensity;

public:
	Light(const vec3 &color, float intensity);

	const vec3 &getColor() const;

	float getIntensity() const;
};


#endif
