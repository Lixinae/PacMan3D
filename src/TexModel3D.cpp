#include <TexModel3D.h>

#include <AbstractModel3D.h>
#include <string>
#include <glimac/Image.hpp>
#include <Utils.h>

using namespace std;

TexModel3D::TexModel3D(const string & meshPath, const string & texturePath, const mat4 & modelTransform) : AbstractModel3D(meshPath, "shaders/tex3D.fs.glsl", modelTransform) {
	_uTexture = getUniformLocation("uTexture");
	unique_ptr<Image> imageTexture = loadImage(texturePath); // todo null check : factory
	glGenTextures(1, &_textureObject);
	glBindTexture(GL_TEXTURE_2D, _textureObject);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, imageTexture->getWidth(), imageTexture->getHeight(), 0, GL_RGBA, GL_FLOAT, imageTexture->getPixels());
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBindTexture(GL_TEXTURE_2D, 0);
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
