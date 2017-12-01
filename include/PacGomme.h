#ifndef __PAC_GOMME_H__
#define __PAC_GOMME_H__

#include <Pacman.h>
#include <Bonus.h>
#include <BoardRepresentation.h>

class PacGomme : public Bonus {

public:
	
	PacGomme();
	
	BoardRepresentation::Model getModel() const;
	
	void apply(Pacman pacman);

};

#endif
