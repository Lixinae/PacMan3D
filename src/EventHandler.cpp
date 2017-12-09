#include <EventHandler.h>

EventHandler::EventHandler(const SDLWindowManager &windowManager, const Game &game, const Configuration &configuration)
        :
        _windowManager(windowManager),
        _game(game),
        _configuration(configuration) {

}

// todo -> changer car tres moche
SDLKey stringToKey(string s) {
    if (s == "a") return SDLK_a;
    if (s == "b") return SDLK_b;
    if (s == "c") return SDLK_c;
    if (s == "d") return SDLK_d;
    if (s == "e") return SDLK_e;
    if (s == "f") return SDLK_f;
    if (s == "g") return SDLK_g;
    if (s == "h") return SDLK_h;
    if (s == "i") return SDLK_i;
    if (s == "j") return SDLK_j;
    if (s == "k") return SDLK_k;
    if (s == "l") return SDLK_l;
    if (s == "m") return SDLK_m;
    if (s == "n") return SDLK_n;
    if (s == "o") return SDLK_o;
    if (s == "p") return SDLK_p;
    if (s == "q") return SDLK_q;
    if (s == "r") return SDLK_r;
    if (s == "s") return SDLK_s;
    if (s == "t") return SDLK_t;
    if (s == "u") return SDLK_u;
    if (s == "v") return SDLK_v;
    if (s == "w") return SDLK_w;
    if (s == "x") return SDLK_x;
    if (s == "y") return SDLK_y;
    if (s == "z") return SDLK_z;
    if (s == "1") return SDLK_1;
    if (s == "2") return SDLK_2;
    if (s == "3") return SDLK_3;
    if (s == "4") return SDLK_4;
    if (s == "5") return SDLK_5;
    if (s == "6") return SDLK_6;
    if (s == "7") return SDLK_7;
    if (s == "8") return SDLK_8;
    if (s == "9") return SDLK_9;
    if (s == "0") return SDLK_0;
    if (s == "k+") return SDLK_KP_PLUS;
    if (s == "k-") return SDLK_KP_MINUS;
    if (s == "k*") return SDLK_KP_MULTIPLY;
    if (s == "k/") return SDLK_KP_DIVIDE;
    if (s == "kenter") return SDLK_KP_ENTER;
    if (s == "k.") return SDLK_KP_PERIOD;
    if (s == "insert") return SDLK_INSERT;
    if (s == "home") return SDLK_HOME;
    if (s == "pgup") return SDLK_PAGEUP;
    if (s == "pgdown") return SDLK_PAGEDOWN;
    if (s == "end") return SDLK_END;
    if (s == "delete") return SDLK_DELETE;
    if (s == "ralt") return SDLK_RALT;
    if (s == "rshift") return SDLK_RSHIFT;
    if (s == "rctrl") return SDLK_RCTRL;
    if (s == "lalt") return SDLK_LALT;
    if (s == "lshift") return SDLK_LSHIFT;
    if (s == "lctrl") return SDLK_LCTRL;
    if (s == "up") return SDLK_UP;
    if (s == "down") return SDLK_DOWN;
    if (s == "right") return SDLK_RIGHT;
    if (s == "left") return SDLK_LEFT;
    if (s == "`") return SDLK_BACKQUOTE;
    if (s == "[") return SDLK_LEFTBRACKET;
    if (s == "]") return SDLK_RIGHTBRACKET;
    if (s == "-") return SDLK_MINUS;
    if (s == "=") return SDLK_EQUALS;
    if (s == "backspace") return SDLK_BACKSPACE;
    if (s == "/") return SDLK_SLASH;
    if (s == "\\") return SDLK_BACKSLASH;
    if (s == ",") return SDLK_COMMA;
    if (s == ".") return SDLK_PERIOD;
    if (s == ";") return SDLK_SEMICOLON;
    if (s == "'") return SDLK_QUOTE;
    if (s == "f1") return SDLK_F1;
    if (s == "f2") return SDLK_F2;
    if (s == "f3") return SDLK_F3;
    if (s == "f4") return SDLK_F4;
    if (s == "f5") return SDLK_F5;
    if (s == "f6") return SDLK_F6;
    if (s == "f7") return SDLK_F7;
    if (s == "f8") return SDLK_F8;
    if (s == "f9") return SDLK_F9;
    if (s == "f10") return SDLK_F10;
    if (s == "f11") return SDLK_F11;
    if (s == "f12") return SDLK_F12;
    if (s == "f13") return SDLK_F13;
    if (s == "f14") return SDLK_F14;
    if (s == "f15") return SDLK_F15;
    if (s == "esc") return SDLK_ESCAPE;

}


void EventHandler::handleEvent(const SDL_Event event) {

    auto map = _configuration.getControlMap();

    SDLKey upKey = stringToKey(map[control::UP]);
    SDLKey downKey = stringToKey(map[control::DOWN]);
    SDLKey leftKey = stringToKey(map[control::LEFT]);
    SDLKey rightKey = stringToKey(map[control::RIGHT]);
    SDLKey changeCamera = stringToKey(map[control::CHANGE_CAMERA]);

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
