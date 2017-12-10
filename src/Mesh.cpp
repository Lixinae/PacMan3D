#include <Mesh.h>


#include <glimac/Sphere.hpp>

Mesh::Mesh(vector<ShapeVertex> vertices) : _vertices(vertices) {

}

Mesh Mesh::fromOBJFile(const string & filePath) {
	/* TODO real impl */
	float r;
	if (filePath == "a") {
		r = 0.7;
	} else if (filePath == "b") {
		r = 1;
	} else {
		r = 0.3;
	}
	Sphere sphere(r,16,16);
	vector<ShapeVertex> vertices(sphere.getVertexCount());
	for (int i = 0; i < sphere.getVertexCount(); i++) {
		vertices[i] = sphere.getDataPointer()[i];
	}
	/*  			  */
	return Mesh(vertices);
}

const ShapeVertex * Mesh::getDataPointer() const {
	return _vertices.data();
}

GLsizei Mesh::getVertexCount() const {
	return _vertices.size();
}
