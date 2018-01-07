#ifndef __LIGHT_TEX_MODEL_3D_H__
#define __LIGHT_TEX_MODEL_3D_H__

#include <AbstractModel3D.h>
#include <Material.h>
#include <string>
#include <glimac/Image.hpp>
#include <SpotLight.h>

using namespace std;

class LightTexModel3D : public AbstractModel3D {

public:

	//TODO static const path

	static const GLchar *FRAGMENT_UNIFORM_TEXTURE;
	static const GLchar *FRAGMENT_UNIFORM_DIFFUSE;
	static const GLchar *FRAGMENT_UNIFORM_GLOSSY;
	static const GLchar *FRAGMENT_UNIFORM_SHININESS;
	static const GLchar *FRAGMENT_UNIFORM_LIGHT_POS_CAMERA;
	static const GLchar *FRAGMENT_UNIFORM_LIGHT_COLOR_SPOT_CAMERA;
	static const GLchar *FRAGMENT_UNIFORM_LIGHT_COLOR_SPOT;
	static const GLchar *FRAGMENT_UNIFORM_LIGHT_INTENSITY_SPOT_CAMERA;
	static const GLchar *FRAGMENT_UNIFORM_LIGHT_INTENSITY_SPOT;
	static const GLchar *FRAGMENT_UNIFORM_LIGHT_POS;

	static LightTexModel3D *
	create(const string &meshPath, const string &texturePath, const Material &material, const mat4 &modelTransform, const SpotLight *spotLight,
	       const SpotLight *spotLightCamera);

	~LightTexModel3D() override;

	void bind() override;

	void unbind() override;

	void setMatrices(const mat4 &ProjMatrix, const mat4 &ViewMatrix, const mat4 &MVMatrix) override;

private:

	GLuint _textureObject;
	Material _material;
	GLint _uTexture;
	GLint _uShininess;
	GLint _uDiffuse;
	GLint _uGlossy;
	GLint _uLightPosSpotCamera;
	GLint _uLightColorSpotCamera;
	GLint _uLightColorSpot;
	GLint _uLightIntensitySpotCamera;
	GLint _uLightIntensitySpot;
	GLint _uLightPos;

	SpotLight *_spotLight;
	SpotLight *_spotLightCamera;
//	DirectionalLight *_directionalLight;

	LightTexModel3D(const Mesh &mesh, const unique_ptr<Image> &texture, const Material &material, const mat4 &modelTransform,
	                const SpotLight *spotLight, const SpotLight *spotLightCamera);

	void initTexture(const unique_ptr<Image> &texture);

	void initLight();

};

#endif
