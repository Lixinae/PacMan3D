#include <Model3DTex.h>

//TODO static
//attribute vertex pos = 0 ....

Model3DTex::Model3DTex(Program & program, const Mesh & mesh, const unique_ptr<Image> & imageTexture) : 
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
	_uTexture = getUniformLocation("uTexture");
	glGenTextures(1, &_textureObject);
	glBindTexture(GL_TEXTURE_2D, _textureObject);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, imageTexture->getWidth(), imageTexture->getHeight(), 0, GL_RGBA, GL_FLOAT, imageTexture->getPixels());
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBindTexture(GL_TEXTURE_2D, 0);
}

Model3DTex Model3DTex::load(const string & meshPath, const string & texturePath) {
	Program program = loadProgram("shaders/3D.vs.glsl", "tex3D.fs.glsl");
	// TODO except if null
	Mesh mesh = Mesh::fromOBJFile(meshPath);
	unique_ptr<Image> imageTexture = loadImage(texturePath); // todo null check
	return Model3DTex(program, mesh, imageTexture);
}

void Model3DTex::bind() {
	AbstractModel::bind();
	glBindTexture(GL_TEXTURE_2D, _textureObject);
	glUniform1i(_uTexture, 0);
}

void Model3DTex::unbind() {
	glBindTexture(GL_TEXTURE_2D, 0);
	AbstractModel::unbind();
}
