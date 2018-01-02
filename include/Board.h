#ifndef __BOARD_H__
#define __BOARD_H__

#include <BoardPosition.h>
#include <BoardSquare.h>
#include <GameRepresentation.h>
#include <map>
#include <vector>
#include <json/json.hpp>

using namespace std;

using json = nlohmann::json;

class Board {

public:
	
	/**
	 * Créer un plateau à partir de sa représentation en JSON
	 * @param jsonBoard : représentation en JSON du plateau
	 * @return le plateau crée
	 */
	static Board fromJSON(const json & jsonBoard);
	
	/**
	 * Constructeur de copie
	 * @param other : plateau à copier
	 **/
	Board(const Board & other);
	
	/**
	 * Destructeur
	 **/
	~Board();

	/**
	 * Renvoie les coordonnées du plateau
	 * @return les coordonnées du plateau
	 **/
	vector<BoardPosition> getPositions() const;

	/**
	 * Renvoie la case à la position en argument
	 * @param position : position de la case
	 * @return la case a la position en argument
	 */
	BoardSquare * getSquare(const BoardPosition & position) const;

	/**
	 * Renvoie la case à la position en argument
	 * @param position : position de la case
	 * @return la case a la position en argument
	 */
	BoardSquare *operator[](const BoardPosition &position) const;

	/**
	 * Operateur d'affectation
	 * @param other : plateau à affecter
	 * @return la reference vers le plateau
	 **/
	Board &operator=(const Board &other);

	/**
	 * Convertit le plateau en JSON
	 * @return la représentation du plateau en JSON
	 **/
	json toJSON() const;
			
private:
 
	map<BoardPosition, BoardSquare *> _squares;

	Board(const map<BoardPosition, BoardSquare *> & squares);

};

#endif
