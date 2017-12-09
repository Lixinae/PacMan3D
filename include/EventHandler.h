#ifndef __EVENT_HANDLER_H__
#define __EVENT_HANDLER_H__

#include <glimac/common.hpp>
#include <SDL/SDL.h>
#include <Game.h>
#include <glimac/SDLWindowManager.hpp>
#include <Configuration.h>

using namespace glimac;
using namespace std;
using namespace glm;
// Permet de gerer les evenement de la sdl lors qu'un utilisateur interagit avec le jeu
class EventHandler{

private:

    SDLWindowManager _windowManager;
    Game _game;
    Configuration _configuration;
    //std::map<> keyMap;// todo changer les types
    /*
    bool _keyLeft=false;
    bool _keyRight=false;
    bool _keyUp=false;
    bool _keyDown=false;

    bool _activateSpeed=false; // Permet d'activer ou non la commande permet d'accélérer et ralentir les mouvements
    bool _speedUp=false;
    bool _speedDown=false;

    bool _changeCamera=false;

    bool _mouseRight= false;
    bool _mouseLeft= false;*/
public:
    EventHandler(const SDLWindowManager &windowManager, const Game &game, const Configuration &configuration);

	void handleEvent(const SDL_Event event);

    /*
    bool moveLeft() const;
    bool moveRight() const;
    bool moveUp() const;
    bool moveDown() const;

    bool activateSpeed() const;
    bool speedUp() const;
    bool speedDown() const;

    bool changeCamera() const;

    bool mouseRight() const;

    bool mouseLeft() const;


    void set_exitProgram(bool _exitProgram);

    void set_moveLeft(bool _moveLeft);

    void set_moveRight(bool _moveRight);

    void set_moveUp(bool _moveUp);

    void set_moveDown(bool _moveDown);

    void set_activateSpeed(bool _activateSpeed);

    void set_speedUp(bool _speedUp);

    void set_speedDown(bool _speedDown);

    void set_changeCamera(bool _changeCamera);
    */
};

#endif
