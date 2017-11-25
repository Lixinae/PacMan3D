#ifndef __BONUS_H__
#define __BONUS_H__

#include "renderer.h"

class Bonus {

public: 

	virtual Renderer::Model getModel() const = 0; //TODO should be option model

	virtual void apply(Pacman pacman) = 0;
	
	virtual ~Bonus() {
		
	};

};

#endif
