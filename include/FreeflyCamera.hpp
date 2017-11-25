#include "glimac/common.hpp"

class FreeflyCamera{

private:
	glm::vec3 m_Position;
	float m_fPhi,m_fTheta;
	glm::vec3 m_FrontVector,m_LeftVector, m_UpVector;

	void computeDirectionVectors();
public:
	FreeflyCamera();
	FreeflyCamera(const glm::vec3 m_Position);
	void rotateLeft(float degrees);
	void rotateUp(float degrees);
	void moveFront(float t);
	void moveLeft(float t);

	glm::mat4 getViewMatrix() const;
};
