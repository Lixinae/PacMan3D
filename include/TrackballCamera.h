#ifndef __TRACKBALL_CAMERA_H__
#define __TRACKBALL_CAMERA_H__

#include <glimac/common.hpp>
#include <Camera.h>

class TrackballCamera : public Camera {

private:

    float m_fDistance, m_fAngleX, m_fAngleY;

public:

    TrackballCamera();

    TrackballCamera(float Distance, float AngleX, float AngleY);

    /**
     * Permet d'avancer ou de reculer la camera
     * @param t : valeur a enlever ou rajouter
     */
    void moveFront(float delta) override;


    void rotateHorizontal(float degrees) override;

    /**
    * Permet de faire tourner la camera vers le haut ou le bas(en ajoutant ou en enlevant des degrées)
    * @param degrees : valeur en degrees a enlever ou ajouter
    */
    void rotateVertical(float degrees) override;

    /**
     * Permet de deplacer la camera vers la gauche ou la droite
     * /!\ Non implementé pour cette camera
     * @param t : valeur a enlever ou rajouter
     *
     */
    void moveHorizontal(float t) override;

    /**
     * Calcul la viewMatrix de la camera et la renvoie
     * @return La viewMatrix de la camera
     */
    glm::mat4 getViewMatrix() const override;

};

#endif

