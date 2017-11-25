#include "wall.h"

#include "pacman.h"
#include "boardSquare.h"
#include "renderer.h"

Wall::Wall() {

}
	
Renderer::Model Wall::getModel() const {
	return Renderer::Model::WALL;
}
	
bool Wall::isWalkable() const {
	return false;
}
	
void Wall::receive(Pacman) {
	// Do nothing : should never be call
}
