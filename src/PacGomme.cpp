#include <PacGomme.h>


PacGomme::PacGomme() {

}

GameRepresentation::Model PacGomme::getModel() const {
	return GameRepresentation::Model(GameRepresentation::ModelType::PAC_GOMME);
}

void PacGomme::apply(Bonus::Context &context) {
	context.informations.updateScore(10);
}

Bonus *PacGomme::clone() const {
	return new PacGomme(*this);
}
