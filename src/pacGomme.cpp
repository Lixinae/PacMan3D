#include "pacGomme.h"

#include "pacman.h"
#include "bonus.h"
#include "renderer.h"

PacGomme::PacGomme() {

}

Renderer::Model PacGomme::getModel() const {
	return Renderer::Model::PAC_GOMME;
}

void PacGomme::apply(Pacman /*pacman*/) {
	//TODO update score
}
