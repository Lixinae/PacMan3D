#include <Material.h>

Material::Material(float shininess, const vec3 &diffuse, const vec3 &glossy) :
	_shininess(shininess),
	_diffuse(diffuse),
	_glossy(glossy)
{
	
}

float Material::getShininess() const {
	return _shininess;
}

vec3 Material::getDiffuse() const {
	return _diffuse;
}

vec3 Material::getGlossy() const {
	return _glossy;
}
