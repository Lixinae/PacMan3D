#ifndef PACMAN3D_SPOTLIGHT_H
#define PACMAN3D_SPOTLIGHT_H

#include <Light.h>
#include <json/json.hpp>

// todo -> Implement
using namespace glm;
using json = nlohmann::json;

class SpotLight : public Light {

private:
	vec3 _position;

	SpotLight(const vec3 &color, const vec3 &position, float intensity);

public:

	const vec3 &getPosition() const;

	SpotLight *clone() const;

	static SpotLight *fromJSON(const json &jsonLight);
};

#endif //PACMAN3D_SPOTLIGHT_H
