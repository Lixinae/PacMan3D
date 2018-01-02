#ifndef __MESH_H__
#define __MESH_H__

#include <vector>
#include <string>
#include <glimac/common.hpp>

using namespace std;
using namespace glimac;

class Mesh {

public:

	/**
	 * Charge un maillage depuis un fichier OBJ
	 * @param filePath : chemin vers le fichier OBJ
	 * @return le maillage du fichier OBJ
	 **/
	static Mesh fromOBJFile(const string &filePath);

	/**
	 * Renvoie le tableau de sommet
	 * @return le tableau de sommet
	 **/
	const ShapeVertex *getDataPointer() const;

	/**
	 * Renvoie la taille du tableau de sommet
	 * @return la taille du tableau de sommet
	 **/
	GLsizei getVertexCount() const;

private:

	vector<ShapeVertex> _vertices;

	Mesh(vector<ShapeVertex> vertices);

};

#endif
