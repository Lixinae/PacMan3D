#include <Model3D.h>

#include <GL/glew.h>

Model3D::Model3D() {
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
		//TODO glBufferData
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}
