#ifndef __GHOST_BLINKY_H__
#define __GHOST_BLINKY_H__

#include <Ghost.h>

class GhostBlinky : public Ghost {

	using Ghost::Ghost;

public:

	Utils::Orientation getNextOrientation(const MovingContext &context) const override;

	GameRepresentation::ModelType getModelType() const override;

	Ghost *clone() const override;

	json toJSON() const override;

};

#endif
