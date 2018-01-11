#include <NormalModel3D.h>

const string NormalModel3D::FRAGMENT_SHADER_NORMAL_3D = "shaders/normal3D.fs.glsl";

NormalModel3D::NormalModel3D(const Mesh &mesh, const mat4 &modelTransform) :
		AbstractModel3D(mesh, "shaders/normal3D.fs.glsl", modelTransform) {

}

NormalModel3D *NormalModel3D::create(const string &meshPath, const mat4 &modelTransform) {
	Mesh mesh = Mesh::fromOBJFile(meshPath);
	return new NormalModel3D(mesh, modelTransform);
};
