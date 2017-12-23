#include <SuperPacGomme.h>


SuperPacGomme::SuperPacGomme() {

}

GameRepresentation::Model SuperPacGomme::getModel() const {
    return GameRepresentation::Model(GameRepresentation::ModelType::SUPER_PAC_GOMME);
}

void SuperPacGomme::apply(Context & /*context*/) {
	//TODO weak ghost
}

Bonus *SuperPacGomme::clone() const {
    return new SuperPacGomme(*this);
}