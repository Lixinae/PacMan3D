#include <SuperPacGomme.h>

int SuperPacGomme::WEAK_ITERATION = 150;

SuperPacGomme::SuperPacGomme() = default;

GameRepresentation::Model SuperPacGomme::getModel() const {
	return GameRepresentation::Model(GameRepresentation::ModelType::SUPER_PAC_GOMME);
}

void SuperPacGomme::apply(Context &context) {
	for (Ghost *ghost : context.ghosts) {
		ghost->setWeak(WEAK_ITERATION);
	}
	context.informations.setMultiplierCounter(WEAK_ITERATION);
}

bool SuperPacGomme::isRequired() const {
	return false;
}

Bonus *SuperPacGomme::clone() const {
	return new SuperPacGomme(*this);
}

json SuperPacGomme::toJSON() const {
	json jsonBonus;
	jsonBonus["type"] = "super_pacgomme";
	return jsonBonus;
}
