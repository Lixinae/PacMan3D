#include <PointOfView.h>

using namespace glm;

PointOfView::PointOfView(const BoardPosition & position, Utils::Orientation orientation) :
	_leftTrackballCamera(25,45,15), // TODO compute in function of position
	_upperTrackballCamera(25,90,0), //
	_rightTrackballCamera(25,45,-15), //
	_freeflyCamera(vec3(0,1,0), Utils::degreesOfOrientation(orientation), 0), 
	_current(PointOfView::CameraType::UPPER_LEFT) 
{


}

PointOfView::CameraType PointOfView::getCurrentCameraType() const {
	return _current;
}

TrackballCamera & PointOfView::getUpperLeftCamera() {
	return _leftTrackballCamera;
}

TrackballCamera & PointOfView::getUpperCamera() {
	return _upperTrackballCamera;
}

TrackballCamera & PointOfView::getUpperRightCamera() {
	return _rightTrackballCamera;
}

FreeflyCamera & PointOfView::getFirstPersonCamera() {
	return _freeflyCamera;
}

const Camera & PointOfView::getCurrentCamera() const {
	if (_current == PointOfView::CameraType::UPPER_LEFT) {
		return _leftTrackballCamera;
	} else if (_current == PointOfView::CameraType::UPPER) {
		return _upperTrackballCamera;
	} else if (_current == PointOfView::CameraType::UPPER_RIGHT) {
		return _rightTrackballCamera;
	} else {
		return _freeflyCamera;
	}
}

void PointOfView::setNextCamera() {
	if (_current == PointOfView::CameraType::UPPER_LEFT) {
		_current = PointOfView::CameraType::UPPER;
	} else if (_current == PointOfView::CameraType::UPPER) {
		_current = PointOfView::CameraType::UPPER_RIGHT;
	} else if (_current == PointOfView::CameraType::UPPER_RIGHT) {
		_current = PointOfView::CameraType::FIRST_PERSON;
	} else {
		_current = PointOfView::CameraType::UPPER_LEFT;
	}
}
