#include <AbstractModel.h>

using namespace std;
using namespace glimac;
using namespace glm;

AbstractModel::Attribute::Attribute(GLuint index, GLuint size, GLenum type, size_t offset) :
	index(index),
	size(size),
	type(type),
	offset(offset)
{
	
}

AbstractModel::AbstractModel
	(
		Program & program,
		const void * data, GLsizei count,
		int size,
		vector<Attribute> attributes,
		const mat4 & modelTransform
	) :
	_program(program)
{
	glGenBuffers(1, &_vbo);
	glBindBuffer(GL_ARRAY_BUFFER, _vbo);
	_size = count;
	glBufferData(GL_ARRAY_BUFFER, count*size, data, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glGenVertexArrays(1, &_vao);
	glBindVertexArray(_vao);
	for (Attribute attribute : attributes) {
		glEnableVertexAttribArray(attribute.index);
	}
	glBindBuffer(GL_ARRAY_BUFFER, _vbo);
	for (Attribute attribute : attributes) {
		glVertexAttribPointer(attribute.index, attribute.size, attribute.type, GL_FALSE, size, (const GLvoid*) attribute.offset);
	}
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	
	/* TODO REMOVE */
	_modelTransform = modelTransform;
	_uMVPmatrix = getUniformLocation("uMVPMatrix");
    _uMVmatrix = getUniformLocation("uMVMatrix");
    _uNormalmatrix = getUniformLocation("uNormalMatrix");
	/* 				*/
}

AbstractModel::~AbstractModel()  {
	glDeleteBuffers(1, &_vbo);
	glDeleteVertexArrays(1, &_vao);
}

void AbstractModel::bind() {
	_program.use();
	glBindVertexArray(_vao);
}

void AbstractModel::unbind() {
	glBindVertexArray(0);
}

GLsizei AbstractModel::count() const {
	return _size;
}

GLuint AbstractModel::getUniformLocation(const GLchar * uniform) {
	return glGetUniformLocation(_program.getGLId(), uniform);
}

void AbstractModel::setMatrices(const mat4 & ProjMatrix, const mat4 & MVMatrix) { //TODO remove
	mat4 transformMVMatrix = MVMatrix * _modelTransform;
	glUniformMatrix4fv(_uMVPmatrix, 1, GL_FALSE, value_ptr(ProjMatrix * transformMVMatrix));
	glUniformMatrix4fv(_uMVmatrix, 1, GL_FALSE, value_ptr(transformMVMatrix));
	glUniformMatrix4fv(_uNormalmatrix, 1, GL_FALSE, value_ptr(transpose(inverse(transformMVMatrix))));
}

