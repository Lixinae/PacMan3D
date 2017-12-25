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
		TRACKBALL,
		FREEFLY
	};

	PointOfView(const BoardPosition & position, Utils::Orientation orientation);
	
	
	TrackballCamera & getTrackballCamera();
	FreeflyCamera & getFreeflyCamera();
	
	const Camera & getCurrentCamera() const;
	
	CameraType getCurrentCameraType() const;
	
	void setNextCamera();

private:
	
	TrackballCamera _trackballCamera;
	FreeflyCamera _freeflyCamera;
	CameraType _current;
	
};

#endif
