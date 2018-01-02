#ifndef __RENDERER_H__
#define __RENDERER_H__

#include <GameRepresentation.h>
#include <GameInformations.h>
#include <Configuration.h>

class Renderer {

public:

	/**
	 * Dessine le jeu
	 * @param repr : representation du jeu
	 * @param gameInfo : informations du jeu
	 **/
	virtual void renderGame(const GameRepresentation &repr, const GameInformations &gameInfo) const = 0;

	/**
	 * Dessine l'ecran titre
	 */
	virtual void renderBeginTitle() const = 0;

	/**
	 * Dessine l'ecran de debut
	 **/
	virtual void renderBeginGame() const = 0;

	/**
	 * Dessine l'ecran de pause
	 * @param keyMap : tableau des controles
	 **/
	virtual void renderPauseMenu(const map<control, SDLKey> &keyMap) const = 0;

	/**
	 * Dessine l'ecran de fin
	 * @param gameInfo : informations du jeu
	 **/
	virtual void renderEndTitle(const GameInformations &gameInfo) const = 0;

	/**
	 * Destructeur
	 **/
	virtual ~Renderer() = default;

};

#endif
