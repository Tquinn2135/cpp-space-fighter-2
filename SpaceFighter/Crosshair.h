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

	//Getters for Crosshair Stats
	virtual double GetCooldownTime() { return cooldownTime; }
	virtual double GetRangeOfEffect() { return rangeOfEffect; }
	virtual double GetDamage() { return damage; }

	//Setters for Crosshair Stats
	virtual void SetCooldownTime(double newVal) { cooldownTime = newVal; }
	virtual void SetRangeOfEffect(double newVal) { rangeOfEffect = newVal; }
	virtual void SetDamage(double newVal) { damage = newVal; }

	Texture GetTexture() {
		return *m_CurrCrosshairTexture;
	}

	Vector2 GetPosition() {
		return position;
	}

private:
	//bools (and more) to track state of Crosshair
	//if both are false then it is still on its cooldown
	bool readyToFire = false;
	bool currentlyFiring = false;

	double timeLastFired = 0;

	Vector2 position = (0, 0);

	//Textures - Bright and Dark just keep the textures loaded
	//Curr is the texture actually being used
	Texture* m_CurrCrosshairTexture = nullptr;
	Texture* m_BrightCrosshairTexture = nullptr;
	Texture* m_DarkCrosshairTexture = nullptr;

	//Crosshair Stats
	double cooldownTime = 1;//seconds
	double rangeOfEffect = 100;//pixels - Note: crosshair textures are 50px*50px
	double damage = 3;//shipHP - Note: basic Enemies have 1HP, the Player has 3HP, and the Boss has 3HP
};