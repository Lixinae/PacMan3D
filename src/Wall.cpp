#include <Wall.h>

#include <Pacman.h>
#include <BoardSquare.h>
#include <BoardRepresentation.h>

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
