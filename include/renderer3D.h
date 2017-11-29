#ifndef __RENDERER_3D_H__
#define __RENDERER_3D_H__

#include "boardRepresentation.h"

class Renderer3D {

public:

	Renderer3D();

	void render(const BoardRepresentation & boardRepr) const;

};

#endif
