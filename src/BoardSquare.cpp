#include <BoardSquare.h>

#include <Wall.h>
#include <Floor.h>
#include <Tunnel.h>
#include <Bonus.h>

using json = nlohmann::json;

BoardSquare * BoardSquare::fromJSON(const json & jsonSquare) {
	string type = jsonSquare["type"];
	if (type == "wall") {
		return new Wall;
	}
	if (type == "floor") {
		// TODO manage if no bonus in square
		Bonus * bonus = Bonus::fromJSON(jsonSquare["args"]["bonus"]); 
		BoardSquare * square = new Floor(bonus);
		delete bonus;
		return square;
	}
	if (type == "tunnel") {
		Utils::Orientation orientation = Utils::orientationFromString(jsonSquare["args"]["orientation"]); 
		BoardPosition dest = BoardPosition::fromJSON(jsonSquare["args"]["dest"]);
		Utils::Orientation destOrientation = Utils::orientationFromString(jsonSquare["args"]["destOrientation"]); 
		return new Tunnel(orientation, dest, destOrientation);
	}
	throw invalid_argument(type + " is not a valid string representation of case type");
}
