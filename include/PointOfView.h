#ifndef __POINT_OF_VIEW_H__
#define __POINT_OF_VIEW_H__

#include <Camera.h>

class PointOfView {

public:

	PointOfView(const Camera * camera);

	~PointOfView();

	const Camera * getCamera() const;
	void setCamera(const Camera * camera);

private:

	Camera * _camera;

};

#endif
