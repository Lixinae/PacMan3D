#include <PacGomme.h>

#include <Pacman.h>
#include <Bonus.h>
#include <BoardRepresentation.h>

PacGomme::PacGomme() {

}

BoardRepresentation::Model PacGomme::getModel() const {
	return BoardRepresentation::Model::PAC_GOMME;
}

void PacGomme::apply(Pacman /*pacman*/) {
	//TODO update score
}
