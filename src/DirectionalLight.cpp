
#include <DirectionalLight.h>

DirectionalLight::DirectionalLight(const vec3 &color,
                                   const vec3 &direction, float intensity) :
		Light::Light(color),
		_direction(direction),
		_intensity(intensity) {

}

float DirectionalLight::getIntensity() const {
	return _intensity;
}

const vec3 &DirectionalLight::getDirection() const {
	return _direction;
}
