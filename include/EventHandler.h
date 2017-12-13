#ifndef __EVENT_HANDLER_H__
#define __EVENT_HANDLER_H__

#include <glimac/common.hpp>
#include <SDL/SDL.h>
#include <map>
#include <Game.h>
#include <glimac/SDLWindowManager.hpp>
#include <Configuration.h>

#include <Camera.h> // TODO rm

using namespace glimac;
using namespace std;
using namespace glm;

class EventHandler {

private:

	map<control, SDLKey> _keyMap;

public:

	EventHandler(const map<control, SDLKey> & keyMap);

    /**
     * Gère les evenement liés à la SDL, tel que les touches appuyer ou les mouvement de la souris
     * @param windowManager Window Manager
     */
    bool handleEvent(SDLWindowManager & windowManager, Game & game);

};

#endif
