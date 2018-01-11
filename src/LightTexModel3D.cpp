#include <LightTexModel3D.h>

using namespace std;

const GLchar *LightTexModel3D::FRAGMENT_UNIFORM_TEXTURE = "uTexture";
const GLchar *LightTexModel3D::FRAGMENT_UNIFORM_DIFFUSE = "uKs";
const GLchar *LightTexModel3D::FRAGMENT_UNIFORM_GLOSSY = "uKd";
const GLchar *LightTexModel3D::FRAGMENT_UNIFORM_SHININESS = "uShininess";
const GLchar *LightTexModel3D::FRAGMENT_UNIFORM_LIGHT_POS_CAMERA = "uLightPosSpotCamera_vs";
const GLchar *LightTexModel3D::FRAGMENT_UNIFORM_LIGHT_COLOR_SPOT_CAMERA = "uLightColorSpotCamera";
const GLchar *LightTexModel3D::FRAGMENT_UNIFORM_LIGHT_COLOR_SPOT = "uLightColorSpot";
const GLchar *LightTexModel3D::FRAGMENT_UNIFORM_LIGHT_INTENSITY_SPOT_CAMERA = "uLightIntensitySpotCamera";
const GLchar *LightTexModel3D::FRAGMENT_UNIFORM_LIGHT_INTENSITY_SPOT = "uLightIntensitySpot";
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
	_uLightPosSpotCamera = getUniformLocation(LightTexModel3D::FRAGMENT_UNIFORM_LIGHT_POS_CAMERA);
	_uLightColorSpotCamera = getUniformLocation(LightTexModel3D::FRAGMENT_UNIFORM_LIGHT_COLOR_SPOT_CAMERA);
	_uLightColorSpot = getUniformLocation(LightTexModel3D::FRAGMENT_UNIFORM_LIGHT_COLOR_SPOT);
	_uLightIntensitySpotCamera = getUniformLocation(LightTexModel3D::FRAGMENT_UNIFORM_LIGHT_INTENSITY_SPOT_CAMERA);
	_uLightIntensitySpot = getUniformLocation(LightTexModel3D::FRAGMENT_UNIFORM_LIGHT_INTENSITY_SPOT);
	_uLightPos = getUniformLocation(LightTexModel3D::FRAGMENT_UNIFORM_LIGHT_POS);
}

LightTexModel3D::LightTexModel3D(const Mesh &mesh, const unique_ptr<Image> &texture, const Material &material, const mat4 &modelTransform,
                                 const SpotLight *spotLight, const SpotLight *spotLightCamera) :
		AbstractModel3D(mesh, "shaders/lightTex3D.fs.glsl", modelTransform),
		_material(material),
		_spotLight(spotLight->clone()),
		_spotLightCamera(spotLightCamera->clone())
{
	initTexture(texture);
	initLight();
}

LightTexModel3D *LightTexModel3D::create(const string &meshPath, const string &texturePath, const Material &material, const mat4 &modelTransform,
                                         const SpotLight *spotLight, const SpotLight *spotLightCamera) {
	Mesh mesh = Mesh::fromOBJFile(meshPath);
	unique_ptr<Image> texture = loadImage(texturePath);
	if (texture == nullptr) {
		throw invalid_argument("invalid texture " + texturePath);
	}
	return new LightTexModel3D(mesh, texture, material, modelTransform, spotLight, spotLightCamera);
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
}

void LightTexModel3D::unbind() {
	glBindTexture(GL_TEXTURE_2D, 0);
	AbstractModel3D::unbind();
}

void LightTexModel3D::setMatrices(const mat4 &ProjMatrix, const mat4 &ViewMatrix, const mat4 &MVMatrix) {
	// Directional
	vec3 lightPosSpotCamera = _spotLightCamera->getPosition(); // relative to camera position
	glUniform3f(_uLightPosSpotCamera, lightPosSpotCamera.x, lightPosSpotCamera.y, lightPosSpotCamera.z);
	vec3 lightColor = _spotLightCamera->getColor();
	glUniform3f(_uLightColorSpotCamera, lightColor.x, lightColor.y, lightColor.z);
	float intensity = _spotLightCamera->getIntensity();
	glUniform1f(_uLightIntensitySpotCamera, intensity);
	// Spot
	lightColor = _spotLight->getColor();
	glUniform3f(_uLightColorSpot, lightColor.x, lightColor.y, lightColor.z);
	intensity = _spotLight->getIntensity();
	glUniform1f(_uLightIntensitySpot, intensity);
	vec3 lightPos = vec3(ViewMatrix * vec4(_spotLight->getPosition(), 1)); // absolute in viewspace
	glUniform3f(_uLightPos, lightPos.x, lightPos.y, lightPos.z);
	AbstractModel3D::setMatrices(ProjMatrix, ViewMatrix, MVMatrix);
}

