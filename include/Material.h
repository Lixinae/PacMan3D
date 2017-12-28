#ifndef __MATERIAL_H__
#define __MATERIAL_H__

#include <glm/vec3.hpp>

using namespace glm;

class Material {

public:

	Material(float shininess, const vec3 &diffuse, const vec3 &glossy);
	
	float getShininess() const;
	
	vec3 getDiffuse() const;
	
	vec3 getGlossy() const;
	
private:
	
	float _shininess;
	vec3 _diffuse;
	vec3 _glossy;
	
};


#endif //PACMAN3D_LIGHT_H
