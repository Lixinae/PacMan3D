#ifndef __POINT_OF_VIEW_H__
#define __POINT_OF_VIEW_H__

#include <Camera.h>

class PointOfView {

// TODO get all the camera used

public:

	PointOfView(Camera * camera);

	const Camera * getCamera() const;
	void setCamera(Camera * camera);

private:

	Camera * _camera;

};

#endif
