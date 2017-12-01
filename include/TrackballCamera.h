#ifndef __FREEFLY_CAMERA_H__
#define __FREEFLY_CAMERA_H__

#include <glimac/common.hpp>

class TrackballCamera{

private:
	float m_fDistance,m_fAngleX,m_fAngleY;

public:
	TrackballCamera();
	TrackballCamera(float m_fDistance,float m_fAngleX,float m_fAngleY);

	void moveFront(float delta);

	void rotateHorizontal(float degrees);
	
	void rotateVertical(float degrees);

	glm::mat4 getViewMatrix() const;
};

#endif

