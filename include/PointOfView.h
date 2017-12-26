#ifndef __POINT_OF_VIEW_H__
#define __POINT_OF_VIEW_H__

#include <Camera.h>
#include <TrackballCamera.h>
#include <FreeflyCamera.h>
#include <BoardPosition.h>
#include <Utils.h>

class PointOfView {

public:

	enum class CameraType {
		UPPER_LEFT,
		UPPER,
		UPPER_RIGHT,
		FIRST_PERSON
	};

	PointOfView(const BoardPosition & position, Utils::Orientation orientation);
	
	
	TrackballCamera & getUpperLeftCamera();
	TrackballCamera & getUpperCamera();
	TrackballCamera & getUpperRightCamera();
	FreeflyCamera & getFirstPersonCamera();
	
	const Camera & getCurrentCamera() const;
	
	CameraType getCurrentCameraType() const;
	
	void setNextCamera();

private:
	
	TrackballCamera _leftTrackballCamera;
	TrackballCamera _upperTrackballCamera;
	TrackballCamera _rightTrackballCamera;
	FreeflyCamera _freeflyCamera;
	CameraType _current;
	
};

#endif
