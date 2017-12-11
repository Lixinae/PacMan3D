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

	EventHandler(const map<control, SDLKey> & keyMap);

public:

    static EventHandler fromConfiguration(const Configuration & configuration);

    /**
     * Gère les evenement liés à la SDL, tel que les touches appuyer ou les mouvement de la souris
     * @param windowManager Window Manager
     */
    void handleEvent(SDLWindowManager & windowManager, Game & game);

};

#endif
