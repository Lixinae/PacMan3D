#include <LightTexModel3D.h>

using namespace std;

const GLchar *LightTexModel3D::FRAGMENT_UNIFORM_TEXTURE = "uTexture";
const GLchar *LightTexModel3D::FRAGMENT_UNIFORM_DIFFUSE = "uKs";
const GLchar *LightTexModel3D::FRAGMENT_UNIFORM_GLOSSY = "uKd";
const GLchar *LightTexModel3D::FRAGMENT_UNIFORM_SHININESS = "uShininess";
const GLchar *LightTexModel3D::FRAGMENT_UNIFORM_LIGHT_DIRECTION = "uLightDir_vs";
const GLchar *LightTexModel3D::FRAGMENT_UNIFORM_LIGHT_COLOR = "uLightColor";
const GLchar *LightTexModel3D::FRAGMENT_UNIFORM_LIGHT_INTENSITY = "uLightIntensity";
const GLchar *LightTexModel3D::FRAGMENT_UNIFORM_LIGHT_POS = "uLightPos_vs";

void LightTexModel3D::initTexture(const unique_ptr<Image> &texture) {
	_uTexture = getUniformLocation(LightTexModel3D::FRAGMENT_UNIFORM_TEXTURE);
	glGenTextures(1, &_textureObject);
	glBindTexture(GL_TEXTURE_2D, _textureObject);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, texture->getWidth(), texture->getHeight(), 0, GL_RGBA, GL_FLOAT, texture->getPixels());
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBindTexture(GL_TEXTURE_2D, 0);
}

void LightTexModel3D::initLight() {
	_uShininess = getUniformLocation(LightTexModel3D::FRAGMENT_UNIFORM_SHININESS);
	_uDiffuse = getUniformLocation(LightTexModel3D::FRAGMENT_UNIFORM_DIFFUSE);
	_uGlossy = getUniformLocation(LightTexModel3D::FRAGMENT_UNIFORM_GLOSSY);
	_uLightDirection = getUniformLocation(LightTexModel3D::FRAGMENT_UNIFORM_LIGHT_DIRECTION);
	_uLightColor = getUniformLocation(LightTexModel3D::FRAGMENT_UNIFORM_LIGHT_COLOR);
	_uLightIntensity = getUniformLocation(LightTexModel3D::FRAGMENT_UNIFORM_LIGHT_INTENSITY);
	_uLightPos = getUniformLocation(LightTexModel3D::FRAGMENT_UNIFORM_LIGHT_POS);
}

LightTexModel3D::LightTexModel3D(const Mesh &mesh, const unique_ptr<Image> &texture, const Material &material, const mat4 &modelTransform,
                                 const SpotLight *spotLight) :
		AbstractModel3D(mesh, "shaders/lightTex3D.fs.glsl", modelTransform),
		_material(material),
		_spotLight(spotLight->clone())
{
	initTexture(texture);
	initLight();
}

LightTexModel3D *LightTexModel3D::create(const string &meshPath, const string &texturePath, const Material &material, const mat4 &modelTransform,
                                         const SpotLight *spotLight) {
	Mesh mesh = Mesh::fromOBJFile(meshPath);
	unique_ptr<Image> texture = loadImage(texturePath);
	//TODO nullcheck
	return new LightTexModel3D(mesh, texture, material, modelTransform, spotLight);
}

LightTexModel3D::~LightTexModel3D() {
	glDeleteTextures(1, &_textureObject);
}

void LightTexModel3D::bind() {
	AbstractModel3D::bind();
	glBindTexture(GL_TEXTURE_2D, _textureObject);
	glUniform1i(_uTexture, 0);
	glUniform1f(_uShininess, _material.getShininess());
	vec3 diffuse = _material.getDiffuse();
	glUniform3f(_uDiffuse, diffuse.x, diffuse.y, diffuse.z);
	vec3 glossy = _material.getGlossy();
	glUniform3f(_uGlossy, glossy.x, glossy.y, glossy.z);
	//LIGHT
//	vec3 lightDir(0.5f, 1.f, 0.5f); // Light dir
//	glUniform3f(_uLightDirection, lightDir.x, lightDir.y, lightDir.z);

	vec3 lightColor = _spotLight->getColor();
	glUniform3f(_uLightColor, lightColor.x, lightColor.y, lightColor.z);
	float intensity = _spotLight->getIntensity();
	glUniform1f(_uLightIntensity, intensity);

	vec3 lightPos = _spotLight->getPosition();
	glUniform3f(_uLightPos, lightPos.x, lightPos.y, lightPos.z);
}

void LightTexModel3D::unbind() {
	glBindTexture(GL_TEXTURE_2D, 0);
	AbstractModel3D::unbind();
}
