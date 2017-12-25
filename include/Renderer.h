#ifndef __RENDERER_H__
#define __RENDERER_H__

#include <GameRepresentation.h>
#include <GameInformations.h>
class Renderer {

public:

	virtual void render(const GameRepresentation & repr,const GameInformations& gameInfo) const = 0;
	
	virtual ~Renderer() = default;;

};

#endif
