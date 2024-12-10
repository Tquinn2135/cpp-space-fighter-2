#include "BossEnemyShip.h" //TPQ's Class ccp
#include "level.h"

BossEnemyShip::BossEnemyShip()
{
	SetSpeed(100); // change this value to change speed. Make adjustments as needed 
	SetMaxHitPoints(3); //change the hit points
	SetCollisionRadius(120);
}

void BossEnemyShip::Update(const GameTime& gameTime)
{
	if (IsActive())
	{
		float x = sin(gameTime.GetTotalTime() * Math::PI + GetIndex());
		x *= GetSpeed() * gameTime.GetElapsedTime() * 1.4f;
		TranslatePosition(x, GetSpeed() * gameTime.GetElapsedTime());

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