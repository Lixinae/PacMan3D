#ifndef __MESH_H__
#define __MESH_H__

#include <vector>
#include <string>
#include <glimac/common.hpp>

using namespace std;
using namespace glimac;

class Mesh {

public:
	
	static Mesh fromOBJFile(const string & filePath);

	const ShapeVertex * getDataPointer() const;
	GLsizei getVertexCount() const;

private:

	vector<ShapeVertex> _vertices;
	
	Mesh(vector<ShapeVertex> vertices);

};

#endif
