#include "glimac/common.hpp"

// Permet de gerer les evenement de la sdl lors qu'un utilisateur interagit avec le jeu
class EventHandler{

private:
	bool _exitProgram=false;
	bool _keyLeft=false;
	bool _keyRight=false;
	bool _keyUp=false;
	bool _keyDown=false;
	
	bool _activateSpeed=false; // Permet d'activer ou non la commande permet d'accélérer et ralentir les mouvements
	bool _speedUp=false;
	bool _speedDown=false;
	
	bool _changeCamera=false;

    bool _mouseRight= false;
public:
	EventHandler();

	void handleEvent(const SDL_Event event);
	
	bool exitProgram();
	bool moveLeft();
	bool moveRight();
	bool moveUp();
	bool moveDown();

	bool activateSpeed();
	bool speedUp();
	bool speedDown();
	
	bool changeCamera();

	void set_exitProgram(bool _exitProgram);

	void set_moveLeft(bool _moveLeft);

	void set_moveRight(bool _moveRight);

	void set_moveUp(bool _moveUp);

	void set_moveDown(bool _moveDown);

	void set_activateSpeed(bool _activateSpeed);

	void set_speedUp(bool _speedUp);

	void set_speedDown(bool _speedDown);

	void set_changeCamera(bool _changeCamera);
};

