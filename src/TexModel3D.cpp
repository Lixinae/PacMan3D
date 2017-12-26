#include <TexModel3D.h>

using namespace std;

const GLchar *TexModel3D::FRAGMENT_UNIFORM_TEXTURE = "uTexture";
const GLchar *TexModel3D::FRAGMENT_UNIFORM_SHININESS = "uShininess";
const GLchar *TexModel3D::FRAGMENT_UNIFORM_LIGHT_DIRECTION = "uLightDirection";
const GLchar *TexModel3D::FRAGMENT_UNIFORM_AMBIANT_COLOR = "uAmbiantColor";
const GLchar *TexModel3D::FRAGMENT_UNIFORM_DIFFUSE_COLOR = "uDiffuseColor";
const GLchar *TexModel3D::FRAGMENT_UNIFORM_LIGHT_COLOR = "uLightColor";
const GLchar *TexModel3D::FRAGMENT_UNIFORM_LIGHT_INTENSITY = "uLightIntensity";

void TexModel3D::initTexture(const unique_ptr<Image> & texture) {
	_uTexture = getUniformLocation(TexModel3D::FRAGMENT_UNIFORM_TEXTURE);
	glGenTextures(1, &_textureObject);
	glBindTexture(GL_TEXTURE_2D, _textureObject);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, texture->getWidth(), texture->getHeight(), 0, GL_RGBA, GL_FLOAT, texture->getPixels());
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBindTexture(GL_TEXTURE_2D, 0);
}

void TexModel3D::initLight() {
	_uShininess = getUniformLocation(FRAGMENT_UNIFORM_SHININESS); // Brillance de l'objet
	_uLightDirection = getUniformLocation(FRAGMENT_UNIFORM_LIGHT_DIRECTION); // Direction de la lumiere
	_uAmbiantColor = getUniformLocation(FRAGMENT_UNIFORM_AMBIANT_COLOR); // Couleur de la lumiere ambiante
	_uDiffuseColor = getUniformLocation(FRAGMENT_UNIFORM_DIFFUSE_COLOR); // Couleur de la lumiere diffuse
	_uLightColor = getUniformLocation(FRAGMENT_UNIFORM_LIGHT_COLOR); // Couleur de la lumiere
	_uLightIntensity = getUniformLocation(FRAGMENT_UNIFORM_LIGHT_INTENSITY); // Intensité de la lumiere
}

// todo -> Changer le shader par celui de la lumiere , "shaders/lightning.fs.glsl"
TexModel3D::TexModel3D(const Mesh & mesh, const unique_ptr<Image> & texture, const mat4 & modelTransform) :
		AbstractModel3D(mesh, "shaders/lightning.fs.glsl", modelTransform)
//	AbstractModel3D(mesh, "shaders/tex3D.fs.glsl", modelTransform)
{
	initTexture(texture);
	initLight();
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

void TexModel3D::setLightComponents(float shininess){

//	float shininess = 10.f; // brillance de l'objet
	glUniform1f(_uShininess, shininess);

	vec3 lightDir = vec3(1, 1, 1); // Light dir
	glUniform3f(_uLightDirection, lightDir.x, lightDir.y, lightDir.z);

	const float divider = 255.f;
	vec3 lightColor = vec3(255.f / divider, 255.f / divider, 255.f / divider); // Light color
	glUniform3f(_uLightColor, lightColor.x, lightColor.y, lightColor.z);

	float ratio = 0.1f; // light AmbiantIntensity
	vec3 ambiantColor = vec3(lightColor.x * ratio, lightColor.y * ratio, lightColor.y * ratio);
	glUniform3f(_uAmbiantColor, ambiantColor.x, ambiantColor.y, ambiantColor.z);

	ratio = 0.5f; // Light diffuseIntensity
	vec3 diffuseColor = vec3(lightColor.x * ratio, lightColor.y * ratio, lightColor.y * ratio);
	glUniform3f(_uDiffuseColor, diffuseColor.x, diffuseColor.y, diffuseColor.z);

	float lightIntensity = 10; // Light intenstity
	glUniform1f(_uLightIntensity, lightIntensity);

}
