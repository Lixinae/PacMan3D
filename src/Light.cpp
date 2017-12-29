#include <Light.h>


Light::Light() : _color(vec3(0.f, 0.f, 0.f)) {}

Light::Light(const vec3 &color) :
		_color(color) {}

const vec3 &Light::getColor() const {
	return _color;
}


