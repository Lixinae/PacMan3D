#ifndef __ABSTRACT_MODEL_3D_H__
#define __ABSTRACT_MODEL_3D_H__

#include <GL/glew.h>
#include <string>
#include <glimac/glm.hpp>
#include <glimac/Program.hpp>

using namespace std;
using namespace glimac;
using namespace glm;

class AbstractModel3D {

public:

	static const string VERTEX_SHADER_3D;

	static const GLuint VERTEX_ATTR_POSITION;
	static const GLuint VERTEX_ATTR_NORMAL;
	static const GLuint VERTEX_ATTR_TEXTURE;
	
	static const GLchar * VERTEX_UNIFORM_MVP_MATRIX;
	static const GLchar * VERTEX_UNIFORM_MV_MATRIX;
	static const GLchar * VERTEX_UNIFORM_NORMAL_MATRIX;
	
	AbstractModel3D(string fragmentShader); //TODO should be protected
	virtual ~AbstractModel3D();
	
	virtual void bind();
	virtual void unbind();
	
	GLsizei count() const;
	
	void setMatrices(const mat4 & ProjMatrix, const mat4 & MVMatrix); // TODO maybe remove

private:

	// TODO model may have a matrix for init transform (scale, ...) 

	GLuint _vbo;
	GLuint _vao;
	GLsizei _size;
	
	Program _program;

	GLuint _uMVPmatrix; 
    GLuint _uMVmatrix;
    GLuint _uNormalmatrix;
    
    void initPoints();
    void initProgram(string fragmentShader);

};

#endif
