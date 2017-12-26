#include <PointOfView.h>

using namespace glm;

PointOfView::PointOfView(const BoardPosition &position, Utils::Orientation orientation) :
		_leftTrackballCamera(position.inSpace(), 25, 45, 15),
		_upperTrackballCamera(position.inSpace(), 20, 90, 0),
		_rightTrackballCamera(position.inSpace(), 25, 45, -15),
		_freeflyCamera(position.inSpace(), Utils::degreesOfOrientation(orientation), 0),
		_current(PointOfView::CameraType::UPPER_LEFT) {


}

PointOfView::CameraType PointOfView::getCurrentCameraType() const {
	return _current;
}

TrackballCamera &PointOfView::getUpperLeftCamera() {
	return _leftTrackballCamera;
}

TrackballCamera &PointOfView::getUpperCamera() {
	return _upperTrackballCamera;
}

TrackballCamera &PointOfView::getUpperRightCamera() {
	return _rightTrackballCamera;
}

FreeflyCamera &PointOfView::getFirstPersonCamera() {
	return _freeflyCamera;
}

const Camera &PointOfView::getCurrentCamera() const {
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
