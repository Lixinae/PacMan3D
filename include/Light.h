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

public:
	Light();

	Light(const vec3 &color);

	const vec3 &getColor() const;
};


#endif
