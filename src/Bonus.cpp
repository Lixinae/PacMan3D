#include <Bonus.h>

#include <PacGomme.h>
#include <SuperPacGomme.h>

using json = nlohmann::json;

Bonus::Context::Context(vector<Ghost *> & ghosts):
	ghosts(ghosts)
{
	
}

Bonus * Bonus::fromJSON(const json & jsonBonus) {
	string type = jsonBonus["type"];
	if (type == "pacgomme") {
		return new PacGomme;
	}
	if (type == "super_pacgomme") {
		return new SuperPacGomme;
	}
	throw invalid_argument(type + " is not a valid string representation of bonus type");
}
