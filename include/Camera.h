#ifndef PACMAN3D_CAMERA_H
#define PACMAN3D_CAMERA_H


#include <glm/detail/type_mat.hpp>

class Camera {

public:

	Camera() = default;

	/**
	 * Calcul la viewMatrix de la camera et la renvoie
	 * @return La viewMatrix de la camera
	 */
	virtual glm::mat4 getViewMatrix() const = 0;

};

#endif
