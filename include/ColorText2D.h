#ifndef __COLOR_TEXT_2D_H__
#define __COLOR_TEXT_2D_H__

#include <GL/glew.h>
#include <glimac/glm.hpp>
#include <glimac/Program.hpp>
#include <map>

#include <iostream>

#include <ft2build.h>
#include FT_FREETYPE_H

using namespace glimac;
using namespace std;
using namespace glm;

class ColorText2D {

public:

	struct Character {
		GLuint TextureID;
		ivec2 Size;
		ivec2 Bearing;
		GLuint Advance;
	};
	
	void init2D(int windowWidth, int windowHeight, const Program &m_Program,const string& fontLoc) {// Compile and setup the shader

		mat4 projection = ortho(0.0f, static_cast<GLfloat>(windowWidth), 0.0f,
								static_cast<GLfloat>(windowHeight));
		m_Program.use();
		GLuint id = m_Program.getGLId();
		GLint projLoc = glGetUniformLocation(id, "projection");
		glUniformMatrix4fv(projLoc, 1, GL_FALSE, value_ptr(projection));

		// FreeType
		FT_Library ft;
		// All functions return a value different than 0 whenever an error occurred
		if (FT_Init_FreeType(&ft))
			cout << "ERROR::FREETYPE: Could not init FreeType Library" << endl;

		// Load font as face
		FT_Face face;
		if (FT_New_Face(ft, fontLoc.c_str(), 0, &face))
			cout << "ERROR::FREETYPE: Failed to load font" << endl;

		// Set size to load glyphs as
		FT_Set_Pixel_Sizes(face, 0, 48);

		// Disable byte-alignment restriction
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

		// Load first 128 characters of ASCII set
		for (GLubyte c = 0; c < 128; c++) {
			// Load character glyph
			if (FT_Load_Char(face, c, FT_LOAD_RENDER)) {
				cout << "ERROR::FREETYTPE: Failed to load Glyph" << endl;
				continue;
			}
			// Generate texture
			GLuint texture;
			glGenTextures(1, &texture);
			glBindTexture(GL_TEXTURE_2D, texture);
			glTexImage2D(
					GL_TEXTURE_2D,
					0,
					GL_RED,
					face->glyph->bitmap.width,
					face->glyph->bitmap.rows,
					0,
					GL_RED,
					GL_UNSIGNED_BYTE,
					face->glyph->bitmap.buffer
			);
			// Set texture options
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			// Now store character for later use
			Character character = {
					texture,
					ivec2(face->glyph->bitmap.width, face->glyph->bitmap.rows),
					ivec2(face->glyph->bitmap_left, face->glyph->bitmap_top),
					static_cast<GLuint>(face->glyph->advance.x)
			};
			_characters.insert(pair<GLchar, Character>(c, character));
		}
		glBindTexture(GL_TEXTURE_2D, 0);
		// Destroy FreeType once we're finished
		FT_Done_Face(face);
		FT_Done_FreeType(ft);


		// Configure VAO/VBO for texture quads
		glGenVertexArrays(1, &_vao);
		glGenBuffers(1, &_vbo);
		glBindVertexArray(_vao);
		glBindBuffer(GL_ARRAY_BUFFER, _vbo);
		glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * 6 * 4, NULL, GL_DYNAMIC_DRAW);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), 0);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);
	}
	
	/**
	 *
	 * @param m_Program Shader a utiliser
	 * @param text Texte a afficher
	 * @param x Coordonnée X en bas a gauche du texte
	 * @param y Coordonnée Y en bas a gauche du texte
	 * @param scale
	 * @param color Couleur du texte
	 */
	void renderText(const Program &m_Program, const string& text, GLfloat x, GLfloat y, GLfloat scale, const vec3& color) {
		// Activate corresponding render state
		m_Program.use();
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glUniform3f(glGetUniformLocation(m_Program.getGLId(), "textColor"), color.x, color.y, color.z);
		glActiveTexture(GL_TEXTURE0);
		glBindVertexArray(_vao);

		// Iterate through all characters
		std::string::const_iterator c;
		for (c = text.begin(); c != text.end(); c++) {
			Character ch = _characters[*c];

			GLfloat xpos = x + ch.Bearing.x * scale;
			GLfloat ypos = y - (ch.Size.y - ch.Bearing.y) * scale;

			GLfloat w = ch.Size.x * scale;
			GLfloat h = ch.Size.y * scale;
			// Update VBO for each character
			GLfloat vertices[6][4] = {
					{xpos,     ypos + h, 0.0, 0.0},
					{xpos,     ypos,     0.0, 1.0},
					{xpos + w, ypos,     1.0, 1.0},

					{xpos,     ypos + h, 0.0, 0.0},
					{xpos + w, ypos,     1.0, 1.0},
					{xpos + w, ypos + h, 1.0, 0.0}
			};
			// Render glyph texture over quad
			glBindTexture(GL_TEXTURE_2D, ch.TextureID);
			// Update content of VBO memory
			glBindBuffer(GL_ARRAY_BUFFER, _vbo);
			glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices),
							vertices); // Be sure to use glBufferSubData and not glBufferData

			glBindBuffer(GL_ARRAY_BUFFER, 0);
			// Render quad
			glDrawArrays(GL_TRIANGLES, 0, 6);
			// Now advance cursors for next glyph (note that advance is number of 1/64 pixels)
			x += (ch.Advance >> 6) *
				 scale; // Bitshift by 6 to get value in pixels (2^6 = 64 (divide amount of 1/64th pixels by 64 to get amount of pixels))
		}
		glBindVertexArray(0);
		glBindTexture(GL_TEXTURE_2D, 0);
		glDisable(GL_BLEND);
	}
	
private:

	std::map<GLchar, Character> _characters;
	GLuint _vbo;
	GLuint _vao;

};

#endif
