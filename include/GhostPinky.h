#ifndef __GHOST_PINKY_H__
#define __GHOST_PINKY_H__

#include <Ghost.h>

class GhostPinky : public Ghost {

	using Ghost::Ghost;

public:

	Utils::Orientation getNextOrientation(const MovingContext &context) const override;

	GameRepresentation::ModelType getModelType() const override;

	Ghost *clone() const override;

	json toJSON() const override;
	
};

#endif
