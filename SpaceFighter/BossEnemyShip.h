#pragma once//TPQ

#include "EnemyShip.h"

/** @brief Represents The boss enemy ship that is biological in nature. */

class BossEnemyShip : public EnemyShip
{

public:

	//creates a new instance of BossEnemyShip
	BossEnemyShip();
	virtual ~BossEnemyShip() { }

	//Set texture to render the enemy ship
	virtual void SetTexture(Texture* pTexture) { m_pTexture = pTexture; }

	//Updates the enemy ship
	virtual void Update(const GameTime& gameTime);

	//Draws the enemy ship
	virtual void Draw(SpriteBatch& spriteBatch);


private:

	Texture* m_pTexture = nullptr;
};