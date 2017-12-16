#include <Mesh.h>

#include <assimp/Importer.hpp> 
#include <assimp/scene.h>  
#include <assimp/postprocess.h>  
#include <glimac/common.hpp>  


#include <glimac/Sphere.hpp>
#include <iostream>

Mesh::Mesh(vector<ShapeVertex> vertices) : _vertices(vertices) {

}

Mesh Mesh::fromOBJFile(const string & filePath) {
	Assimp::Importer importer;
	const aiScene * scene = importer.ReadFile(filePath, aiProcessPreset_TargetRealtime_Fast);
	if (!scene) { //TODO except
		printf("%s\n", importer.GetErrorString());
	}
	std::cerr << filePath << std::endl;
	vector<ShapeVertex> vertices;
	for (unsigned int i = 0; i < scene->mNumMeshes; i++) {
		const aiMesh * mesh = scene->mMeshes[i];
		for(unsigned int j = 0; j < mesh->mNumFaces; j++) {
			const aiFace & face = mesh->mFaces[j];
			for(unsigned int k = 0; k < 3; k++) {
				aiVector3D position = mesh->mVertices[face.mIndices[k]];
				aiVector3D normal = mesh->mNormals[face.mIndices[k]];
				// texCoords is a 3D vector but we only use the 2 first dimensions
				aiVector3D texCoords = position; // TODO use : mesh->mTextureCoords[0][face.mIndices[k]]
				ShapeVertex shapeVertex;
				shapeVertex.position = glm::vec3(position.x, position.y, position.z);
				shapeVertex.normal = glm::vec3(normal.x, normal.y, normal.z);
				shapeVertex.texCoords = glm::vec2(texCoords.x, texCoords.y); // TODO maybe x,z or y,z , ...
				vertices.push_back(shapeVertex);
			}
		}
	}
	std::cerr << filePath << std::endl;
	return Mesh(vertices);
}

const ShapeVertex * Mesh::getDataPointer() const {
	return _vertices.data();
}

GLsizei Mesh::getVertexCount() const {
	return _vertices.size();
}
