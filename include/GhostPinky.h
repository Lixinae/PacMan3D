#ifndef __GHOST_PINKY_H__
#define __GHOST_PINKY_H__

#include <Ghost.h>

class GhostPinky : public Ghost {

using Ghost::Ghost;

public:

	Utils::Orientation getNextOrientation() const;
	
	GameRepresentation::Model getModel() const;
	
	Ghost * clone() const;

};

#endif
