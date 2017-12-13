#include <Bonus.h>

#include <PacGomme.h>

using json = nlohmann::json;

Bonus * Bonus::fromJSON(const json & jsonBonus) {
	string type = jsonBonus["type"];
	if (type == "pacgomme") {
		return new PacGomme;
	}
	throw invalid_argument(type + " is not a valid string representation of bonus type");
}
