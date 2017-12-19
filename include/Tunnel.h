#ifndef __TUNNEL_H__
#define __TUNNEL_H__

#include <BoardSquare.h>
#include <Pacman.h>
#include <GameRepresentation.h>
#include <Utils.h>
#include <BoardPosition.h>

class Tunnel : public BoardSquare {

public:

	Tunnel(Utils::Orientation orientation, const BoardPosition & dest, Utils::Orientation destOrientation);
	
	vector<GameRepresentation::Model> getModels() const;
	
	bool isPacmanWalkable(const BoardSquare::PacmanContext & context) const;
	
	void receivePacman(BoardSquare::PacmanContext & context);
	
	BoardSquare * clone();
	
private:

	Utils::Orientation _orientation;
	BoardPosition _dest;
	Utils::Orientation _destOrientation;

};

#endif
