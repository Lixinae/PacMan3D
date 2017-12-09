#ifndef __ABSTRACT_MODEL_3D_H__
#define __ABSTRACT_MODEL_3D_H__

#include <GL/glew.h>
#include <string>
#include <glimac/Program.hpp>

using namespace std;
using namespace glimac;

class AbstractModel3D {

public:

	static const string VERTEX_SHADER_3D;

	static const GLuint VERTEX_ATTR_POSITION;
	static const GLuint VERTEX_ATTR_NORMAL;
	static const GLuint VERTEX_ATTR_TEXTURE;
	
	AbstractModel3D(string fragmentShader); //TODO should be protected
	virtual ~AbstractModel3D();
	
	virtual void bind();
	virtual void unbind();
	
	GLsizei count() const;

private:

	// TODO model may have a matrix for init transform (scale, ...) 

	GLuint _vbo;
	GLuint _vao;
	GLsizei _size;
	Program _program;

};

#endif
