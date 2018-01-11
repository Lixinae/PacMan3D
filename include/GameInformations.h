#ifndef __GAME_INFORMATIONS_H__
#define __GAME_INFORMATIONS_H__

#include <json/json.hpp>

using json = nlohmann::json;

class GameInformations {

private:
	int _score;
	int _score_init;
	int _score_max_life;
	int _step_score_max_life;
	int _lives;
	int _multiplier;
	int _multiplierCounter;
	int _level;

	void addLifeScore();

public:

	static GameInformations fromJSON(const json &jsonInfo);

	GameInformations();

	explicit GameInformations(int score, int score_max_life, int step_score_max_life, int lives, int multiplier, int multiplierCounter, int level);

	/**
	 * Indique si le joueur est mort ou non
	 * @return True si le joueur est mort , False sinon
	 */
	bool isDead() const;

	/**
	 * Augmente le score
	 * @param value La valeur à additioner au score
	 */
	void updateScore(int value);

	void updateMultipliedScore(int value);

	/**
	 * Reduit de 1 le nombre de vie du joueur
	 */
	void decreaseLife();

	/**
	 * Met la durée du multiplicateur
	 * @param time Durée du multiplicateur
	 */
	void setMultiplierCounter(int time);

	/**
	 * Augmente le multiplicateur
	 */
	void increaseMultiplier();

	void iterate();

	/**
	 * Renvoie le score
	 * @return Le score
	 */
	int getScore() const;

	/**
	 * Renvoie le nombre de vie restantes
	 * @return Le nombre de vie restantes
	 */
	int getLives() const;


	json toJSON() const;

	/**
	 * Augmente le niveau
	 */
	void increaseLevel();

	/**
	 * Renvoie le niveau sur lequel est le joueur
	 * @return Le niveau sur lequel est le joueur
	 */
	int getLevel() const;

};

#endif

