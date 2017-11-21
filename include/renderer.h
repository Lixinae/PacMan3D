#ifndef __RENDERER_H__
#define __RENDERER_H__

class Renderer {

public:

	enum class Model {
		PACMAN,
		WALL,
		PAC_GOMME
		//TODO SUPER_PAC_GOMME, GHOST_SPEEDY, FRUIT_CHERRY, ...
	};

	virtual void render(Model model) = 0;
	
	virtual ~Renderer() {
		
	};

};

#endif
