#ifndef __GHOST_H__
#define __GHOST_H__

#include "boardPosition.h"

class Ghost {

public:

	Ghost(const BoardPosition & position);

private:

	BoardPosition _position;

};

#endif