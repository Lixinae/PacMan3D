#ifndef __RENDERER_3D_H__
#define __RENDERER_3D_H__

#include "renderer.h"
#include "boardRepresentation.h"

class Renderer3D : public Renderer {

public:

	Renderer3D(); //TODO private + take in argument the map of BoardRepresentation->Model3D  

	void render(const BoardRepresentation & boardRepr) const;

};

#endif
