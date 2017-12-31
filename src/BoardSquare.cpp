#include <BoardSquare.h>

#include <Wall.h>
#include <Floor.h>
#include <Tunnel.h>
#include <Door.h>
#include <Utils.h>

using json = nlohmann::json;

BoardSquare::PacmanContext::PacmanContext(Pacman &pacman, vector<Ghost *> &ghosts, GameInformations &informations) :
		pacman(pacman),
		ghosts(ghosts),
		informations(informations) {
}

BoardSquare::GhostContext::GhostContext(Ghost &ghost) :
		ghost(ghost) {

}

BoardPosition BoardSquare::neighbour(const BoardPosition & position, Utils::Orientation orientation) {
	return position.translate(orientation);
}

BoardSquare *BoardSquare::fromJSON(const json &jsonSquare) {
	string type = jsonSquare["type"];
	if (type == "wall") {
		return new Wall;
	}
	if (type == "floor") {
		json jsonBonus = jsonSquare["args"]["bonus"];
		if (jsonBonus == nullptr) {
			return new Floor;
		}
		Bonus *bonus = Bonus::fromJSON(jsonBonus);
		BoardSquare *square = new Floor(bonus);
		delete bonus;
		return square;
	}
	if (type == "tunnel") {
		Utils::Orientation orientation = Utils::orientationFromString(jsonSquare["args"]["orientation"]);
		BoardPosition dest = BoardPosition::fromJSON(jsonSquare["args"]["dest"]);
		Utils::Orientation destOrientation = Utils::orientationFromString(jsonSquare["args"]["destOrientation"]);
		return new Tunnel(orientation, dest, destOrientation);
	}
	if (type == "door") {
		return new Door;
	}
	throw invalid_argument(type + " is not a valid string representation of case type");
}
