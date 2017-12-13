#ifndef __BONUS_H__
#define __BONUS_H__

#include <GameRepresentation.h>

class Bonus {

public: 

	virtual GameRepresentation::Model getModel() const = 0; //TODO should be option model

	virtual void apply(Pacman pacman) = 0;
	
	virtual Bonus * clone() const = 0;
	
	virtual ~Bonus() {
		
	};

};

#endif
