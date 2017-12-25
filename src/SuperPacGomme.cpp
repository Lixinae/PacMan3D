#include <SuperPacGomme.h>

SuperPacGomme::SuperPacGomme() {

}

GameRepresentation::Model SuperPacGomme::getModel() const {
    return GameRepresentation::Model(GameRepresentation::ModelType::SUPER_PAC_GOMME);
}

void SuperPacGomme::apply(Context & context) {
	// TODO static const for time
	int time = 100;
	for (Ghost * ghost : context.ghosts) {
		ghost->setWeak(time);
	}
	context.informations.setMultiplier(time);
}

Bonus *SuperPacGomme::clone() const {
    return new SuperPacGomme(*this);
}
