#include <Model3D.h>

#include <GL/glew.h>

Model3D::Model3D() {
	const GLuint VERTEX_ATTR_POSITION = 0;
	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	GLfloat vertices[] = { -0.5f, -0.5f, 0.5f, -0.5f, 0.0f, 0.5f };
	glBufferData(GL_ARRAY_BUFFER, 6*sizeof(GLfloat), vertices, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	glEnableVertexAttribArray(VERTEX_ATTR_POSITION);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glVertexAttribPointer(VERTEX_ATTR_POSITION, 2, GL_FLOAT, GL_FALSE, 2*sizeof(GLfloat), 0); 
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void Model3D::bindVAO() const {
	glBindVertexArray(vao);
}

void Model3D::unbindVAO() const {
	glBindVertexArray(0);
}

GLsizei Model3D::count() const {
	return 3;
}
