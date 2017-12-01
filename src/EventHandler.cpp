#include "EventHandler.hpp"

EventHandler::EventHandler() {

}

void EventHandler::handleEvent(const SDL_Event event){

    if(event.type == SQL_QUIT){
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
    }


    if(event.type == SDL_MOUSEBUTTONDOWN){
        switch(event.button.button){
            case SDL_BUTTON_RIGHT:
                _mouseRight = true;
                break;
            default:
                break;
        }
    }
    if(event.type == SDL_MOUSEBUTTONUP){
        _mouseRight = false;
    }
}

bool EventHandler::exitProgram() {
    return _exitProgram;
}

bool EventHandler::moveLeft() {
    return _keyLeft;
}

bool EventHandler::moveRight() {
    return _keyRight;
}

bool EventHandler::moveUp() {
    return _keyUp;
}

bool EventHandler::moveDown() {
    return _keyDown;
}

bool EventHandler::activateSpeed() {
    return _activateSpeed;
}

bool EventHandler::speedUp() {
    return _speedUp;
}

bool EventHandler::speedDown() {
    return _speedDown;
}

bool EventHandler::changeCamera() {
    return _changeCamera;
}

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

