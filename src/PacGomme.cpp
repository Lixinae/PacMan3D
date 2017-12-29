#include <PacGomme.h>


PacGomme::PacGomme() {

}

GameRepresentation::Model PacGomme::getModel() const {
	return GameRepresentation::Model(GameRepresentation::ModelType::PAC_GOMME);
}

void PacGomme::apply(Bonus::Context &context) {
	context.informations.updateScore(10);
}

bool PacGomme::isRequired() const {
	return true;
}

Bonus *PacGomme::clone() const {
	return new PacGomme(*this);
}

json PacGomme::toJSON() const {
	json jsonBonus;
	jsonBonus["type"] = "pacgomme";
	return jsonBonus;
}
