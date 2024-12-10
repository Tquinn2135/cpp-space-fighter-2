//Whole File Made By James-Lee
#include "Crosshair.h"

bool Crosshair::Update(const GameTime& gameTime) {

	if (timeLastFired + 1 < gameTime.GetTotalTime()) {
		readyToFire = true;
		m_CurrCrosshairTexture = m_BrightCrosshairTexture;
	}
	if (currentlyFiring) {
		timeLastFired = gameTime.GetTotalTime();
		m_CurrCrosshairTexture = m_DarkCrosshairTexture;
		currentlyFiring = false;
		return true;
	}
	return false;
}

void Crosshair::Draw(SpriteBatch& spriteBatch) {
	//const float alpha = GetCurrentLevel()->GetAlpha();
	spriteBatch.Draw(m_CurrCrosshairTexture, GetPosition(), Color::WHITE * 1, m_CurrCrosshairTexture->GetCenter());
}

void Crosshair::Fire() {
	currentlyFiring = true;
	readyToFire = false;
	m_CurrCrosshairTexture = m_DarkCrosshairTexture;
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