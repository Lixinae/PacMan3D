#ifndef __ABSTRACT_MODEL_3D_H__
#define __ABSTRACT_MODEL_3D_H__

#include <GL/glew.h>
#include <Mesh.h>
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
	
	AbstractModel3D(const string & mesh, const string & fragmentShader, const mat4 & modelTransform); 
																			//TODO should be protected
																		   // mesh class and not string
	
	virtual ~AbstractModel3D();
	
	virtual void bind();
	virtual void unbind();
	
	GLsizei count() const;
	
	GLuint getUniformLocation(const GLchar * uniform);
	
	void setMatrices(const mat4 & ProjMatrix, const mat4 & MVMatrix);

private:

	Program _program;

	GLuint _vbo;
	GLuint _vao;
	GLsizei _size;

	GLint _uMVPmatrix;
    GLint _uMVmatrix;
    GLint _uNormalmatrix;
    
    mat4 _modelTransform;
    
    void initPoints(const Mesh & mesh);
    void initProgram(const string & fragmentShader);

};

#endif
