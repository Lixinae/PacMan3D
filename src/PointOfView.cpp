#include <PointOfView.h>

using namespace glm;

PointOfView::PointOfView(const BoardPosition & position, Utils::Orientation orientation) :
	_trackballCamera(25,45,15),
	_freeflyCamera(vec3(0,1,0), Utils::degreesOfOrientation(orientation), 0), 
	_current(PointOfView::CameraType::TRACKBALL) 
{


}

PointOfView::CameraType PointOfView::getCurrentCameraType() const {
	return _current;
}

TrackballCamera & PointOfView::getTrackballCamera() {
	return _trackballCamera;
}

FreeflyCamera & PointOfView::getFreeflyCamera() {
	return _freeflyCamera;
}

const Camera & PointOfView::getCurrentCamera() const {
	if (_current == PointOfView::CameraType::TRACKBALL) {
		return _trackballCamera;
	} else {
		return _freeflyCamera;
	}
}

void PointOfView::setNextCamera() {
	if (_current == PointOfView::CameraType::TRACKBALL) {
		_current = PointOfView::CameraType::FREEFLY;
	} else {
		_current = PointOfView::CameraType::TRACKBALL;
	}
}
