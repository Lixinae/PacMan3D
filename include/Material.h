#ifndef __MATERIAL_H__
#define __MATERIAL_H__

#include <glm/vec3.hpp>
#include <json/json.hpp>

using namespace glm;

using json = nlohmann::json;

class Material {

public:

	static Material fromJSON(const json & jsonMaterial);

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
