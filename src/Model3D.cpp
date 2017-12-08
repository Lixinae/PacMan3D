#include <Model3D.h>

#include <GL/glew.h>

Model3D::Model3D() : Model3D(1,1,1) {
	
}

Model3D::Model3D(float r, float g, float b) {
	const GLuint VERTEX_ATTR_POSITION = 0;
	const GLuint VERTEX_ATTR_COLOR = 1;
	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	GLfloat vertices[] = { -0.5f, -0.5f, r, g, b, // premier sommet
							0.5f, -0.5f, r, g, b, // deuxième sommet
							0.0f, 0.5f,  r, g, b // troisième sommet
	};
	glBufferData(GL_ARRAY_BUFFER, 15*sizeof(GLfloat), vertices, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	glEnableVertexAttribArray(VERTEX_ATTR_POSITION);
	glEnableVertexAttribArray(VERTEX_ATTR_COLOR);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glVertexAttribPointer(VERTEX_ATTR_POSITION, 2, GL_FLOAT, GL_FALSE, 5*sizeof(GLfloat), 0); 
	glVertexAttribPointer(VERTEX_ATTR_COLOR, 3, GL_FLOAT, GL_FALSE, 5*sizeof(GLfloat), (const GLvoid *) (2*sizeof(GLfloat)));  
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
