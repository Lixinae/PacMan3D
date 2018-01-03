
#include <DirectionalLight.h>

DirectionalLight::DirectionalLight(const vec3 &color,
                                   const vec3 &direction, float intensity) :
		Light::Light(color, intensity),
		_direction(direction) {

}

const vec3 &DirectionalLight::getDirection() const {
	return _direction;
}

DirectionalLight *DirectionalLight::clone() const {
	return new DirectionalLight(*this);
}

DirectionalLight *DirectionalLight::fromJSON(const json &jsonLight) {
	vec3 position = vec3(jsonLight["direction"]["x"], jsonLight["direction"]["y"], jsonLight["direction"]["z"]);
	vec3 color = vec3(jsonLight["color"]["x"], jsonLight["color"]["y"], jsonLight["color"]["z"]);
	float intensity = jsonLight["intensity"];
	return new DirectionalLight(color, position, intensity);
}