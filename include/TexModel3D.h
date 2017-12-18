#ifndef __TEX_MODEL_3D_H__
#define __TEX_MODEL_3D_H__

#include <AbstractModel3D.h>
#include <string>

using namespace std;

class TexModel3D : public AbstractModel3D {

public:

	//TODO static const path
	
	TexModel3D(const string & meshPath, const string & texturePath, const mat4 & modelTransform);
	
	~TexModel3D();
	
	void bind() override;
	void unbind() override;
	
private:

	GLuint _textureObject;
	GLint _uTexture;

};

#endif
