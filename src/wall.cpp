#include "wall.h"

#include "pacman.h"
#include "boardSquare.h"
#include "boardRepresentation.h"

Wall::Wall() {

}
	
BoardRepresentation::Model Wall::getModel() const {
	return BoardRepresentation::Model::WALL;
}
	
bool Wall::isWalkable() const {
	return false;
}
	
void Wall::receive(Pacman) {
	// Do nothing : should never be call
}
