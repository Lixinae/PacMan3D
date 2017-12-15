#ifndef __POINT_OF_VIEW_H__
#define __POINT_OF_VIEW_H__

#include <Camera.h>
#include <TrackballCamera.h>

class PointOfView {

public:

	PointOfView();
	
	Camera & getCurrentCamera();
	void setNextCamera();

private:
	
	TrackballCamera _trackballCamera;
	TrackballCamera _trackballCamera2;
	int _current;
	
};

#endif
