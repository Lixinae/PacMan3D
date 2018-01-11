#ifndef __DISTANCE_MAP_H__
#define __DISTANCE_MAP_H__

#include <Ghost.h>
#include <Board.h>
#include <BoardPosition.h>
#include <vector>
#include <Utils.h>

using namespace std;

class DistanceMap {

public:

	/**
	 * renvoie une fonction permettant de calculer la liste des cases sur lesquel le fantome peut marcher
	 * @param ghost : le fantome
	 * @param board : le plateau
	 * @param context : le contexte du fantome
	 * @return une fonction permettant de calculer la liste des cases sur lesquel le fantome peut marcher
	 */
	static function<vector<Utils::Orientation>()> walkableOrientations(const Ghost & ghost, const Board & board, const BoardSquare::GhostContext & context);

	/**
	 * renvoie une fonction permettant de calculer l'orientation pour suivre pacman
	 * @param ghost : le fantome
	 * @param board : le plateau
	 * @param context : le contexte du fantome
	 * @param pacman : pacman
	 * @return une fonction permettant de calculer l'orientation pour suivre pacman
	 */
	static function<Utils::Orientation()> orientationFollowPacman(const Ghost & ghost, const Board & board, const BoardSquare::GhostContext & context, const Pacman & pacman);
	
	/**
	 * renvoie une fonction permettant de calculer l'orientation pour bloquer pacman
	 * @param ghost : le fantome
	 * @param board : le plateau
	 * @param context : le contexte du fantome
	 * @param pacman : pacman
	 * @return une fonction permettant de calculer l'orientation pour bloquer pacman
	 */
	static function<Utils::Orientation()> orientationBlockPacman(const Ghost & ghost, const Board & board, const BoardSquare::GhostContext & context, const Pacman & pacman);
	
	/**
	 * renvoie une fonction permettant de calculer l'orientation pour fuir pacman
	 * @param ghost : le fantome
	 * @param board : le plateau
	 * @param context : le contexte du fantome
	 * @param pacman : pacman
	 * @return une fonction permettant de calculer l'orientation pour fuir pacman
	 */
	static function<Utils::Orientation()> orientationAvoidPacman(const Ghost & ghost, const Board & board, const BoardSquare::GhostContext & context, const Pacman & pacman);

private:

	static vector<Utils::Orientation> walkableOrientations(const BoardPosition & position, const Board & board, const BoardSquare::GhostContext & context);
	
	static Utils::Orientation auxOrientatioGoToTarget(const Ghost & ghost, const Board & board, const BoardSquare::GhostContext & context, BoardPosition target);

	static function<Utils::Orientation()> orientationGoToTarget(const Ghost & ghost, const Board & board, const BoardSquare::GhostContext & context, BoardPosition target);
	
	static function<Utils::Orientation()> orientationAvoidTarget(const Ghost & ghost, const Board & board, const BoardSquare::GhostContext & context, BoardPosition target);

};

#endif
