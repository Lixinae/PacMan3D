#ifndef __GHOST_CLYDE_H__
#define __GHOST_CLYDE_H__

#include <Ghost.h>

class GhostClyde : public Ghost {

using Ghost::Ghost;

public:

	Utils::Orientation getNextOrientation() const;

	GameRepresentation::Model getModel() const;

	Ghost * clone() const;

};

#endif
