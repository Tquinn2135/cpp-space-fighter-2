//Whole File Made By James-Lee
#pragma once
#include "KatanaEngine.h"

using namespace KatanaEngine;

class Crosshair
{
public:

	//Constructor Declartion and Destrutor
	Crosshair() { };
	virtual ~Crosshair() { };

	//update
	virtual bool Update(const GameTime& gameTime);

	//draw
	virtual void Draw(SpriteBatch& spriteBatch);

	//input
	virtual void HandleInput(const InputState& input);

	//fire
	virtual void Fire();

	//load
	virtual void LoadContent(ResourceManager& resourceManager);

	Texture GetTexture() {
		return *m_CurrCrosshairTexture;
	}

	Vector2 GetPosition() {
		return position;
	}

private:
	Vector2 position = (0, 0);

	double timeLastFired = 0;

	bool readyToFire = false;
	bool currentlyFiring = false;

	Texture* m_CurrCrosshairTexture = nullptr;
	Texture* m_BrightCrosshairTexture = nullptr;
	Texture* m_DarkCrosshairTexture = nullptr;
};