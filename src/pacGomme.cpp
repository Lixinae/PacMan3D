#include "pacGomme.h"

#include "pacman.h"
#include "bonus.h"
#include "boardRepresentation.h"

PacGomme::PacGomme() {

}

BoardRepresentation::Model PacGomme::getModel() const {
	return BoardRepresentation::Model::PAC_GOMME;
}

void PacGomme::apply(Pacman /*pacman*/) {
	//TODO update score
}
