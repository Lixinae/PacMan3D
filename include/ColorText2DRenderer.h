#ifndef __COLOR_TEXT_2D_RENDERER_H__
#define __COLOR_TEXT_2D_RENDERER_H__

#include <GL/glew.h>
#include <glimac/glm.hpp>
#include <glimac/Program.hpp>
#include <map>
#include <string>

using namespace glimac;
using namespace std;
using namespace glm;

class ColorText2DRenderer {

public:

	struct Character {
		GLuint TextureID;
		ivec2 Size;
		ivec2 Bearing;
		GLuint Advance;
	};

	/**
	 * Nom du vertex shader texte 2D
	 **/
	static const string VERTEX_SHADER_TEXT_2D;

	/**
	 * Nom du fragment shader texte 2D
	 **/
	static const string FRAGMENT_SHADER_TEXT_2D;

	ColorText2DRenderer(int windowWidth, int windowHeight, const string &fontPath);

	// TODO DESTRUCT

	/**
	 *
	 * @param text Texte a ecrire
	 * @param xPercent % de taille de la largeur de la fenetre ou ecrire
	 * @param yPercent % de taille de la hauteur de la fenetre ou ecrire
	 * @param scale Scaling du texte , reduction ou augmentation de la taille
	 * @param color Couleur du texte
	 */
	void render(const string &text, GLfloat xPercent, GLfloat yPercent, GLfloat scale, const vec3 &color) const;

	/**
	 *
	 * @param text Texte a ecrire
	 * @param yPercent % de taille de la hauteur de la fenetre ou ecrire
	 * @param scale Scaling du texte , reduction ou augmentation de la taille
	 * @param color Couleur du texte
	 */
	void renderXCentered(const string &text, GLfloat yPercent, GLfloat scale, const vec3 &color) const;

private:

	map<GLchar, Character> _characters;

	Program _program;

	GLuint _vbo;
	GLuint _vao;

	GLint _uProjection;
	GLint _uTextColor;

	int _windowWidth;
	int _windowHeight;

	void initProgram();

	void initCharacters(int windowWidth, int windowHeight, const string &fontPath);

	void initQuads();

};

#endif
