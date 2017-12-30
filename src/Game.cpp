#include <Game.h>

#include <fstream>

using json = nlohmann::json;

using namespace std;

Game::Game(const Board &board, const Board &board_init, const Pacman &pacman, const Pacman &pacman_init, const vector<Ghost *> &ghosts, const GameInformations &informations) :
		_board(board),
		_board_init(board_init),
		_pacman(pacman),
		_pacman_init(pacman_init),
		_ghosts(ghosts.size()),
		_ghosts_init(ghosts.size()),
		_pointOfView(pacman.getPosition(), pacman.getOrientation()),
		_informations(informations) 
{
	for (unsigned int i = 0; i < ghosts.size(); i++) {
		_ghosts[i] = ghosts[i]->clone();
		_ghosts_init[i] = ghosts[i]->clone();
	}
	updateFirstPersonCameraPosition();
}

Game::Game(const Board &board, const Pacman &pacman, const vector<Ghost *> &ghosts, const GameInformations &informations) :
	Game::Game(board, board, pacman, pacman, ghosts, informations)
{
	
}

Game::Game(const Game & other) :
	Game::Game(
		other._board, 
		other._board_init,
		other._pacman,
		other._pacman_init,
		other._ghosts,
		other._informations
	)
{
	
}

Game::~Game() {
	Utils::cleanVector(_ghosts);
	Utils::cleanVector(_ghosts_init);
}

Game &Game::operator=(const Game &other) {
	if (&other != this) {
		Game tmp(other);
		std::swap(_board, tmp._board);
		std::swap(_board_init, tmp._board_init);
		std::swap(_pacman, tmp._pacman);
		std::swap(_pacman_init, tmp._pacman_init);
		std::swap(_ghosts, tmp._ghosts);
		std::swap(_ghosts_init, tmp._ghosts_init);
		std::swap(_pointOfView, tmp._pointOfView);
		std::swap(_informations, tmp._informations);
	}
	return *this;
}

Game Game::fromJSON(const json &jsonGame) {
	Board board = Board::fromJSON(jsonGame["board"]);
	Pacman pacman = Pacman::fromJSON(jsonGame["pacman"]);
	GameInformations informations = GameInformations::fromJSON(jsonGame["informations"]);
	vector<Ghost *> ghosts;
	for (const auto &it : jsonGame["ghosts"]) {
		ghosts.push_back(Ghost::fromJSON(it));
	}
	json jsonInit = jsonGame["init"];
	if (jsonInit == nullptr) {
		Game game(board, pacman, ghosts, informations);
		Utils::cleanVector(ghosts);
		return game;
	}
	Board board_init = Board::fromJSON(jsonInit["board"]);
	Pacman pacman_init = Pacman::fromJSON(jsonInit["pacman"]);
	Game game(board, board_init, pacman, pacman_init, ghosts, informations);
	Utils::cleanVector(ghosts);
	return game;
}

json Game::toJSON() const {
	json jsonGame;
	jsonGame["board"] = _board.toJSON();
	jsonGame["pacman"] = _pacman.toJSON();
	jsonGame["informations"] = _informations.toJSON();
	json jsonGhosts;
	for (const Ghost * ghost : _ghosts) {
		jsonGhosts.push_back(ghost->toJSON());
	}
	jsonGame["ghosts"] = jsonGhosts;
	jsonGame["init"]["board"] = _board_init.toJSON();
	jsonGame["init"]["pacman"] = _pacman_init.toJSON();
	return jsonGame;
}

Game Game::fromJSONFile(const string &filePath) {
	json jsonGame;
	ifstream gameFile(filePath);
	gameFile >> jsonGame;
	gameFile.close();
	return fromJSON(jsonGame);
}

void Game::toJSONFile(const string &filePath) const {
	ofstream gameFile(filePath);
	gameFile << toJSON().dump(4);
	gameFile.close();
}

void Game::updateFirstPersonCameraPosition() {
	glm::vec3 cameraPos = 
		_pacman.getPosition().inSpace() + 
		_pacman.getShift()*Utils::vectorOfOrientation(_pacman.getOrientation()) + 
		glm::vec3(0, 1, 0);
	_pointOfView.getFirstPersonCamera().setPosition(cameraPos);
}

void Game::orientPacman(Utils::Orientation orientation) {
	Utils::Orientation realOrientation;
	if (_pointOfView.getCurrentCameraType() == PointOfView::CameraType::FIRST_PERSON) {
		realOrientation = Utils::relativeOrientation(_pacman.getOrientation(), orientation);
	} else {
		realOrientation = orientation;
	}
	BoardPosition position = _pacman.getPosition().translate(realOrientation);
	BoardSquare *square = _board[position];
	BoardSquare::PacmanContext context(_pacman, _ghosts, _informations);
	if (square != nullptr && square->isPacmanWalkable(context)) {
		if (_pacman.orientTo(realOrientation)) {
			_pointOfView.getFirstPersonCamera().setHorizontalAngle(Utils::degreesOfOrientation(realOrientation));
		}
	}
}

