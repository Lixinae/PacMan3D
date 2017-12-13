#include <BoardSquare.h>

#include <Wall.h>
#include <Floor.h>
#include <PacGomme.h>

using json = nlohmann::json;

BoardSquare * BoardSquare::fromJSON(const json & jsonSquare) {
	string type = jsonSquare["type"];
	if (type == "wall") {
		return new Wall;
	}
	if (type == "floor") {
		//TODO use args for bonus in constructor
		Bonus * bonus = new PacGomme; 
		return new Floor(bonus);
	}
	throw invalid_argument(type + " is not a valid string representation of case type");
}
