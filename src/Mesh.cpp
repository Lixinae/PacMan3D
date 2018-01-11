#include <Mesh.h>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>


#include <iostream>

Mesh::Mesh(vector<ShapeVertex> vertices) : _vertices(vertices) {

}

Mesh Mesh::fromOBJFile(const string &filePath) {
	Assimp::Importer importer;
	const aiScene *scene = importer.ReadFile(filePath, aiProcessPreset_TargetRealtime_Fast);
	if (!scene) {
		throw invalid_argument("invalid OBJ file " + filePath);
	}
	vector<ShapeVertex> vertices;
	for (unsigned int i = 0; i < scene->mNumMeshes; i++) {
		const aiMesh *mesh = scene->mMeshes[i];
		for (unsigned int j = 0; j < mesh->mNumFaces; j++) {
			const aiFace &face = mesh->mFaces[j];
			for (unsigned int k = 0; k < 3; k++) {
				ShapeVertex shapeVertex;
				aiVector3D position = mesh->mVertices[face.mIndices[k]];
				shapeVertex.position = glm::vec3(position.x, position.y, position.z);
				aiVector3D normal = mesh->mNormals[face.mIndices[k]];
				shapeVertex.normal = glm::vec3(normal.x, normal.y, normal.z);
				aiVector3D *uv = mesh->mTextureCoords[0];
				// if uv if null there is no texture coords
				if (uv != nullptr) {
					// texCoords is a 3D vector but we only use the 2 first dimensions
					aiVector3D texCoords = uv[face.mIndices[k]];
					shapeVertex.texCoords = glm::vec2(texCoords.x, texCoords.y);
				}
				vertices.push_back(shapeVertex);
			}
		}
	}
	return Mesh(vertices);
}

const ShapeVertex *Mesh::getDataPointer() const {
	return _vertices.data();
}

GLsizei Mesh::getVertexCount() const {
	return _vertices.size();
}
