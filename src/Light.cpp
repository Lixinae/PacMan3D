#include <Light.h>

Light::Light(const vec3 &color, float intensity) :
		_color(color), _intensity(intensity) {}

const vec3 &Light::getColor() const {
	return _color;
}

float Light::getIntensity() const {
	return _intensity;
}

