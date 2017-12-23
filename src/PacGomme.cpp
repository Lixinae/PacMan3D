#include <PacGomme.h>


PacGomme::PacGomme() {

}

GameRepresentation::Model PacGomme::getModel() const {
    return GameRepresentation::Model(GameRepresentation::ModelType::PAC_GOMME);
}

void PacGomme::apply(Pacman & /*pacman*/) {
	//TODO update score
}

Bonus *PacGomme::clone() const {
    return new PacGomme(*this);
}
