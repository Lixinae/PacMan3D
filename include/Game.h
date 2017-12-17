#ifndef __GAME_H__
#define __GAME_H__

#include <Board.h>
#include <Pacman.h>
#include <PointOfView.h>
#include <GameRepresentation.h>
#include <json/json.hpp>
#include <string>

using json = nlohmann::json;

using namespace std;

class Game {

public:

    static Game fromJSON(const json &jsonGame);

    static Game fromJSONFile(const string &filePath);

    PointOfView *getPointOfView();

    void orientPacman(Utils::Orientation orientation);

    const GameRepresentation &getRepresentation() const;

    void iterate();

private:

    Board _board;
    Pacman _pacman;
    PointOfView _pointOfView;

    GameRepresentation _representation;

    Game(const Board &board, const Pacman &pacman);

    void setSquare(const BoardPosition &position);

    void setPacman();

    void cleanSquare(const BoardPosition &position);

    void cleanPacman();

};

#endif
