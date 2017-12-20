#ifndef __BONUS_H__
#define __BONUS_H__

#include <Pacman.h>
#include <GameRepresentation.h>
#include <json/json.hpp>

using json = nlohmann::json;

class Bonus {

public: 

	static Bonus * fromJSON(const json & jsonBonus);

	virtual GameRepresentation::ModelType getModel() const = 0;

	virtual void apply(Pacman & pacman) = 0;
	
	virtual Bonus * clone() const = 0;
	
	virtual ~Bonus() {
		
	};

};

#endif
