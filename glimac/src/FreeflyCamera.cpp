#include "glimac/FreeflyCamera.hpp"
#include <iostream>
#define _USE_MATH_DEFINES
 
#include <cmath>
FreeflyCamera::FreeflyCamera():	
	m_Position(0,0,0),m_fPhi(M_PI),m_fTheta(0){
	computeDirectionVectors();
}

void FreeflyCamera::rotateLeft(float degrees){
	degrees = glm::radians(degrees);
	m_fPhi+=degrees;
	computeDirectionVectors();
}
	
void FreeflyCamera::rotateUp(float degrees){
	degrees = glm::radians(degrees);
	m_fTheta+=degrees;
	computeDirectionVectors();
}

void FreeflyCamera::moveFront(float t){
	m_Position += t*m_FrontVector;
}

void FreeflyCamera::moveLeft(float t){
	m_Position += t*m_LeftVector;
}

void FreeflyCamera::computeDirectionVectors(){
	m_LeftVector = glm::vec3(sin(m_fPhi+M_PI/2),0,cos(m_fPhi+M_PI/2));
	m_FrontVector = glm::vec3(cos(m_fTheta)*sin(m_fPhi),sin(m_fTheta),cos(m_fTheta)*cos(m_fPhi));
	m_UpVector = glm::cross(m_FrontVector, m_LeftVector);
}

glm::mat4 FreeflyCamera::getViewMatrix() const{
	return glm::lookAt(m_Position, m_Position+m_FrontVector, m_UpVector);  // todo

}