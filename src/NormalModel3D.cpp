#include <NormalModel3D.h>

//const string NormalModel3D::FRAGMENT_SHADER_NORMAL_3D = Utils::SHADER_PATH + "/" + "normal.fs.glsl";
const string NormalModel3D::FRAGMENT_SHADER_NORMAL_3D = "shaders/normal.fs.glsl";

NormalModel3D::NormalModel3D(const string & meshPath) : AbstractModel3D(meshPath, FRAGMENT_SHADER_NORMAL_3D) {

}
