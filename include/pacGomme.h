#ifndef __PAC_GOMME_H__
#define __PAC_GOMME_H__

#include "pacman.h"
#include "bonus.h"
#include "boardRepresentation.h"

class PacGomme : public Bonus {

public:
	
	PacGomme();
	
	BoardRepresentation::Model getModel() const;
	
	void apply(Pacman pacman);

};

#endif
