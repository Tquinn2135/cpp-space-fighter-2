#include "BossEnemyShip.h" //TPQ's Class ccp
#include "level.h"

BossEnemyShip::BossEnemyShip()
{
	SetSpeed(90); // change this value to change speed. Make adjustments as needed //tweaked last by tom
	SetMaxHitPoints(25); //change the hit points //tweaked last by tom
	SetCollisionRadius(125); //don't change
}

void BossEnemyShip::Update(const GameTime& gameTime)
{
	if (IsActive())
	{
		float x = sin(gameTime.GetTotalTime() * Math::PI_OVER2 + GetIndex());
		x *= GetSpeed() * gameTime.GetElapsedTime() * 1.4f;
		TranslatePosition(x * 1.5, GetSpeed() * gameTime.GetElapsedTime()); //added the PI_OVER2 and the * 1.5 to TranslatePosition in order to
																			//to give the boss a wider range of movement
		if (!IsOnScreen()) Deactivate();
	}

	EnemyShip::Update(gameTime);
}

void BossEnemyShip::Draw(SpriteBatch& spriteBatch)
{
	if (IsActive())
	{
		const float alpha = GetCurrentLevel()->GetAlpha();
		spriteBatch.Draw(m_pTexture, GetPosition(), Color::WHITE * alpha, m_pTexture->GetCenter(), Vector2::ONE, Math::PI, 1);
	}
}