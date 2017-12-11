#include <PointOfView.h>


PointOfView::PointOfView() : _camera(nullptr) {

}

const Camera * PointOfView::getCamera() const {
	return _camera;
}

void PointOfView::setCamera(Camera * camera) {
	_camera = camera;
}
