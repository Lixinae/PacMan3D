#ifndef __EVENT_HANDLER_H__
#define __EVENT_HANDLER_H__

#include <glimac/common.hpp>
#include <SDL/SDL.h>
#include <map>
#include <Game.h>
#include <glimac/SDLWindowManager.hpp>
#include <Configuration.h>

using namespace glimac;
using namespace std;
using namespace glm;

class EventHandler {

private:

	map<control, SDLKey> _keyMap;

	void cameraMovement(const SDLWindowManager &windowManager, Game &game) const;

public:

	enum class State {
		NEXT,
		CONTINUE,
		PAUSE,
		QUIT
	};


	/**
	 * Constructeur de gestionnaire d'événement
	 * @param keyMap : tableau des controles
	 **/
	explicit EventHandler(const map<control, SDLKey> &keyMap);

	/**
	 * Gère les evenement de l'ecran titre
	 * @param windowManager : gestionnaire de la fenetre
	 * @return l'etat du jeu
	 **/
	State handleBeginTitleEvent(SDLWindowManager &windowManager);

	/**
	 * Gère les evenement de l'ecran de debut
	 * @param windowManager : gestionnaire de la fenetre
	 * @param game : le jeu
	 * @return l'etat du jeu
	 **/
	State handleBeginGameEvent(SDLWindowManager &windowManager, Game &game);

	/**
	 * Gère les evenement du jeu
	 * @param windowManager : gestionnaire de la fenetre
	 * @param game : le jeu
	 * @return l'etat du jeu
	 **/
	State handleGameEvent(SDLWindowManager &windowManager, Game &game);

	/**
	 * Gère les evenement de l'ecran de pause
	 * @param windowManager : gestionnaire de la fenetre
	 * @param game : le jeu
	 * @return l'etat du jeu
	 **/
	State handlePauseMenuEvent(SDLWindowManager &windowManager, Game &game);

	/**
	 * Gère les evenement de l'ecran de fin
	 * @param windowManager : gestionnaire de la fenetre
	 * @return l'etat du jeu
	 **/
	State handleEndTitleEvent(SDLWindowManager &windowManager);


};

#endif
