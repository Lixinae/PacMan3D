#ifndef __TEX_MODEL_3D_H__
#define __TEX_MODEL_3D_H__

#include <AbstractModel3D.h>
#include <string>
#include <glimac/Image.hpp>

using namespace std;

class TexModel3D : public AbstractModel3D {

public:

	//TODO static const path

	static const GLchar *FRAGMENT_UNIFORM_TEXTURE;

	static TexModel3D *create(const string &meshPath, const string &texturePath, const mat4 &modelTransform);

	~TexModel3D();

	void bind() override;

	void unbind() override;

private:

	GLuint _textureObject;
	GLint _uTexture;

	TexModel3D(const Mesh &mesh, const unique_ptr<Image> &texture, const mat4 &modelTransform);

	void initTexture(const unique_ptr<Image> &texture);

};

#endif
