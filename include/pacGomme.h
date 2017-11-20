#ifndef __PAC_GOMME_H__
#define __PAC_GOMME_H__

#include "pacman.h"
#include "bonus.h"

class PacGomme : public Bonus {

public:
	
	PacGomme();
	
	void apply(Pacman pacman);

};

#endif
