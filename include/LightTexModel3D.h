#ifndef __LIGHT_TEX_MODEL_3D_H__
#define __LIGHT_TEX_MODEL_3D_H__

#include <AbstractModel3D.h>
#include <string>
#include <glimac/Image.hpp>

using namespace std;

class LightTexModel3D : public AbstractModel3D {

public:

	//TODO static const path

	static const GLchar *FRAGMENT_UNIFORM_TEXTURE;
	static const GLchar *FRAGMENT_UNIFORM_DIFFUSE;
	static const GLchar *FRAGMENT_UNIFORM_GLOSSY;
	static const GLchar *FRAGMENT_UNIFORM_SHININESS;
	static const GLchar *FRAGMENT_UNIFORM_LIGHT_DIRECTION;
	static const GLchar *FRAGMENT_UNIFORM_LIGHT_COLOR;
	static const GLchar *FRAGMENT_UNIFORM_LIGHT_INTENSITY;

	static LightTexModel3D *create(const string &meshPath, const string &texturePath, const mat4 &modelTransform);

	~LightTexModel3D();

	void bind() override;

	void unbind() override;

private:

	GLuint _textureObject;
	GLint _uTexture;
	GLint _uShininess;
	GLint _uDiffuse;
	GLint _uGlossy;
	GLint _uLightDirection;
	GLint _uLightColor;
	GLint _uLightIntensity;

	LightTexModel3D(const Mesh &mesh, const unique_ptr<Image> &texture, const mat4 &modelTransform);

	void initTexture(const unique_ptr<Image> &texture);

	void initLight();

};

#endif
