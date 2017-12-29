#include <Board.h>

#include <Utils.h>

using namespace std;

Board::Board(const map<BoardPosition, BoardSquare *> &squares) : _squares() {
	for (const auto &entry : squares) {
		_squares[entry.first] = entry.second->clone(); //TODO CHECK IMPLEMENTATIONS FOR DESTRUCTOR
	}
}

Board::Board(const Board &other) : Board::Board(other._squares) {

}

Board::~Board() {
	//Utils::cleanMap(_squares);//TODO correct bug
}

Board Board::fromJSON(const json &jsonBoard) {
	map<BoardPosition, BoardSquare *> squares;
	json casesArray = jsonBoard["cases"];
	for (const auto &it : casesArray) {
		BoardPosition position = BoardPosition::fromJSON(it["position"]);
		BoardSquare *square = BoardSquare::fromJSON(it["case"]);
		squares[position] = square;
	}
	Board board(squares);
	Utils::cleanMap(squares);
	return board;
}

json Board::toJSON() const {
	json jsonBoard;
	json jsonSquares;
	for (const auto &entry : _squares) {
		json jsonSquare;
		jsonSquare["position"] = entry.first.toJSON();
		jsonSquare["case"] = entry.second->toJSON(); 
		jsonSquares.push_back(jsonSquare);
	}
	jsonBoard["cases"] = jsonSquares;
	return jsonBoard;
}

vector<BoardPosition> Board::getPositions() const {
	vector<BoardPosition> positions;
	for (const auto &pair : _squares) {
		positions.push_back(pair.first);
	}
	return positions;
}

BoardSquare *Board::getSquare(const BoardPosition &position) const {
	auto it = _squares.find(position);
	if (it == _squares.end()) {
		return nullptr;
	}
	return it->second;
}

BoardSquare *Board::operator[](const BoardPosition &position) const {
	return getSquare(position);
}
