#include <PointOfView.h>

#include <Camera.h>

PointOfView::PointOfView(Camera * camera) : _camera(camera) {

}

const Camera * PointOfView::getCamera() const {
	return _camera;
}

void PointOfView::setCamera(Camera * camera) {
	_camera = camera;
}
