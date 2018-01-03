#ifndef __SUPER_PAC_GOMME_H__
#define __SUPER_PAC_GOMME_H__

#include <Pacman.h>
#include <Bonus.h>
#include <GameRepresentation.h>

class SuperPacGomme : public Bonus {

public:

	SuperPacGomme();

	GameRepresentation::Model getModel() const override;

	void apply(Bonus::Context &context) override;

	bool isRequired() const override;

	Bonus *clone() const override;

	json toJSON() const override;

};

#endif
