#include "DropItem.h"
#include "Level.h"

//Texture* DropItem::s_pTexture = nullptr;
Texture* m_pDropItemTexture = nullptr;

DropItem::DropItem()
{
	SetDirection(Vector2::UNIT_Y); // -Vector2
	SetCollisionRadius(9);
}

void DropItem::LoadContent(ResourceManager& resourceManager)
{
	m_pDropItemTexture = resourceManager.Load<Texture>("Textures\\LogoSmall.png");

}

void DropItem::Update(const GameTime& gameTime)
{
	if (IsActive())
	{
		Vector2 translation = m_direction * m_speed * gameTime.GetElapsedTime();
		TranslatePosition(translation);

		Vector2 position = GetPosition();
		Vector2 size = m_pDropItemTexture->GetSize();

		// Is the projectile off the screen?
		if (position.Y < -size.Y) Deactivate();
		else if (position.X < -size.X) Deactivate();
		else if (position.Y > Game::GetScreenHeight() + size.Y) Deactivate();
		else if (position.X > Game::GetScreenWidth() + size.X) Deactivate();
	}

	GameObject::Update(gameTime);
}

void DropItem::Draw(SpriteBatch& spriteBatch)
{
	if (IsActive())
	{
		const float alpha = GetCurrentLevel()->GetAlpha();
		spriteBatch.Draw(m_pDropItemTexture, GetPosition(), Color::WHITE * alpha, m_pDropItemTexture->GetCenter());
	}
}

//DropItem* EnemyShip::GetDropItem()
//{
//	for (DropItem* pDropItem : *m_pDropItems)
//	{
//		if (!pDropItem->IsActive()) return pDropItem;
//	}
//
//	return nullptr;
//}

//void DropItem::Activate(Vector2& position) const 
//{
//	
//	SetPosition(position);
//
//	GameObject::Activate();
//}

//CollisionType DropItem::GetCollisionType() const
//{
//	CollisionType shipType = WasShotByPlayer() ? CollisionType::Player : CollisionType::Enemy;
//	return (shipType | GetProjectileType());
//}
