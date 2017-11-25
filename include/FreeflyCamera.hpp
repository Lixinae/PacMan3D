#include "glimac/common.hpp"

class FreeflyCamera{

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
	void rotateLeft(float degrees);
    /**
     * Permet de faire tourner la camera vers le haut ou le bas(en ajoutant ou en enlevant des degrées)
     * @param degrees
     */
	void rotateUp(float degrees);
	/**
	 * Permet d'avancer ou de reculer la camera
	 * @param t
	 */
    void moveFront(float t);
	/**
	 * Permet de deplacer la camera vers la gauche ou la droite
	 * @param t
	 */
    void moveLeft(float t);

    /**
     * Calcul la viewMatrix de la camera et la renvoie
     * @return La viewMatrix de la camera
     */
	glm::mat4 getViewMatrix() const;
};
