#include <Wall.h>

#include <Pacman.h>
#include <BoardSquare.h>
#include <GameRepresentation.h>

Wall::Wall() {

}
	
vector<GameRepresentation::ModelType> Wall::getModels() const {
	return {GameRepresentation::ModelType::WALL};
}
	
bool Wall::isPacmanWalkable(const BoardSquare::PacmanContext &) const {
	return false;
}
	
void Wall::receivePacman(BoardSquare::PacmanContext &) {

}

bool Wall::isGhostWalkable(const BoardSquare::GhostContext &) const {
	return false;
}
	
void Wall::receiveGhost(BoardSquare::GhostContext &) {
	
}

BoardSquare * Wall::clone() {
	return new Wall(*this);
}
