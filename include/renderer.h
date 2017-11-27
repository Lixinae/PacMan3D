#ifndef __RENDERER_H__
#define __RENDERER_H__

#include "boardRepresentation.h"

class Renderer {

public:

	virtual void render(const BoardRepresentation & boardRepr) = 0;
	
	virtual ~Renderer() {
		
	};

};

#endif
