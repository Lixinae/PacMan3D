#include <SuperPacGomme.h>

SuperPacGomme::SuperPacGomme() = default;

GameRepresentation::Model SuperPacGomme::getModel() const {
	return GameRepresentation::Model(GameRepresentation::ModelType::SUPER_PAC_GOMME);
}

void SuperPacGomme::apply(Context &context) {
	// TODO static const for time
	int time = 150;
	for (Ghost *ghost : context.ghosts) {
		ghost->setWeak(time);
	}
	context.informations.setMultiplierCounter(time);
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
