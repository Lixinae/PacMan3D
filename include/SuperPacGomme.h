#ifndef __SUPER_PAC_GOMME_H__
#define __SUPER_PAC_GOMME_H__

#include <Pacman.h>
#include <Bonus.h>
#include <GameRepresentation.h>

class SuperPacGomme : public Bonus {

public:

	SuperPacGomme();

	GameRepresentation::Model getModel() const;

	void apply(Bonus::Context &context);

	bool isRequired() const;
	
	Bonus *clone() const;
	
	json toJSON() const;

};

#endif
