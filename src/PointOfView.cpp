#include <PointOfView.h>


PointOfView::PointOfView() : _trackballCamera(25,45,15), _trackballCamera2(25,45,-15), _current(0) {


}

Camera & PointOfView::getCurrentCamera() {
	if (_current == 0) {
		return _trackballCamera;
	} else {
		return _trackballCamera2;
	}
}

void PointOfView::setNextCamera() {
	_current = (_current + 1)%2;
}
