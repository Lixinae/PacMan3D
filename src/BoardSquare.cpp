#include <BoardSquare.h>

#include <Wall.h>
#include <Floor.h>
#include <json/json.hpp>

using json = nlohmann::json;

BoardSquare * BoardSquare::fromJSON(json jsonSquare) {
	string type = jsonSquare["type"];
	if (type == "wall") {
		return new Wall;
	}
	if (type == "floor") {
		//TODO use args for bonus in constructor
		return new Floor;
	}
	throw invalid_argument(type + " is not a valid string representation of case type");
}
