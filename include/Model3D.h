#ifndef __MODEL_3D_H__
#define __MODEL_3D_H__

#include <GL/glew.h>

class Model3D {

public:
	
	Model3D(); //TODO should be private:load from file
	
	void bindVAO() const; // TODO may be not const
	void unbindVAO() const;
	
	GLsizei count() const;

private:

	GLuint vao;

};

#endif
