#include <Board.h>

using namespace std;

Board::Board(const map<BoardPosition, BoardSquare *> & squares) : _squares(squares) {

}

Board::Board(const Board & other) : _squares() {
	for (const auto & entry : other._squares) {
		_squares[entry.first] = entry.second->clone();
	}
}

Board::~Board() {
	for (auto & entry : _squares) {
		delete entry.second;
	}
}

Board Board::fromJSON(const json & jsonBoard) {
	map<BoardPosition, BoardSquare *> squares;
	json casesArray = jsonBoard["cases"];
    for (const auto &it : casesArray) {
        BoardPosition position = BoardPosition::fromJSON(it["position"]);
        BoardSquare *square = BoardSquare::fromJSON(it["case"]);
		squares[position] = square;
	}
	return Board(squares);
}

vector<BoardPosition> Board::getPositions() const {
	vector<BoardPosition> positions;
	for(const auto & pair : _squares) {
		positions.push_back(pair.first);
	}
	return positions;
}

BoardSquare * Board::getSquare(const BoardPosition & position) const {
	auto it = _squares.find(position);
	if (it == _squares.end()) {
		return nullptr;
	}
	return it->second;
}

BoardSquare * Board::operator[](const BoardPosition & position) const {
	return getSquare(position);
}
