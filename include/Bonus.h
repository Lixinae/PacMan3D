#ifndef __BONUS_H__
#define __BONUS_H__

#include <Pacman.h>
#include <GameRepresentation.h>
#include <json/json.hpp>

using json = nlohmann::json;

class Bonus {

public: 

	struct Context {
		
		Context();
		
	};

	static Bonus * fromJSON(const json & jsonBonus);

	virtual GameRepresentation::Model getModel() const = 0;

	virtual void apply(Context & context) = 0;
	
	virtual Bonus * clone() const = 0;
	
	virtual ~Bonus() {
		
	};

};

#endif
