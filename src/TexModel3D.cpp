#include <TexModel3D.h>

using namespace std;

// todo -> Changer le shader par celui de la lumiere , "shaders/lightning.fs.glsl"
TexModel3D::TexModel3D(const Mesh & mesh, const unique_ptr<Image> & texture, const mat4 & modelTransform) :
		AbstractModel3D(mesh, "shaders/lightning.fs.glsl", modelTransform)
//	AbstractModel3D(mesh, "shaders/tex3D.fs.glsl", modelTransform)
{
	_uTexture = getUniformLocation("uTexture");
	glGenTextures(1, &_textureObject);
	glBindTexture(GL_TEXTURE_2D, _textureObject);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, texture->getWidth(), texture->getHeight(), 0, GL_RGBA, GL_FLOAT, texture->getPixels());
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBindTexture(GL_TEXTURE_2D, 0);
}

TexModel3D * TexModel3D::create(const string & meshPath, const string & texturePath, const mat4 & modelTransform) {
	Mesh mesh = Mesh::fromOBJFile(meshPath);
	unique_ptr<Image> texture = loadImage(texturePath);
	//TODO nullcheck
	return new TexModel3D(mesh, texture, modelTransform);
}

TexModel3D::~TexModel3D() {
	glDeleteTextures(1, &_textureObject);
}

void TexModel3D::bind() {
    AbstractModel3D::bind();
    glBindTexture(GL_TEXTURE_2D, _textureObject);
    glUniform1i(_uTexture, 0);
}

void TexModel3D::unbind() {
	glBindTexture(GL_TEXTURE_2D, 0);
	AbstractModel3D::unbind();
}
