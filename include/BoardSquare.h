#ifndef __BOARD_SQUARE_H__
#define __BOARD_SQUARE_H__

#include <Pacman.h>
#include <Ghost.h>
#include <GameInformations.h>
#include <GameRepresentation.h>
#include <vector>
#include <json/json.hpp>

using json = nlohmann::json;

class BoardSquare {

public:

	struct PacmanContext {

		Pacman &pacman;
		vector<Ghost *> &ghosts;
		GameInformations &informations;

		PacmanContext(Pacman &pacman, vector<Ghost *> &ghosts, GameInformations &informations);

	};

	struct GhostContext {

		Ghost &ghost;

		GhostContext(Ghost &ghost);

	};

	static BoardSquare *fromJSON(const json &jsonSquare);

	virtual vector<GameRepresentation::Model> getModels() const = 0;

	virtual bool isPacmanWalkable(const PacmanContext &context) const = 0;

	virtual void receivePacman(PacmanContext &context) = 0;

	virtual bool isGhostWalkable(const GhostContext &context) const = 0;

	virtual void receiveGhost(GhostContext &context) = 0;

	virtual BoardSquare *clone() = 0;

	virtual ~BoardSquare() {

	};

};

#endif
