#include <Wall.h>

#include <Pacman.h>
#include <BoardSquare.h>
#include <GameRepresentation.h>

Wall::Wall() {

}
	
vector<GameRepresentation::Model> Wall::getModels() const {
	return {GameRepresentation::Model::WALL};
}
	
bool Wall::isWalkable() const {
	return false;
}
	
void Wall::receive(BoardSquare::Context &) {
	// Do nothing : should never be call
}

BoardSquare * Wall::clone() {
	return new Wall(*this);
}
