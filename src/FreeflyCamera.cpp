#include <FreeflyCamera.h>

// Pour palier aux soucis de macro M_PI sous windows , vu que c'est une norme POSX
constexpr double pi() { return std::atan2(0, -1); }

FreeflyCamera::FreeflyCamera() :
		Camera(),
		m_Position(glm::vec3(0, 0, 0)),
		m_fPhi(static_cast<float>(pi())),
		m_fTheta(0),
		m_LeftVector(0, 0, 0),
		m_FrontVector(0, 0, 0),
		m_UpVector(0, 0, 0) {

}

FreeflyCamera::FreeflyCamera(glm::vec3 Position, float phi, float theta) :
		Camera(),
		m_Position(Position),
		m_fPhi(glm::radians(phi)),
		m_fTheta(glm::radians(theta)),
		m_LeftVector(0, 0, 0),
		m_FrontVector(0, 0, 0),
		m_UpVector(0, 0, 0) {
	computeDirectionVectors();
}

void FreeflyCamera::setHorizontalAngle(float degrees) {
	m_fPhi = glm::radians(degrees);
	computeDirectionVectors();
}

void FreeflyCamera::setVerticalAngle(float degrees) {
	m_fTheta = glm::radians(degrees);
	computeDirectionVectors();
}

void FreeflyCamera::setPosition(glm::vec3 position) {
	m_Position = position;
}

void FreeflyCamera::computeDirectionVectors() {
	m_LeftVector = glm::vec3(sin(m_fPhi + pi() / 2),
	                         0,
	                         cos(m_fPhi + pi() / 2));
	m_FrontVector = glm::vec3(std::cos(m_fTheta) * std::sin(m_fPhi),
	                          std::sin(m_fTheta),
	                          std::cos(m_fTheta) * std::cos(m_fPhi));
	m_UpVector = glm::cross(m_FrontVector, m_LeftVector);
}

glm::mat4 FreeflyCamera::getViewMatrix() const {
	return glm::lookAt(m_Position, m_Position + m_FrontVector, m_UpVector);

}
