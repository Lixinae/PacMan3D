#ifndef __GAME_H__
#define __GAME_H__

#include <Board.h>
#include <Pacman.h>
#include <Ghost.h>
#include <PointOfView.h>
#include <GameInformations.h>
#include <GameRepresentation.h>
#include <json/json.hpp>
#include <string>
#include <vector>

using json = nlohmann::json;

using namespace std;

class Game {

public:

	enum class State {
		CONTINUE,
		WIN,
		LOOSE,
		RESTART
	};

	/**
	 * Créer une partie à partir de sa représentation en JSON
	 * @param jsonGame : représentation en JSON de la partie
	 * @return la partie crée
	 */
	static Game fromJSON(const json &jsonGame);

	/**
	 * Créer une partie à partir de sa représentation en JSON
	 * @param filePath : fichier JSON représentant la partie
	 * @return la partie crée
	 */
	static Game fromJSONFile(const string &filePath);

	/**
	 * Constructeur de copie
	 */
	Game(const Game & other);

	/**
	 * Destructeur
	 */
	~Game();

	/**
	 * Renvoie le point de vue de la partie
	 * @return le point de vue de la partie
	 */
	const PointOfView &getPointOfView() const;

	/**
	 * Change la camera courante
	 */
	void changeCamera();

	/**
	 * Depace la camera courante
	 * @param distance : distance de deplacement
	 */
	void moveFrontCamera(float distance);

	/**
	 * Oriente pacman
	 * @param orientation : nouvelle orientation de pacman
	 */
	void orientPacman(Utils::Orientation orientation);

	/**
	 * Renvoie la representation de la partie
	 * @return la representation de la partie
	 */
	GameRepresentation getRepresentation() const;
	
	/**
	 * Renvoie les informations de la partie
	 * @return les informations de la partie
	 */
	const GameInformations &getInformations() const;

	/**
	 * Itere la partie
	 * @return l'etat de la partie
	 */
	State iterate();

	/**
	 * Reinitialise les fantomes et pacman
	 **/
	void reset();
	
	/**
	 * Reinitialise les fantomes, pacman, le plateau et le score
	 */
	void restart();

	/**
	 * Reinitialise les fantomes, pacman et le plateau
	 */
	void restartKeepingScore();

	/**
	 * Passe au prochain niveau
	 */
	void setNextLevel();
	
	/**
	 * Convertit la partie en JSON
	 * @return la representation en JSON de la partie
	 */
	json toJSON() const;
	
	/**
	 * Convertit la partie dans un fichier JSON
	 * @param filePath : fichier JSON dans lequel sera sauvegarder la representation de la partie en JSON
	 */
	void toJSONFile(const string &filePath) const;
	
	/**
	 * Operator d'affectation
	 */
	Game & operator=(const Game &other);

	/**
	 * Renvoie la position inférieur du plateau de la partie
	 * @return la position inférieur du plateau de la partie
	 */
	BoardPosition getLowerBound() const;

	/**
	 * Renvoie la position supérieur du plateau de la partie
	 * @return la position supérieur du plateau de la partie
	 */
	BoardPosition getUpperBound() const;

private:

	Board _board;
	Pacman _pacman;
	vector<Ghost *> _ghosts;

	Board _board_init;
	Pacman _pacman_init;
	vector<Ghost *> _ghosts_init;

	PointOfView _pointOfView;

	GameInformations _informations;
	GameInformations _informations_init;

	Game(const Board &board, const Board &board_init, const Pacman &pacman, const Pacman &pacman_init, const vector<Ghost *> &ghosts, const vector<Ghost *> &ghosts_init, const GameInformations &informations, const GameInformations &informations_init);
	Game(const Board &board, const Pacman &pacman, const vector<Ghost *> &ghosts, const GameInformations &informations);

	void updateFirstPersonCameraPosition();

	void iteratePacman();

	void iterateGhost(Ghost *ghost);

};

#endif
