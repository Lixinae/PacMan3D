#ifndef __FREEFLY_CAMERA_H__
#define __FREEFLY_CAMERA_H__

#include <glimac/common.hpp>
#include <Camera.h>

class FreeflyCamera: public Camera{

private:
	glm::vec3 m_Position;
	float m_fPhi,m_fTheta;
	glm::vec3 m_FrontVector,m_LeftVector, m_UpVector;

	void computeDirectionVectors();
public:
	FreeflyCamera();

    explicit FreeflyCamera(glm::vec3 m_Position);
    /**
     * Permet de faire tourner la camera vers la gauche ou la droite (en ajoutant ou en enlevant des degrées)
     * @param degrees
     */
	void rotateHorizontal(float degrees) override;
    /**
     * Permet de faire tourner la camera vers le haut ou le bas(en ajoutant ou en enlevant des degrées)
     * @param degrees
     */
	void rotateVertical(float degrees) override;
	/**
	 * Permet d'avancer ou de reculer la camera
	 * @param t
	 */
    void moveFront(float t) override;
	/**
	 * Permet de deplacer la camera vers la gauche ou la droite
	 * @param t
	 */
    void moveHorizontal(float t) override;

    /**
     * Calcul la viewMatrix de la camera et la renvoie
     * @return La viewMatrix de la camera
     */
	glm::mat4 getViewMatrix() const override;
};

#endif
