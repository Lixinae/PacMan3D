#ifndef __TUNNEL_H__
#define __TUNNEL_H__

#include <BoardSquare.h>
#include <Pacman.h>
#include <GameRepresentation.h>
#include <Utils.h>
#include <BoardPosition.h>

class Tunnel : public BoardSquare {

public:

	Tunnel(Utils::Orientation orientation, const BoardPosition &dest, Utils::Orientation destOrientation);

	vector<GameRepresentation::Model> getModels() const override;

	bool isPacmanWalkable(const BoardSquare::PacmanContext &context) const override;

	void receivePacman(BoardSquare::PacmanContext &context) override;

	bool isGhostWalkable(const BoardSquare::GhostContext &context) const override;

	void receiveGhost(BoardSquare::GhostContext &context) override;

	bool isDone() const override;

	void iterate() override;

	BoardSquare *clone() const override;

	json toJSON() const override;

private:

	Utils::Orientation _orientation;
	BoardPosition _dest;
	Utils::Orientation _destOrientation;

};

#endif
