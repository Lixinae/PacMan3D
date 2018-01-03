#ifndef __FRUIT_H__
#define __FRUIT_H__

#include <Pacman.h>
#include <Bonus.h>
#include <GameRepresentation.h>

class Fruit : public Bonus {

public:

	Fruit();

	GameRepresentation::Model getModel() const;

	void apply(Bonus::Context &context);

	bool isRequired() const;

	Bonus *clone() const;

	json toJSON() const;

};

#endif
