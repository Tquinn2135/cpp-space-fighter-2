//Whole File Made By James-Lee
#include "Crosshair.h"

bool Crosshair::Update(const GameTime& gameTime) {
	//Returns to level whether the crosshair is firing
	if (currentlyFiring) {
		//Unready Crosshair
		timeLastFired = gameTime.GetTotalTime();
		m_CurrCrosshairTexture = m_DarkCrosshairTexture;
		currentlyFiring = false;
		return true;
	}
	if (timeLastFired + cooldownTime < gameTime.GetTotalTime()) {
		//Ready Crosshair
		readyToFire = true;
		m_CurrCrosshairTexture = m_BrightCrosshairTexture;
	}
	return false;
}

void Crosshair::Draw(SpriteBatch& spriteBatch) {
	//const float alpha = GetCurrentLevel()->GetAlpha();
	spriteBatch.Draw(m_CurrCrosshairTexture, GetPosition(), Color::WHITE * 1, m_CurrCrosshairTexture->GetCenter());
}

void Crosshair::Fire() {
	//Crosshair is now firing - See Crosshair::Update
	currentlyFiring = true;
	readyToFire = false;
}

void Crosshair::LoadContent(ResourceManager& resourceManager)
{
	m_BrightCrosshairTexture = resourceManager.Load<Texture>("Textures\\CrosshairBright.png");
	m_DarkCrosshairTexture = resourceManager.Load<Texture>("Textures\\CrosshairDark.png");

	m_CurrCrosshairTexture = m_DarkCrosshairTexture;
}

void Crosshair::HandleInput(const InputState& input) {

	position = input.GetMousePosition().ToVector2();

	if (input.IsNewMouseButtonPress(MouseButton(1)) && readyToFire)
	{
		Fire();
	}
}