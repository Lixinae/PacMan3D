#ifndef __BONUS_H__
#define __BONUS_H__

#include <Ghost.h>
#include <GameInformations.h>
#include <GameRepresentation.h>
#include <json/json.hpp>

using json = nlohmann::json;

class Bonus {

public:

	struct Context {

		vector<Ghost *> &ghosts;
		GameInformations &informations;

		Context(vector<Ghost *> &ghosts, GameInformations &informations);

	};

	static Bonus *fromJSON(const json &jsonBonus);

	virtual GameRepresentation::Model getModel() const = 0;

	virtual void apply(Context &context) = 0;

	virtual Bonus *clone() const = 0;

	virtual ~Bonus() {

	};

};

#endif
