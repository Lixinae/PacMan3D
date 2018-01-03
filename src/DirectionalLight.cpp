
#include <DirectionalLight.h>

DirectionalLight::DirectionalLight(const vec3 &color,
                                   const vec3 &direction, float intensity) :
		Light::Light(color, intensity),
		_direction(direction) {

}

const vec3 &DirectionalLight::getDirection() const {
	return _direction;
}
