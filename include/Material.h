#ifndef __MATERIAL_H__
#define __MATERIAL_H__

#include <glm/vec3.hpp>
#include <json/json.hpp>

using namespace glm;

using json = nlohmann::json;

class Material {

public:

	/**
	 * Créer un materiel a partir de sa representation en JSON
	 * @param jsonMaterial : representation en JSON du materiel
	 * @return le materiel crée
	 **/
	static Material fromJSON(const json & jsonMaterial);

	/**
	 * Construit un materiel
	 * @param shininess : brillance de l'objet
	 * @param diffuse : reflection diffuse de l'objet
	 * @param glossy : reflection brillante de l'objet
	 **/
	Material(float shininess, const vec3 &diffuse, const vec3 &glossy);
	
	/**
	 * Renvoie le coefficient de brillance
	 * @return le coefficient de brillance
	 **/
	float getShininess() const;
	
	/**
	 * Renvoie le vecteur de reflection diffuse de l'objet
	 * @return le vecteur de reflection diffuse de l'objet
	 **/
	vec3 getDiffuse() const;
	
	/**
	 * Renvoie le vecteur de reflection brillante de l'objet
	 * @return le vecteur de reflection brillante de l'objet
	 **/
	vec3 getGlossy() const;
	
private:
	
	float _shininess;
	vec3 _diffuse;
	vec3 _glossy;
	
};


#endif
