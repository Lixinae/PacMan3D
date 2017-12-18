#ifndef __ABSTRACT_MODEL_H__
#define __ABSTRACT_MODEL_H__

#include <GL/glew.h>
#include <glimac/glm.hpp>
#include <glimac/Program.hpp>
#include <vector>

using namespace std;
using namespace glimac;
using namespace glm;

class AbstractModel {

public:

	struct Attribute {
		
		GLuint index;
		GLuint size;
		GLenum type;
		size_t offset;
		
		Attribute(GLuint index, GLuint size, GLenum type, size_t offset);
		
	};
	
	AbstractModel(Program & program, const void * data, GLsizei count, int size, vector<Attribute> attributes, const mat4 & modelTransform);

	~AbstractModel();
	
	virtual void bind();
	virtual void unbind();
	
	GLsizei count() const;
	
	GLuint getUniformLocation(const GLchar * uniform); // TODO may change
	
	void setMatrices(const mat4 & ProjMatrix, const mat4 & MVMatrix); // TODO remove

private:

	Program & _program;
	
	GLuint _vbo;
	GLuint _vao;
	GLsizei _size;

	/* todo rm */
	GLint _uMVPmatrix;
    GLint _uMVmatrix;
    GLint _uNormalmatrix;
    
	mat4 _modelTransform;
	/*		*/

};

#endif
