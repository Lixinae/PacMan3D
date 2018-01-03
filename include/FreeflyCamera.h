#ifndef __FREEFLY_CAMERA_H__
#define __FREEFLY_CAMERA_H__

#include <glimac/common.hpp>
#include <Camera.h>

class FreeflyCamera : public Camera {

private:

	glm::vec3 m_Position;
	float m_fPhi, m_fTheta;
	glm::vec3 m_FrontVector, m_LeftVector, m_UpVector;

	void computeDirectionVectors();

public:

	FreeflyCamera();

	FreeflyCamera(glm::vec3 Position, float phi, float theta);

	/**
	 * Change l'angle horizontal de la camera
	 * @param degrees Nombre de degrées à ajouter à l'angle
	 */
	void setHorizontalAngle(float degrees);

	void setVerticalAngle(float degrees);

	/**
	 * Change la position de la camera
	 * @param position La nouvelle position de la camera
	 */
	void setPosition(glm::vec3 position);

	/**
	 * Calcul la viewMatrix de la camera et la renvoie
	 * @return La viewMatrix de la camera
	 */
	glm::mat4 getViewMatrix() const override;

};

#endif
