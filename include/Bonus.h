#ifndef __BONUS_H__
#define __BONUS_H__

#include <Ghost.h>
#include <GameInformations.h>
#include <GameRepresentation.h>
#include <json/json.hpp>

using json = nlohmann::json;

class Bonus {

public:

	struct Context {

		vector<Ghost *> &ghosts;
		GameInformations &informations;

		Context(vector<Ghost *> &ghosts, GameInformations &informations);

	};

	/**
	 * Créer un bonus à partir de sa représentation en JSON
	 * @param jsonBonus : représentation en JSON du bonus
	 * @return le bonus crée
	 **/
	static Bonus *fromJSON(const json &jsonBonus);

	/**
	 * Renvoie le modele du bonus
	 * @return le modele du bonus
	 **/
	virtual GameRepresentation::Model getModel() const = 0;

	/**
	 * Applique le bonus
	 * @param context : contexte
	 **/
	virtual void apply(Context &context) = 0;

	/**
	 * Teste si le bonus est necessaire pour la fin du jeu
	 * @return true si le bonus est necessaire, false sinon
	 **/
	virtual bool isRequired() const = 0;

	/**
	 * Copie le bonus
	 * @return une copie du bonus
	 **/
	virtual Bonus *clone() const = 0;

	/**
	 * Convertit le bonus en JSON
	 * @return la représentation en JSON du bonus
	 **/
	virtual json toJSON() const = 0;

	/**
	 * Destructeur
	 **/
	virtual ~Bonus() = default;;

};

#endif
