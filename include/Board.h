#ifndef __BOARD_H__
#define __BOARD_H__

#include <BoardPosition.h>
#include <BoardSquare.h>
#include <GameRepresentation.h>
#include <map>
#include <vector>

using namespace std;

class Board {

public:

	Board(); // TODO should be private, the factory from file must be public

	vector<BoardPosition> getPositions() const;

	const BoardSquare & getSquare(const BoardPosition & position) const;
	const BoardSquare & operator[](const BoardPosition & position) const;
			
private:
 
	map<BoardPosition, BoardSquare *> _squares;

};

#endif
