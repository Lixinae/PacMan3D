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

public:

	enum class State {
		NEXT,
		CONTINUE,
		PAUSE,
		QUIT
	};


	explicit EventHandler(const map<control, SDLKey> &keyMap);

	State handleBeginTitleEvent(SDLWindowManager &windowManager);

	State handleBeginGameEvent(SDLWindowManager &windowManager, Game &game);

	/**
	 * Gère les evenement liés à la SDL, tel que les touches appuyer ou les mouvement de la souris
	 * @param windowManager Window Manager
	 */
	State handleGameEvent(SDLWindowManager &windowManager, Game &game);

	State handleEndTitleEvent(SDLWindowManager &windowManager);

};

#endif
