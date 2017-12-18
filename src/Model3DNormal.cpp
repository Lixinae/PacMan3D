#include <Model3DNormal.h>

//TODO static

Model3DNormal::Model3DNormal(Program & program, const Mesh & mesh) : 
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
		mat4(1)
	)
{
	
}

Model3DNormal Model3DNormal::load(const string & meshPath) {
	Program program = loadProgram("shaders/3D.vs.glsl", "normal3D.fs.glsl");
	// TODO except if null
	Mesh mesh = Mesh::fromOBJFile(meshPath);
	return Model3DNormal(program, mesh);
}
