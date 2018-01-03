#ifndef PACMAN3D_DIRECTIONALLIGHT_H
#define PACMAN3D_DIRECTIONALLIGHT_H

#include <Light.h>
#include <json/json.hpp>

using namespace glm;

using json = nlohmann::json;


class DirectionalLight : public Light {

private:
	vec3 _direction;

	DirectionalLight(const vec3 &color, const vec3 &_direction, float intensity);

public:
	/**
	 *
	 * @return La direction de la lumiere
	 */
	const vec3 &getDirection() const;

	/**
	 *
	 * @return Une copie de la lumiere
	 */
	DirectionalLight *clone() const;

	/**
	 *
	 * @param jsonLight Json ou lire les données
	 * @return Une nouvelle lumière directionnel
	 */
	static DirectionalLight *fromJSON(const json &jsonLight);
};


#endif
