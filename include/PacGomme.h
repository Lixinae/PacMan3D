#ifndef __PAC_GOMME_H__
#define __PAC_GOMME_H__

#include <Pacman.h>
#include <Bonus.h>
#include <GameRepresentation.h>

class PacGomme : public Bonus {

public:
	
	PacGomme();
	
	GameRepresentation::Model getModel() const;
	
	void apply(Pacman & pacman);
	
	Bonus * clone() const;

};

#endif
