#ifndef __PACMAN_H__
#define __PACMAN_H__

#include "boardPosition.h"

class Pacman {

public:
	
	Pacman(const BoardPosition & position);
		
private:
	
	BoardPosition _position;

};

#endif
