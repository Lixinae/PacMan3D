#ifndef __GHOST_H__
#define __GHOST_H__

#include <BoardPosition.h>

class Ghost {

public:

	explicit Ghost(const BoardPosition & position);

private:

	BoardPosition _position;

};

#endif
