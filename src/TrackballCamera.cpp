#include <TrackballCamera.h>

TrackballCamera::TrackballCamera() :
        m_fDistance(5),
        m_fAngleX(0),
        m_fAngleY(0) 
{

}

TrackballCamera::TrackballCamera(glm::vec3 center, float Distance, float AngleX, float AngleY) :
        m_fDistance(Distance),
        m_fAngleX(AngleX),
        m_fAngleY(AngleY) 
{

}

void TrackballCamera::moveFront(float delta) {
    m_fDistance += delta;
}

void TrackballCamera::rotateLeft(float degrees) {
    m_fAngleY += degrees;
}

void TrackballCamera::rotateUp(float degrees) {
    m_fAngleX += degrees;
}

glm::mat4 TrackballCamera::getViewMatrix() const {
    glm::mat4 viewMatrix = glm::translate(glm::mat4(1.f), glm::vec3(0.0f, 0.0f, -m_fDistance));;
    viewMatrix = glm::rotate(viewMatrix, glm::radians(m_fAngleX), glm::vec3(1, 0, 0));
    viewMatrix = glm::rotate(viewMatrix, glm::radians(m_fAngleY), glm::vec3(0, 1, 0));
    return viewMatrix;
}
