#ifndef __FREEFLY_CAMERA_H__
#define __FREEFLY_CAMERA_H__

#include <glimac/common.hpp>
#include <Camera.h>

class FreeflyCamera: public Camera{

private:

	glm::vec3 m_Position;
	float m_fPhi, m_fTheta;
	glm::vec3 m_FrontVector ,m_LeftVector, m_UpVector;

	void computeDirectionVectors();
	
public:

	FreeflyCamera();

    FreeflyCamera(glm::vec3 Position, float phi, float theta);

	void setHorizontalAngle(float degrees);
	void setVerticalAngle(float degrees);
	
	void setPosition(glm::vec3 position);
	
    /**
     * Calcul la viewMatrix de la camera et la renvoie
     * @return La viewMatrix de la camera
     */
	glm::mat4 getViewMatrix() const override;
	
};

#endif
