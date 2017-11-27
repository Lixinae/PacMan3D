#include "boardRepresentation.h"

#include "boardPosition.h"
#include <map>
#include <vector>

using namespace std;

// TODO impl

BoardRepresentation::BoardRepresentation() { // TODO
	
}
	
vector<BoardPosition> BoardRepresentation::getPositions(Model /*model*/) const {
	return vector<BoardPosition>();
}

void BoardRepresentation::add(Model /*model*/, const BoardPosition & /*position*/) {
	
}
	
void BoardRepresentation::remove(Model /*model*/, const BoardPosition & /*position*/) {
	
}
	
vector<BoardPosition> BoardRepresentation::operator[](Model model) const {
	return getPositions(model);
}
