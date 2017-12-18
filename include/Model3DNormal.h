#ifndef __MODEL_3D_NORMAL_H__
#define __MODEL_3D_NORMAL_H__

#include <AbstractModel.h>
#include <Mesh.h>
#include <string>

class Model3DNormal : public AbstractModel {

public:

	static AbstractModel * load(const string & meshPath, const mat4 & transformations);

private:

	Model3DNormal(Program & program, const Mesh & mesh, const mat4 & transformations);

};

#endif