const PointOfView &Game::getPointOfView() const {
	return _pointOfView;
}

void Game::changeCamera() {
	_pointOfView.setNextCamera();
}

void Game::moveFrontCamera(float distance) {
	if (_pointOfView.getCurrentCameraType() == PointOfView::CameraType::UPPER_LEFT) {
		_pointOfView.getUpperLeftCamera().moveFront(distance);
	} else if (_pointOfView.getCurrentCameraType() == PointOfView::CameraType::UPPER) {
		_pointOfView.getUpperCamera().moveFront(distance);
	} else if (_pointOfView.getCurrentCameraType() == PointOfView::CameraType::UPPER_RIGHT) {
		_pointOfView.getUpperRightCamera().moveFront(distance);
	}
}

GameRepresentation Game::getRepresentation() const {
	GameRepresentation representation;
	if (_pointOfView.getCurrentCameraType() != PointOfView::CameraType::FIRST_PERSON) {
		representation.add(_pacman.getModel(), _pacman.getPosition());
	}
	for (const Ghost *ghost : _ghosts) {
		representation.add(ghost->getModel(), ghost->getPosition());
	}
	for (const BoardPosition &position : _board.getPositions()) {
		for (const GameRepresentation::Model &model : _board[position]->getModels()) {
			representation.add(model, position);
		}
	}
	return representation;
}

const GameInformations &Game::getInformations() const {
	return _informations;
}

void Game::iteratePacman() {
	BoardPosition nextPosition = _pacman.getPosition().translate(_pacman.getOrientation());
	BoardSquare *nextSquare = _board[nextPosition];
	BoardSquare::PacmanContext context(_pacman, _ghosts, _informations);
	if (nextSquare != nullptr && nextSquare->isPacmanWalkable(context)) {
		if(_pacman.goTo(nextPosition)){
			nextSquare->receivePacman(context);
		}
		updateFirstPersonCameraPosition();
	}
	_pacman.iterate();
}

void Game::iterateGhost(Ghost *ghost) {
	BoardPosition nextPosition = ghost->getPosition().translate(ghost->getOrientation());
	BoardSquare *nextSquare = _board[nextPosition];
	BoardSquare::GhostContext context(*ghost);
	Utils::Orientation orientation;
	if (nextSquare != nullptr && nextSquare->isGhostWalkable(context)) {
		if(ghost->goTo(nextPosition)) {
			nextSquare->receiveGhost(context);
		}
	}
	vector<Utils::Orientation> walkableOrientations;
	vector<Utils::Orientation> orientations = {
			Utils::Orientation::NORTH,
			Utils::Orientation::SOUTH,
			Utils::Orientation::EAST,
			Utils::Orientation::WEST
	};
	for (Utils::Orientation orientation : orientations) {
		BoardSquare *square = _board[ghost->getPosition().translate(orientation)];
		if (square != nullptr && square->isGhostWalkable(context)) {
			walkableOrientations.push_back(orientation);
		}
	}
	Ghost::MovingContext movingContext(walkableOrientations);
	ghost->orientTo(ghost->getNextOrientation(movingContext));
	ghost->iterate();
}

Game::State Game::iterate() {
	iteratePacman();
	for (unsigned int i = 0; i < _ghosts.size(); i++) {
		if (_pacman.getPosition() == _ghosts[i]->getPosition()) {
			if (_ghosts[i]->isWeak()) {
				_informations.increaseMultiplier();
				_informations.updateMultipliedScore(100);
				delete _ghosts[i];
				_ghosts[i] = _ghosts_init[i]->clone();
			} else {
				_informations.decreaseLife();
				if (_informations.isDead()) {
					return Game::State::LOOSE;
				} else {
					return Game::State::RESTART;
				}
			}
		}
		iterateGhost(_ghosts[i]);
	}
	_informations.iterate();
	for (const BoardPosition &position : _board.getPositions()) {
		if (!_board[position]->isDone()) {
			return Game::State::CONTINUE;
		}
	}
	return Game::State::WIN;
}

void Game::reset() {
	Utils::cleanVector(_ghosts);
	for (unsigned int i = 0; i < _ghosts.size(); i++) {
		_ghosts[i] = _ghosts_init[i]->clone();
	}
	_pacman = _pacman_init;
	_pointOfView = PointOfView(_pacman.getPosition(), _pacman.getOrientation());
	updateFirstPersonCameraPosition();
}

void Game::restart() {
	reset();
	_board = _board_init;
	_informations.resetAll();
}

void Game::restartKeepingScore() {
	reset();
	_board = _board_init;
}

void Game::setNextLevel() {
	_informations.increaseLevel();
	restartKeepingScore();
}


