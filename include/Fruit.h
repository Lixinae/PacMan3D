#ifndef __FRUIT_H__
#define __FRUIT_H__

#include <Pacman.h>
#include <Bonus.h>
#include <GameRepresentation.h>

class Fruit : public Bonus {

public:

	Fruit();

	GameRepresentation::Model getModel() const override;

	void apply(Bonus::Context &context) override;

	bool isRequired() const override;

	Bonus *clone() const override;

	json toJSON() const override;

};

#endif
