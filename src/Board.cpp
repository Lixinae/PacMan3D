#include <Board.h>

#include <BoardPosition.h>
#include <BoardSquare.h>
#include <GameRepresentation.h>
#include <map>
#include <vector>

using namespace std;

Board::Board(const map<BoardPosition, BoardSquare *> & squares) : _squares(squares) {
	
}

Board::~Board() {
	// TODO manage delete for new boardsquare::fromjson
}

Board Board::fromJSON(json jsonBoard) {
	map<BoardPosition, BoardSquare *> squares;
	json casesArray = jsonBoard["cases"];
	for (json::iterator it = casesArray.begin(); it != casesArray.end(); ++it) {
		BoardPosition position = BoardPosition::fromJSON((*it)["position"]);
		BoardSquare * square = BoardSquare::fromJSON((*it)["case"]); //TODO Manage delete
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

const BoardSquare & Board::getSquare(const BoardPosition & position) const {
	//TODO Option Square <=> Square *
	return *(_squares.at(position));
}

const BoardSquare & Board::operator[](const BoardPosition & position) const {
	return getSquare(position);
}
