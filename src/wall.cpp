#include "wall.h"

#include "pacman.h"
#include "boardSquare.h"

Wall::Wall() {

}
	
bool Wall::isWalkable() const {
	return false;
}
	
void Wall::receive(Pacman) {
	// Do nothing : should never be call
}
