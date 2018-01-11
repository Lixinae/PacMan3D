#include <TexModel3D.h>

using namespace std;

const GLchar *TexModel3D::FRAGMENT_UNIFORM_TEXTURE = "uTexture";

void TexModel3D::initTexture(const unique_ptr<Image> &texture) {
	_uTexture = getUniformLocation(TexModel3D::FRAGMENT_UNIFORM_TEXTURE);
	glGenTextures(1, &_textureObject);
	glBindTexture(GL_TEXTURE_2D, _textureObject);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, texture->getWidth(), texture->getHeight(), 0, GL_RGBA, GL_FLOAT, texture->getPixels());
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBindTexture(GL_TEXTURE_2D, 0);
}

TexModel3D::TexModel3D(const Mesh &mesh, const unique_ptr<Image> &texture, const mat4 &modelTransform) :
		AbstractModel3D(mesh, "shaders/tex3D.fs.glsl", modelTransform) {
	initTexture(texture);
}

TexModel3D *TexModel3D::create(const string &meshPath, const string &texturePath, const mat4 &modelTransform) {
	Mesh mesh = Mesh::fromOBJFile(meshPath);
	unique_ptr<Image> texture = loadImage(texturePath);
	if (texture == nullptr) {
		throw invalid_argument(texturePath + " is not a valid texture");
	}
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
