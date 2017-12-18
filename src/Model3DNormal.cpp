#include <Model3DNormal.h>

//TODO static

Model3DNormal::Model3DNormal(Program & program, const Mesh & mesh, const mat4 & transformations) : 
	AbstractModel(
		program,
		mesh.getDataPointer(),
		mesh.getVertexCount(),
		sizeof(ShapeVertex),
		{
			AbstractModel::Attribute(0, 3, GL_FLOAT, offsetof(ShapeVertex, position)),
			AbstractModel::Attribute(1, 3, GL_FLOAT, offsetof(ShapeVertex, normal)),
			AbstractModel::Attribute(2, 2, GL_FLOAT, offsetof(ShapeVertex, texCoords))
		},
		transformations
	)
{
	
}

AbstractModel * Model3DNormal::load(const string & meshPath, const mat4 & transformations) {
	Program program = loadProgram("shaders/3D.vs.glsl", "shaders/normal3D.fs.glsl");
	// TODO except if null
	Mesh mesh = Mesh::fromOBJFile(meshPath);
	return new Model3DNormal(program, mesh, transformations);
}
