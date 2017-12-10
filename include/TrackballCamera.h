#ifndef __TRACKBALL_CAMERA_H__
#define __TRACKBALL_CAMERA_H__

#include <glimac/common.hpp>
#include <Camera.h>

class TrackballCamera :public Camera {

private:

	float m_fDistance, m_fAngleX, m_fAngleY;

public:

	TrackballCamera();
	TrackballCamera(float Distance, float AngleX, float AngleY);

	void moveFront(float delta) override;

	void rotateHorizontal(float degrees) override;
	
	void rotateVertical(float degrees) override;

    void moveHorizontal(float t) override;
	glm::mat4 getViewMatrix() const override;
	
};

#endif

