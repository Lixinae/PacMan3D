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
	static const GLchar *FRAGMENT_UNIFORM_SHININESS;
	static const GLchar *FRAGMENT_UNIFORM_LIGHT_DIRECTION;
	static const GLchar *FRAGMENT_UNIFORM_AMBIANT_COLOR;
	static const GLchar *FRAGMENT_UNIFORM_DIFFUSE_COLOR;
	static const GLchar *FRAGMENT_UNIFORM_LIGHT_COLOR;
	static const GLchar *FRAGMENT_UNIFORM_LIGHT_INTENSITY;
	
	static TexModel3D * create(const string & meshPath, const string & texturePath, const mat4 & modelTransform);
	
	~TexModel3D();
	
	void bind() override;
	void unbind() override;
	
	virtual void setLightComponents(float shininess);
	
private:

	GLuint _textureObject;
	GLint _uTexture;
	GLint _uShininess;
	GLint _uLightDirection;
	GLint _uAmbiantColor;
	GLint _uDiffuseColor;
	GLint _uLightColor;
	GLint _uLightIntensity;
	
	TexModel3D(const Mesh & mesh, const unique_ptr<Image> & texture, const mat4 & modelTransform);
	
	void initTexture(const unique_ptr<Image> & texture);
	void initLight();

};

#endif
