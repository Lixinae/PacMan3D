#include <FreeflyCamera.h>

// Pour palier aux soucis de macro M_PI sous windows , vu que c'est une norme POSX
constexpr double pi() { return std::atan2(0, -1); }

FreeflyCamera::FreeflyCamera() :
        Camera(),
        m_Position(0, 0, 0),
        m_fPhi(static_cast<float>(pi())),
        m_fTheta(0),
        m_LeftVector(0, 0, 0),
        m_FrontVector(0, 0, 0),
        m_UpVector(0, 0, 0) {
    computeDirectionVectors();
}

FreeflyCamera::FreeflyCamera(glm::vec3 Position) :
        Camera(),
        m_Position(Position),
        m_fPhi(static_cast<float>(pi())),
        m_fTheta(0),
        m_LeftVector(0, 0, 0),
        m_FrontVector(0, 0, 0),
        m_UpVector(0, 0, 0) {
    computeDirectionVectors();
}

void FreeflyCamera::rotateHorizontal(float degrees) {
    degrees = glm::radians(degrees);
    m_fPhi += degrees;
    computeDirectionVectors();
}

void FreeflyCamera::rotateVertical(float degrees) {
    degrees = glm::radians(degrees);
    m_fTheta += degrees;
    computeDirectionVectors();
}

void FreeflyCamera::moveFront(float t) {
    m_Position += t * m_FrontVector;
}

void FreeflyCamera::moveHorizontal(float t) {
    m_Position += t * m_LeftVector;
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
