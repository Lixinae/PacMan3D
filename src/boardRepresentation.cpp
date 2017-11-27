#include "boardRepresentation.h"

#include "boardPosition.h"
#include "renderer.h"
#include <map>
#include <vector>

using namespace std;

// TODO impl

BoardRepresentation::BoardRepresentation() { // TODO
	
}
	
vector<BoardPosition> BoardRepresentation::getPositions(Renderer::Model /*model*/) const {
	return vector<BoardPosition>();
}

void BoardRepresentation::add(Renderer::Model /*model*/, const BoardPosition & /*position*/) {
	
}
	
void BoardRepresentation::remove(Renderer::Model /*model*/, const BoardPosition & /*position*/) {
	
}
	
vector<BoardPosition> BoardRepresentation::operator[](Renderer::Model model) const {
	return getPositions(model);
}
