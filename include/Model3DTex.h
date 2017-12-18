#ifndef __MODEL_3D_TEX_H__
#define __MODEL_3D_TEX_H__

#include <AbstractModel.h>
#include <Mesh.h>
#include <glimac/Image.hpp>
#include <string>

class Model3DTex : public AbstractModel {

public:

	static Model3DTex load(const string & meshPath, const string & texturePath);

	void bind();
	void unbind();

private:

	GLuint _textureObject; // TODO destruct it
	GLint _uTexture;

	Model3DTex(Program & program, const Mesh & mesh, const unique_ptr<Image> & imageTexture);

};

#endif
