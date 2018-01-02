#ifndef __BOARD_POSITION_H__
#define __BOARD_POSITION_H__

#include <iostream>
#include <json/json.hpp>
#include <Utils.h>
#include <glimac/common.hpp>

using namespace std;

using json = nlohmann::json;

class BoardPosition {

public:

	/**
	 * Construit la position
	 * @param x : valeur en abcisse
	 * @param y : valeur en ordonnée
	 **/
	BoardPosition(int x, int y);

	/**
	 * Créer une position à partir de sa représentation en JSON
	 * @param jsonPosition : représentation en JSON de la position
	 * @return la position crée
	 **/
	static BoardPosition fromJSON(const json &jsonPosition);

	/**
	 * Renvoie la valeur en abcisse de la position
	 * @return la valeur en abcisse de la position
	 **/
	int getX() const;

	/**
	 * Renvoie la valeur en ordonnée de la position
	 * @return la valeur en ordonnée de la position
	 **/
	int getY() const;

	/**
	 * Réalise une translation sur la position
	 * @param orientation : direction de la translation
	 * @return la position translatée
	 **/
	BoardPosition translate(Utils::Orientation orientation) const;

	/**
	 * Renvoie la position dans l'espace 3D 
	 * @return la position dans l'espace 3D
	 **/
	glm::vec3 inSpace() const;
	
	/**
	 * Renvoie la représentation en JSON de la position
	 * @return la représentation en JSON de la position
	 **/
	json toJSON() const;

	/**
	 * Teste si la position est egale à l'autre
	 * @param other : l'autre position
	 * @return true si les positions sont egales, false sinon
	 **/
	bool operator==(const BoardPosition &other) const;

	/**
	 * Teste si la position est differente de l'autre
	 * @param other : l'autre position
	 * @return true si les positions sont differentes, false sinon
	 **/
	bool operator!=(const BoardPosition &other) const;

	/**
	 * Teste si la position est strictement inferieur à l'autre
	 * @param other : l'autre position
	 * @return true si la position est inferieur, false sinon
	 **/
	bool operator<(const BoardPosition &other) const;

	/**
	 * Teste si la position est strictement superieur à l'autre
	 * @param other : l'autre position
	 * @return true si la position est superieur, false sinon
	 **/
	bool operator>(const BoardPosition &other) const;

	/**
	 * Teste si la position est inferieur à l'autre
	 * @param other : l'autre position
	 * @return true si la position est inferieur, false sinon
	 **/
	bool operator<=(const BoardPosition &other) const;

	/**
	 * Teste si la position est superieur à l'autre
	 * @param other : l'autre position
	 * @return true si la position est superieur, false sinon
	 **/
	bool operator>=(const BoardPosition &other) const;

	/**
	 * Ecrit la position dans le flux
	 * @param os : le flux
	 * @param position : la position
	 * @return le flux en argument
	 **/
	friend ostream &operator<<(ostream &os, BoardPosition position);

private:

	int _x;
	int _y;

};

#endif
