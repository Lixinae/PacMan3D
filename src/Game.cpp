#include <Game.h>

#include <fstream>
#include <Utils.h>

using json = nlohmann::json;

using namespace std;

Game::Game(const Board & board, const Pacman & pacman, const vector<Ghost *> & ghosts) :
        _board(board),
        _pacman(pacman),
        _pacman_init(pacman),
        _ghosts(ghosts.size()),
        _ghosts_init(ghosts.size()),
        _pointOfView(pacman.getPosition(), pacman.getOrientation()),
        _informations()
{
	for (unsigned int i = 0; i < ghosts.size(); i++) {
		_ghosts[i] = ghosts[i]->clone();
		_ghosts_init[i] = ghosts[i]->clone();
	}
}

Game::~Game() {
	Utils::cleanVector(_ghosts);
	Utils::cleanVector(_ghosts_init);
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
	//TODO not orientation but
	// but relative orientation of current pacman orientation
	Utils::Orientation realOrientation;
	if (_pointOfView.getCurrentCameraType() == PointOfView::CameraType::TRACKBALL) {
		realOrientation = orientation;
	} else {
		realOrientation = Utils::relativeOrientation(_pacman.getOrientation(), orientation);
	}
    BoardPosition position = _pacman.getPosition().translate(realOrientation);
    BoardSquare *square = _board[position];
    BoardSquare::PacmanContext context(_pacman, _ghosts, _informations);
    if (square != nullptr && square->isPacmanWalkable(context)) {
        _pacman.setOrientation(realOrientation);
        _pointOfView.getFreeflyCamera().setHorizontalAngle(Utils::degreesOfOrientation(realOrientation));
    }
}

const PointOfView & Game::getPointOfView() const {
    return _pointOfView;
}

void Game::changeCamera() {
	_pointOfView.setNextCamera();
}

void Game::moveFrontCamera(float distance) {
	if (_pointOfView.getCurrentCameraType() == PointOfView::CameraType::TRACKBALL) {
		_pointOfView.getTrackballCamera().moveFront(distance);
	}
}

GameRepresentation Game::getRepresentation() const {
    GameRepresentation representation;
    if (_pointOfView.getCurrentCameraType() != PointOfView::CameraType::FREEFLY) {
		representation.add(_pacman.getModel(), _pacman.getPosition());
	}
	for (const Ghost * ghost : _ghosts) {
		representation.add(ghost->getModel(), ghost->getPosition());
	}
    for (const BoardPosition & position : _board.getPositions()) {
        for (const GameRepresentation::Model & model : _board[position]->getModels()) {
            representation.add(model, position);
        }
    }
    return representation;
}

const GameInformations & Game::getInformations() const {
	return _informations;
}

void Game::iteratePacman() {
	BoardPosition nextPosition = _pacman.getPosition().translate(_pacman.getOrientation());
    BoardSquare *nextSquare = _board[nextPosition];
    BoardSquare::PacmanContext context(_pacman, _ghosts, _informations);
    if (nextSquare != nullptr && nextSquare->isPacmanWalkable(context)) {
        _pacman.setPosition(nextPosition);
        nextSquare->receivePacman(context);
        glm::vec3 cameraPos = _pacman.getPosition().inSpace() + glm::vec3(0, 1.5, 0);
		_pointOfView.getFreeflyCamera().setPosition(cameraPos);
    }
    _pacman.iterate();
}

void Game::iterateGhost(Ghost * ghost) {
	BoardPosition nextPosition = ghost->getPosition().translate(ghost->getOrientation());
    BoardSquare *nextSquare = _board[nextPosition];
    BoardSquare::GhostContext context(*ghost);
	if (nextSquare != nullptr && nextSquare->isGhostWalkable(context)) {
        ghost->setPosition(nextPosition);
        nextSquare->receiveGhost(context);
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
    for (unsigned int i = 0; i < _ghosts.size(); i++) {
		iterateGhost(_ghosts[i]); //TODO maybe after pos check
		if (_pacman.getPosition() == _ghosts[i]->getPosition()) {
			if (_ghosts[i]->isWeak()) {
				delete _ghosts[i];
				_ghosts[i] = _ghosts_init[i]->clone();
			} else {
				//_pacman = _pacman_init;
				// update camera pos and angle
				_informations.decreaseLife();
				if (_informations.isDead()) {
					return false;
				}
			}
		}
	}
	return true;
}
