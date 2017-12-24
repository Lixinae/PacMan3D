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
	
	ColorText2DRenderer(int windowWidth, int windowHeight, const string & fontPath);
	
	// TODO DESTRUCT
	
	void render(const string & text, GLfloat x, GLfloat y, GLfloat scale, const vec3 & color) const;
	
private:

	map<GLchar, Character> _characters;
		
	Program _program;
	
	GLuint _vbo;
	GLuint _vao;
	
	GLuint _uProjection;
	GLuint _uTextColor;
	
	void initProgram();
	void initCharacters(int windowWidth, int windowHeight, const string & fontPath);
	void initQuads();

};

#endif
