#ifndef __TEX_MODEL_3D_H__
#define __TEX_MODEL_3D_H__

#include <AbstractModel3D.h>
#include <string>

using namespace std;

class TexModel3D : public AbstractModel3D {

public:

	//TODO static const path
	
	TexModel3D(const string & meshPath, const string & texturePath);
	
	void bind();
	void unbind();
	
private:

	GLuint _textureObject;
	GLuint _uTexture;

};

#endif
