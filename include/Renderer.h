#ifndef __RENDERER_H__
#define __RENDERER_H__

#include <GameRepresentation.h>
#include <GameInformations.h>

class Renderer {

public:

	virtual void renderGame(const GameRepresentation &repr, const GameInformations &gameInfo) const = 0;

	virtual void renderBeginTitle() const = 0;

	virtual void renderBeginGame() const = 0;
	
	virtual void renderPauseMenu() const = 0;

	virtual void renderEndTitle() const = 0;

	virtual ~Renderer() = default;

};

#endif
