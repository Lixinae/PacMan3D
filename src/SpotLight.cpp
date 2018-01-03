//
// Created by ValasNaerth on 03/01/2018.
//

#include <SpotLight.h>

SpotLight::SpotLight(const vec3 &color, const vec3 &position, float intensity) : Light(color, intensity), _position(position) {}

const vec3 &SpotLight::getPosition() const {
	return _position;
}

SpotLight *SpotLight::clone() const {
	return new SpotLight(*this);
}

SpotLight *SpotLight::fromJSON(const json &jsonLight) {
	vec3 position = vec3(jsonLight["position"]["x"], jsonLight["position"]["y"], jsonLight["position"]["z"]);
	vec3 color = vec3(jsonLight["color"]["x"], jsonLight["color"]["y"], jsonLight["color"]["z"]);
	float intensity = jsonLight["intensity"];
	return new SpotLight(color, position, intensity);
}
