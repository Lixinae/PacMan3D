#include <Game.h>

#include <fstream>
#include <Utils.h>

using json = nlohmann::json;

using namespace std;

Game::Game(const Board & board, const Pacman & pacman, const vector<Ghost *> & ghosts) :
        _board(board),
        _pacman(pacman),
        _ghosts(),
        _pointOfView(),
        _informations(),
        _representation()
{
	_representation.add(pacman.getModel(), pacman.getPosition());
	for (const Ghost * ghost : ghosts) {
		_ghosts.push_back(ghost->clone());
		_representation.add(ghost->getModel(), ghost->getPosition());
	}
    for (const BoardPosition & position : _board.getPositions()) {
        for (const GameRepresentation::Model & model : _board[position]->getModels()) {
            _representation.add(model, position);
        }
    }
}

Game::~Game() {
	Utils::cleanVector(_ghosts);
}

Game Game::fromJSON(const json &jsonGame) {
    Board board = Board::fromJSON(jsonGame["board"]);
    Pacman pacman = Pacman::fromJSON(jsonGame["pacman"]);
    vector<Ghost *> ghosts;
    for (const auto &it : jsonGame["ghosts"]) {
        ghosts.push_back(Ghost::fromJSON(it));
	}
    Game game(board, pacman, ghosts);
    Utils::cleanVector(ghosts);
    return game;
}

Game Game::fromJSONFile(const string &filePath) {
    json jsonGame;
    ifstream gameFile(filePath);
    gameFile >> jsonGame;
    gameFile.close();
    return fromJSON(jsonGame);
}

void Game::orientPacman(Utils::Orientation orientation) {
    BoardPosition position = _pacman.getPosition().translate(orientation);
    BoardSquare *square = _board[position];
    BoardSquare::PacmanContext context(_pacman, _ghosts, _informations);
    if (square != nullptr && square->isPacmanWalkable(context)) {
        _pacman.setOrientation(orientation);
    }
}

PointOfView *Game::getPointOfView() {
    return &_pointOfView;
}

const GameRepresentation &Game::getRepresentation() const {
	// TODO may change :
	// time to compute all the gamerepresentation is unsignificant compare to the time to make all the render
    return _representation;
}

void Game::setSquare(const BoardPosition &position) {
    for (const GameRepresentation::Model & model : _board[position]->getModels()) {
        _representation.add(model, position);
    }
}

void Game::setPacman() {
    _representation.add(_pacman.getModel(), _pacman.getPosition());
}

void Game::setGhost(const Ghost * ghost) {
	 _representation.add(ghost->getModel(), ghost->getPosition());
}

void Game::cleanSquare(const BoardPosition &position) {
    for (const GameRepresentation::Model & model : _board[position]->getModels()) {
        _representation.remove(model, position);
    }
}

void Game::cleanPacman() {
    _representation.remove(_pacman.getModel(), _pacman.getPosition());
}

void Game::cleanGhost(const Ghost * ghost) {
	// TODO should change !!!!
	_representation.remove(GameRepresentation::ModelType::GHOST_BLINKY, ghost->getPosition());
	_representation.remove(GameRepresentation::ModelType::GHOST_PINKY, ghost->getPosition());
	_representation.remove(GameRepresentation::ModelType::GHOST_INKY, ghost->getPosition());
	_representation.remove(GameRepresentation::ModelType::GHOST_CLYDE, ghost->getPosition());
	_representation.remove(GameRepresentation::ModelType::GHOST_WEAK, ghost->getPosition());
	//_representation.remove(ghost->getModel(), ghost->getPosition());
}

void Game::iteratePacman() {
	BoardPosition nextPosition = _pacman.getPosition().translate(_pacman.getOrientation());
    BoardSquare *nextSquare = _board[nextPosition];
    BoardSquare::PacmanContext context(_pacman, _ghosts, _informations);
    if (nextSquare != nullptr && nextSquare->isPacmanWalkable(context)) {
        // Clean models
        cleanSquare(nextPosition);
        cleanPacman();
        // Update
        _pacman.setPosition(nextPosition);
        nextSquare->receivePacman(context);
        // Reset models
        setSquare(nextPosition);
        setPacman();
    }
    _pacman.iterate();
}

void Game::iterateGhost(Ghost * ghost) {
	BoardPosition nextPosition = ghost->getPosition().translate(ghost->getOrientation());
    BoardSquare *nextSquare = _board[nextPosition];
    BoardSquare::GhostContext context(*ghost);
	if (nextSquare != nullptr && nextSquare->isGhostWalkable(context)) {
		cleanSquare(nextPosition);
		cleanGhost(ghost);
        ghost->setPosition(nextPosition);
        nextSquare->receiveGhost(context);
        cleanGhost(ghost);
        setSquare(nextPosition);
		setGhost(ghost);
	} else {
		// get all the direction and choose one of the possible
		vector<Utils::Orientation> walkableOrientations;
		vector<Utils::Orientation> orientations = {
			Utils::Orientation::NORTH,
			Utils::Orientation::SOUTH,
			Utils::Orientation::EAST,
			Utils::Orientation::WEST,
			//One more chance to go to the opposite of the unwalkable square
			Utils::oppositeOrientation(ghost->getOrientation()) 
		};
		for (Utils::Orientation orientation : orientations) {
			BoardSquare *square = _board[ghost->getPosition().translate(orientation)];
			if (square != nullptr && square->isGhostWalkable(context)) {
				walkableOrientations.push_back(orientation);
			}
		}
		ghost->setOrientation(Utils::randomOrientation(walkableOrientations));
	}
	ghost->iterate();
}

bool Game::iterate() {
    iteratePacman();
    for (Ghost * ghost : _ghosts) {
		iterateGhost(ghost);
		if (_pacman.getPosition() == ghost->getPosition()) {
			if (ghost->isWeak()) {
				// TODO Implement eat
			} else {
				return false;
			}
		}
	}
	return true;
}
