#ifndef __GHOST_H__
#define __GHOST_H__

#include <BoardPosition.h>
#include <GameRepresentation.h>
#include <Pacman.h>
#include <Utils.h>

using json = nlohmann::json;

class Ghost {

public:

	struct MovingContext {

		Pacman &pacman;
		function<vector<Utils::Orientation>()> &availableOrientation;
		function<Utils::Orientation()> &orientationOnPacman;
		function<Utils::Orientation()> &orientationBlockPacman;
		function<Utils::Orientation()> &orientationAvoidPacman;

		MovingContext(
				Pacman &pacman,
				function<vector<Utils::Orientation>()> &availableOrientation,
				function<Utils::Orientation()> &orientationOnPacman,
				function<Utils::Orientation()> &orientationBlockPacman,
				function<Utils::Orientation()> &orientationAvoidPacman
		);

	};

	static int CASE_REDIRECTION_ITERATION;
	static int MAX_ITERATION;

	/**
	 * Créer un fantome à partir de sa représentation en JSON
	 * @param jsonGhost : représentation en JSON du fantome
	 * @return le fantome crée
	 */
	static Ghost *fromJSON(const json &jsonGhost);

	/**
	 * Construit un fantome
	 * @param position : position du fantome
	 * @param orientation : orientation du fantome
	 */
	Ghost(const BoardPosition &position, Utils::Orientation orientation);

	/**
	 * Renvoie l'orientation du fantome
	 * @return l'orientation du fantome
	 */
	Utils::Orientation getOrientation() const;

	/**
	 * Change l'orientation du fantome
	 * @param orientation : la nouvelle orientation du fantome
	 */
	void setOrientation(Utils::Orientation orientation);

	/**
	 * Change la prochaine orientation du fantome
	 * @param context : contexte
	 * @return true si l'orientation du fantome a changé, false sinon
	 */
	bool orientToTarget(const MovingContext &context);

	/**
	 * Renvoie la position du fantome
	 * @return la position du fantome
	 */
	BoardPosition getPosition() const;

	/**
	 * Change la position du fantome
	 * @param position : la nouvelle position du fantome
	 */
	void setPosition(const BoardPosition &position);

	/**
	 * Renvoie les positions ou le fantome appartient graphiquement
	 * @return les potitions graphiques du fantome
	 */
	vector<BoardPosition> getGraphicalPositions() const;

	/**
	 * Change la prochaine position du fantome
	 * @param position : la nouvelle position du fantome
	 * @return true si le fantome a bougé, false sinon
	 */
	bool goTo(const BoardPosition &position);

	/**
	 * Renvoie l'état du fantome
	 * @return true si le fantome est en etat faible, false sinon
	 */
	bool isWeak() const;

	/**
	 * Met le fantome en etat faible
	 * @param time : nombre d'iteration en etat faible
	 */
	void setWeak(int time);

	/**
	 * Est ce que le fantome peut traverser la porte
	 * @return true si le fantome peut traverser la porte, false sinon
	 */
	bool canCrossDoor();

	/**
	 * Fais traverser la porte au fantome
	 */
	void crossDoor();

	/**
	 * Renvoie le decalage graphique par rapport au centre de la case
	 * @return le decalage graphique par rapport au centre de la case
	 */
	float getShift() const;

	/**
	 * Itere le fantome
	 */
	void iterate();

	/**
	 * Renvoie le modele du fantome
	 * @return le modele du fantome
	 */
	GameRepresentation::Model getModel() const;

	/**
	 * Renvoie la prochaine orientation du fantome
	 * @param context : contexte
	 * @return la prochaine orientation du fantome
	 */
	virtual Utils::Orientation getNextOrientation(const MovingContext &context) const = 0;

	/**
	 * Renvoie le type de modele du fantome
	 * @return le type de modele du fantome
	 */
	virtual GameRepresentation::ModelType getModelType() const = 0;

	/**
	 * clone le fantome
	 * @return une copie du fantome
	 */
	virtual Ghost *clone() const = 0;

	/**
	 * Convertit le fantome en JSON
	 * @return la representation en JSON du fantome
	 */
	virtual json toJSON() const = 0;

private:

	BoardPosition _position;
	Utils::Orientation _orientation;
	BoardPosition _nextPosition;
	int _iterPosition;
	int _iterOrientation;
	int _weakCounter;
	bool _crossDoor;

};

#endif
