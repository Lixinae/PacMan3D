#ifndef __NORMAL_MODEL_3D_H__
#define __NORMAL_MODEL_3D_H__

#include <AbstractModel3D.h>

class NormalModel3D : public AbstractModel3D {

public:

	static const string FRAGMENT_SHADER_NORMAL_3D;
	
	NormalModel3D();

};

#endif
