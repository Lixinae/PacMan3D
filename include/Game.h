#ifndef __GAME_H__
#define __GAME_H__

#include <Board.h>
#include <Pacman.h>
#include <Ghost.h>
#include <PointOfView.h>
#include <GameInformations.h>
#include <GameRepresentation.h>
#include <json/json.hpp>
#include <string>
#include <vector>

using json = nlohmann::json;

using namespace std;

class Game {

public:

	enum class State {
		CONTINUE,
		WIN,
		LOOSE,
		RESTART
	};

	static Game fromJSON(const json &jsonGame);

	static Game fromJSONFile(const string &filePath);

	Game(const Game & other);

	~Game();

	const PointOfView &getPointOfView() const;

	void changeCamera();

	void moveFrontCamera(float distance);

	void orientPacman(Utils::Orientation orientation);

	GameRepresentation getRepresentation() const;

	const GameInformations &getInformations() const;

	State iterate();

	void reset();
	
	void restart();

	void restartKeepingScore();

	void setNextLevel();
	
	json toJSON() const;
	
	void toJSONFile(const string &filePath) const;
	
	Game & operator=(const Game &other);

private:

	Board _board;
	Pacman _pacman;
	vector<Ghost *> _ghosts;

	Board _board_init;
	Pacman _pacman_init;
	vector<Ghost *> _ghosts_init;

	PointOfView _pointOfView;

	GameInformations _informations;

	Game(const Board &board, const Pacman &pacman, const vector<Ghost *> &ghosts, const GameInformations &informations);

	void updateFirstPersonCameraPosition();

	void iteratePacman();

	void iterateGhost(Ghost *ghost);

};

#endif
