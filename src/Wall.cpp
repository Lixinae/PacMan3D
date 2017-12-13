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
	
void Wall::receive(Pacman) {
	// Do nothing : should never be call
}
