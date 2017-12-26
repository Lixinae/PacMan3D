#ifndef __GAME_INFORMATIONS_H__
#define __GAME_INFORMATIONS_H__

class GameInformations {

private:
	int _score;
	int _lives;
	int _multiplier;
	int _multiplierCounter;

public:

	GameInformations();

	explicit GameInformations(int lives);

	/**
	 *
	 * @return True If the player is dead, false otherwise
	 */
	bool isDead() const;

	/**
	 * Update the score of the player from
	 * @param value used to upgrade the score
	 */
	void updateScore(int value);

	void updateMultipliedScore(int value);

	/**
	 * Decrease the life count of the player by one
	 */
	void decreaseLife();


	void setMultiplier(int time);

	/**
	 * Increase the multiplier
	 */
	void increaseMultiplier();

	void iterate();

	/**
	 *
	 * @return The score
	 */
	int getScore() const;

	/**
	 *
	 * @return The lives left
	 */
	int getLives() const;

	/**
	 *
	 * @return The multiplier
	 */
	int getMultiplier() const;


};

#endif

