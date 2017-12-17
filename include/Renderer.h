#ifndef __RENDERER_H__
#define __RENDERER_H__

#include <GameRepresentation.h>

class Renderer {

public:

	virtual void render(const GameRepresentation & repr) const = 0;
	
	virtual ~Renderer() = default;;

};

#endif
