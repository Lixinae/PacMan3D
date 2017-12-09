#include <NormalModel3D.h>

#include <AbstractModel3D.h>
#include <Utils.h>

const string NormalModel3D::FRAGMENT_SHADER_NORMAL_3D = Utils::SHADER_PATH + "/" + "normal.fs.glsl";

NormalModel3D::NormalModel3D() : AbstractModel3D(FRAGMENT_SHADER_NORMAL_3D) {

}
