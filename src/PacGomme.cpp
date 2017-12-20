#include <PacGomme.h>


PacGomme::PacGomme() {

}

GameRepresentation::ModelType PacGomme::getModel() const {
    return GameRepresentation::ModelType::PAC_GOMME;
}

void PacGomme::apply(Pacman & /*pacman*/) {
	//TODO update score
}

Bonus *PacGomme::clone() const {
    return new PacGomme;
}
