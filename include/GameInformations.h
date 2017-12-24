#ifndef __GAME_INFORMATIONS_H__
#define __GAME_INFORMATIONS_H__

class GameInformations {

private:
	int _score;
	int _lives;
	int _multiplier;

public:

	GameInformations();

	explicit GameInformations(int _lives);

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

	/**
	 * Decrease the life count of the player by one
	 */
	void decreaseLife();

	/**
	 * Resets the score multiplier
	 */
	void resetMultiplier();

	/**
	 * Increase the multiplier
	 */
	void increaseMultiplier();

	/**
	 *
	 * @return The score
	 */
	int get_score() const;

	/**
	 *
	 * @return The lives left
	 */
	int get_lives() const;

	/**
	 *
	 * @return The multiplier
	 */
	int get_multiplier() const;


};

#endif

