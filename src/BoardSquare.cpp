#include <BoardSquare.h>

#include <Wall.h>
#include <Floor.h>
#include <Bonus.h>

using json = nlohmann::json;

BoardSquare * BoardSquare::fromJSON(const json & jsonSquare) {
	string type = jsonSquare["type"];
	if (type == "wall") {
		return new Wall;
	}
	if (type == "floor") {
		Bonus * bonus = Bonus::fromJSON(jsonSquare["args"]["bonus"]); 
		BoardSquare * square = new Floor(bonus);
		delete bonus;
		return square;
	}
	throw invalid_argument(type + " is not a valid string representation of case type");
}
