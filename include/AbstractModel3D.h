#ifndef __ABSTRACT_MODEL_3D_H__
#define __ABSTRACT_MODEL_3D_H__

#include <GL/glew.h>
#include <Mesh.h>
#include <string>
#include <glimac/glm.hpp>
#include <glimac/Program.hpp>
#include <json/json.hpp>

using namespace std;
using namespace glimac;
using namespace glm;

using json = nlohmann::json;

class AbstractModel3D {

public:

	// Informations du vertex Shader
	static const string VERTEX_SHADER_3D;

	static const GLuint VERTEX_ATTR_POSITION;
	static const GLuint VERTEX_ATTR_NORMAL;
	static const GLuint VERTEX_ATTR_TEXTURE;
	
	static const GLchar * VERTEX_UNIFORM_MVP_MATRIX;
	static const GLchar * VERTEX_UNIFORM_MV_MATRIX;
	static const GLchar * VERTEX_UNIFORM_NORMAL_MATRIX;

	// Informations du fragment shader pour la lumiere
	static const GLchar *FRAGMENT_UNIFORM_SHININESS;
	static const GLchar *FRAGMENT_UNIFORM_LIGHT_DIRECTION;
	static const GLchar *FRAGMENT_UNIFORM_AMBIANT_COLOR;
	static const GLchar *FRAGMENT_UNIFORM_DIFFUSE_COLOR;
	static const GLchar *FRAGMENT_UNIFORM_LIGHT_COLOR;
	static const GLchar *FRAGMENT_UNIFORM_LIGHT_INTENSITY;


	static AbstractModel3D * fromJSON(const json & jsonModel);
	
	virtual ~AbstractModel3D();
	
	virtual void bind();
	virtual void unbind();
	
	GLsizei count() const;

	GLint getUniformLocation(const GLchar *uniform);
	
	void setMatrices(const mat4 & ProjMatrix, const mat4 & MVMatrix);

	void setLightComponents(float shininess) const;

protected:

	AbstractModel3D(const Mesh & mesh, const string & fragmentShader, const mat4 & modelTransform); 
	

private:

	Program _program;

	GLuint _vbo;
	GLuint _vao;
	GLsizei _size;

	GLint _uMVPmatrix;
    GLint _uMVmatrix;
    GLint _uNormalmatrix;

	mat4 _modelTransform;

	// Variables uniform pour la lumiere
	GLint _uShininess; // Brillance de l'objet
	GLint _uLightDirection; // Direction de la lumiere
	GLint _uAmbiantColor; // Couleur de la lumiere ambiante
	GLint _uDiffuseColor; // Couleur de la lumiere diffuse
	GLint _uLightColor; // Couleur de la lumiere
	GLint _uLightIntensity; // Intensité de la lumiere

    void initPoints(const Mesh & mesh);
    void initProgram(const string & fragmentShader);

};

#endif
