#include <EventHandler.h>

EventHandler::EventHandler(const SDLWindowManager &windowManager, const Game &game, const Configuration &configuration)
        :
        _windowManager(windowManager),
        _game(game),
        _configuration(configuration) {

}




void EventHandler::handleEvent(const SDL_Event event) {

    auto map = _configuration.getControlMap();

    SDLKey upKey = map[control::UP];
    SDLKey downKey = map[control::DOWN];
    SDLKey leftKey = map[control::LEFT];
    SDLKey rightKey = map[control::RIGHT];
    SDLKey changeCamera = map[control::CHANGE_CAMERA];

//	Pacman &pacman = game.getPacman();
//	if (windowManager.isKeyPressed(SDLK_z)) {
//		cout << "z" << endl;
//		pacman.setOrientation(Pacman::Orientation::NORTH);
//	} else if (windowManager.isKeyPressed(SDLK_s)) {
//		cout << "s" << endl;
//		pacman.setOrientation(Pacman::Orientation::SOUTH);
//	} else if (windowManager.isKeyPressed(SDLK_q)) {
//		cout << "q" << endl;
//		pacman.setOrientation(Pacman::Orientation::WEST);
//	} else if (windowManager.isKeyPressed(SDLK_d)) {
//		cout << "d" << endl;
//		pacman.setOrientation(Pacman::Orientation::EAST);
//	}

    /*
    if(event.type == SDL_QUIT){
        _exitProgram = true;
        return;
    }

    if (event.type == SDL_KEYDOWN) {
        switch (event.key.keysym.sym) { //voir https://wiki.libsdl.org/SDL_Keycode
            // Deplacement de la camera
            case SDLK_q:
                _keyLeft=true;
                _keyRight=false;
                break;
            case SDLK_d:
                _keyLeft=false;
                _keyRight=true;
                break;
            case SDLK_z:
                _keyUp=true;
                _keyDown=false;
                break;
            case SDLK_s:
                _keyDown=true;
                _keyUp=false;
                break;
            case SDLK_KP_PLUS:
                _speedUp = true;
                _speedDown = false;
                break;
            case SDLK_KP_MINUS:
                _speedDown = true;
                _speedUp = false;
                break;
            case SDLK_c:
                _changeCamera = true;
                break;
            case SDLK_t:// todo -> possiblement changer la touche d'activation pour accéléré / décélérer
                _activateSpeed = !_activateSpeed;
                break;
            default:
                break;
        }
    }
    if(event.type == SDL_KEYUP){
        _keyUp = false;
        _keyDown = false;
        _keyLeft = false;
        _keyRight = false;
        _speedUp = false;
        _speedDown = false;
        _changeCamera = false;
    }

    if(event.type == SDL_MOUSEBUTTONDOWN){
        switch(event.button.button){
            case SDL_BUTTON_RIGHT:
                _mouseRight = true;
                break;
            case SDL_BUTTON_LEFT:
                _mouseLeft = true;
                break;
            default:
                break;
        }
    }
    if(event.type == SDL_MOUSEBUTTONUP){
        _mouseRight = false;
        _mouseLeft = false;
    }
    */
}


/*
bool EventHandler::moveLeft() {
	return windowManager.isKeyPressed(SDLK_q);
    //return _keyLeft;
}

bool EventHandler::moveRight() {
	return windowManager.isKeyPressed(SDLK_d);
    //return _keyRight;
}

bool EventHandler::moveUp() {
	return windowManager.isKeyPressed(SDLK_z);
    //return _keyUp;
}

bool EventHandler::moveDown() {
	return windowManager.isKeyPressed(SDLK_s);
    //return _keyDown;
}

bool EventHandler::activateSpeed() {
	return windowManager.isKeyPressed(SDLK_t);
    //return _activateSpeed;
}

bool EventHandler::speedUp() {
	return windowManager.isKeyPressed(SDLK_KP_PLUS);
    //return _speedUp;
}

bool EventHandler::speedDown() {
	return windowManager.isKeyPressed(SDLK_KP_MINUS);
    //return _speedDown;
}

bool EventHandler::changeCamera() {
    return windowManager.isKeyPressed(SDLK_c);
	//return _changeCamera;
}

bool EventHandler::mouseRight() const {
	return windowManager.isMouseButtonPressed(SDL_BUTTON_RIGHT) ;
    //return _mouseRight;
}*/
/*
void EventHandler::set_exitProgram(bool _exitProgram) {
    EventHandler::_exitProgram = _exitProgram;
}

void EventHandler::set_moveLeft(bool _moveLeft) {
    EventHandler::_keyLeft = _moveLeft;
}

void EventHandler::set_moveRight(bool _moveRight) {
    EventHandler::_keyRight = _moveRight;
}

void EventHandler::set_moveUp(bool _moveUp) {
    EventHandler::_keyUp = _moveUp;
}

void EventHandler::set_moveDown(bool _moveDown) {
    EventHandler::_keyDown = _moveDown;
}

void EventHandler::set_activateSpeed(bool _activateSpeed) {
    EventHandler::_activateSpeed = _activateSpeed;
}

void EventHandler::set_speedUp(bool _speedUp) {
    EventHandler::_speedUp = _speedUp;
}

void EventHandler::set_speedDown(bool _speedDown) {
    EventHandler::_speedDown = _speedDown;
}

void EventHandler::set_changeCamera(bool _changeCamera) {
    EventHandler::_changeCamera = _changeCamera;
}

bool EventHandler::mouseLeft() const {
    return _mouseLeft;
}
*/
