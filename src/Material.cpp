#include <Material.h>

Material::Material(float shininess, const vec3 &diffuse, const vec3 &glossy) :
		_shininess(shininess),
		_diffuse(diffuse),
		_glossy(glossy) {

}

Material Material::fromJSON(const json &jsonMaterial) {
	float shininess = jsonMaterial["shininess"];
	vec3 diffuse = vec3(jsonMaterial["diffuse"]["x"], jsonMaterial["diffuse"]["y"], jsonMaterial["diffuse"]["z"]);
	vec3 glossy = vec3(jsonMaterial["glossy"]["x"], jsonMaterial["glossy"]["y"], jsonMaterial["glossy"]["z"]);
	return Material(shininess, diffuse, glossy);
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
