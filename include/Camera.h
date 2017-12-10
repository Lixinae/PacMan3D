//
// Created by naeos on 08/12/17.
//

#ifndef PACMAN3D_CAMERA_H
#define PACMAN3D_CAMERA_H


#include <glm/detail/type_mat.hpp>

class Camera {

public:

    Camera() = default;

	/* *** TODO maybe not usefull *** */
    virtual void rotateHorizontal(float degrees)= 0;

    /**
     * Permet de faire tourner la camera vers le haut ou le bas(en ajoutant ou en enlevant des degrées)
     * @param degrees : valeur en degrees a enlever ou ajouter
     */
    virtual void rotateVertical(float degrees)= 0;

    /**
     * Permet d'avancer ou de reculer la camera
     * @param t : valeur a enlever ou rajouter
     */
    virtual void moveFront(float t)= 0;

    /**
     * Permet de deplacer la camera vers la gauche ou la droite
     * @param t : valeur a enlever ou rajouter
     */
    virtual void moveHorizontal(float t)= 0;
	
    /**
     * Calcul la viewMatrix de la camera et la renvoie
     * @return La viewMatrix de la camera
     */
    virtual glm::mat4 getViewMatrix() const = 0;

};

#endif //PACMAN3D_CAMERA_H
