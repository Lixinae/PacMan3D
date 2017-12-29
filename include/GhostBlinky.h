#ifndef __GHOST_BLINKY_H__
#define __GHOST_BLINKY_H__

#include <Ghost.h>

class GhostBlinky : public Ghost {

	using Ghost::Ghost;

public:

	Utils::Orientation getNextOrientation(const MovingContext & context) const;

	GameRepresentation::ModelType getModelType() const;

	Ghost *clone() const;
	
	json toJSON() const;

};

#endif
