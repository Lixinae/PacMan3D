#include <PointOfView.h>

#include <Camera.h>

PointOfView::PointOfView(const Camera * camera) : _camera(camera->clone()) {

}

PointOfView::~PointOfView() {
	delete _camera;
}

const Camera * PointOfView::getCamera() const {
	return _camera;
}

void PointOfView::setCamera(const Camera * camera) {
	delete _camera;
	_camera = camera->clone();
}
