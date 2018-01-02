#ifndef __POINT_OF_VIEW_H__
#define __POINT_OF_VIEW_H__

#include <Camera.h>
#include <TrackballCamera.h>
#include <FreeflyCamera.h>
#include <BoardPosition.h>
#include <Utils.h>

class PointOfView {

public:

	enum class CameraType {
		UPPER_LEFT,
		UPPER,
		UPPER_RIGHT,
		FIRST_PERSON
	};

	/**
	 * Construit le point de vue du jeu
	 * @param position : position de pacman
	 * @param orientation : orientation de pacman
	 **/
	PointOfView(const BoardPosition &position, Utils::Orientation orientation);

	/**
	 * Renvoie la camera gauche
	 * @return la camera gauche
	 **/
	TrackballCamera &getUpperLeftCamera();

	/**
	 * Renvoie la camera haute
	 * @return la camera haute
	 **/
	TrackballCamera &getUpperCamera();

	/**
	 * Renvoie la camera droite
	 * @return la camera droite
	 **/
	TrackballCamera &getUpperRightCamera();

	/**
	 * Renvoie la camera premiere personne
	 * @return la camera premiere personne
	 **/
	FreeflyCamera &getFirstPersonCamera();

	/**
	 * Renvoie la camera courante
	 * @return la camera courant
	 **/
	const Camera &getCurrentCamera() const;

	/**
	 * Renvoie le type de la camera courante
	 * @return le type de la camera courant
	 **/
	CameraType getCurrentCameraType() const;

	/**
	 * Passe a la camera suivante
	 **/
	void setNextCamera();

private:

	TrackballCamera _leftTrackballCamera;
	TrackballCamera _upperTrackballCamera;
	TrackballCamera _rightTrackballCamera;
	FreeflyCamera _freeflyCamera;
	CameraType _current;

};

#endif
