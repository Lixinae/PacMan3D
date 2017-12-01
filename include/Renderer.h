#ifndef __RENDERER_H__
#define __RENDERER_H__

#include <BoardRepresentation.h>

class Renderer {

public:

	virtual void render(const BoardRepresentation & boardRepr) const = 0;
	
	virtual ~Renderer() {
		
	};

};

#endif
