#ifndef __GHOST_INKY_H__
#define __GHOST_INKY_H__

#include <Ghost.h>

class GhostInky : public Ghost {

using Ghost::Ghost;

public:

	Utils::Orientation getNextOrientation() const;

	GameRepresentation::Model getModel() const;
	
	Ghost * clone() const;

};

#endif
