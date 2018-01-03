#ifndef __ABSTRACT_MODEL_3D_H__
#define __ABSTRACT_MODEL_3D_H__

#include <GL/glew.h>
#include <Mesh.h>
#include <string>
#include <glimac/glm.hpp>
#include <glimac/Program.hpp>
#include <json/json.hpp>
#include <SpotLight.h>

using namespace std;
using namespace glimac;
using namespace glm;

using json = nlohmann::json;

class AbstractModel3D {

public:

	/**
	 * Nom du vertex shader modeles abstraits 3D
	 **/
	static const string VERTEX_SHADER_3D;

	/**
	 * Variable d'entree correspondant a la position d'un sommet
	 **/
	static const GLuint VERTEX_ATTR_POSITION;
	
	/**
	 * Variable d'entree correspondant a la normale d'un sommet
	 **/
	static const GLuint VERTEX_ATTR_NORMAL;
	
	/**
	 * Variable d'entree correspondant au cordonnées de texture d'un sommet
	 **/
	static const GLuint VERTEX_ATTR_TEXTURE;

	/**
	 * Variable uniforme correspondant a la matrice ModelViewProjection
	 **/
	static const GLchar *VERTEX_UNIFORM_MVP_MATRIX;
	
	/**
	 * Variable uniforme correspondant a la matrice ModelView
	 **/
	static const GLchar *VERTEX_UNIFORM_MV_MATRIX;
	
	/**
	 * Variable uniforme correspondant a la matrice des normales
	 **/
	static const GLchar *VERTEX_UNIFORM_NORMAL_MATRIX;

	/**
	 * Créer un modele abstrait 3D à partir de sa représentation en JSON
	 * @param jsonModel : représentation en JSON du modele abstrait 3D
	 * @return le modele abstrait 3D crée
	 **/
	static AbstractModel3D *fromJSON(const json &jsonModel, const SpotLight *spotLight);

	/**
	 * Destructeur
	 **/
	virtual ~AbstractModel3D();

	/**
	 * Réalise les opération necessaire pour l'affichage du modele (bind du VAO, ...)
	 **/
	virtual void bind();

	/**
	 * Annule les opérations réalisées pour l'affichage du modele (bind du VAO à 0, ...)
	 **/
	virtual void unbind();

	/**
	 * Compte le nombre de sommet du modele
	 * @return le nombre de sommet du modele
	 **/
	GLsizei count() const;

	/**
	 * Renvoie l'identifiant de la variable uniforme en argument
	 * @param uniform : nom de la variable uniforme
	 * @return l'identifiant de la variable uniforme
	 **/
	GLint getUniformLocation(const GLchar *uniform);

	/**
	 * Met a jour les matrices passées en variables uniformes du modele
	 * @param ProjMatrix : matrice de projection
	 * @param MVMatrix : matrice ModelView
	 **/
	void setMatrices(const mat4 &ProjMatrix, const mat4 &MVMatrix);

protected:

	AbstractModel3D(const Mesh &mesh, const string &fragmentShader, const mat4 &modelTransform);


private:

	Program _program;

	GLuint _vbo;
	GLuint _vao;
	GLsizei _size;

	GLint _uMVPmatrix;
	GLint _uMVmatrix;
	GLint _uNormalmatrix;

	mat4 _modelTransform;

	void initPoints(const Mesh &mesh);

	void initProgram(const string &fragmentShader);

};

#endif
