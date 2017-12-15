#include <PacGomme.h>

#include <Pacman.h>
#include <Bonus.h>
#include <GameRepresentation.h>

PacGomme::PacGomme() {

}

GameRepresentation::Model PacGomme::getModel() const {
	return GameRepresentation::Model::PAC_GOMME;
}

void PacGomme::apply(Pacman /*pacman*/) {
	//TODO update score
}

Bonus * PacGomme::clone() const {
	return new PacGomme;
}
