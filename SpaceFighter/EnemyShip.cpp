
#include "EnemyShip.h"
#include "Level.h" 



EnemyShip::EnemyShip()
{
	SetMaxHitPoints(1);
	SetCollisionRadius(20);

	

	//DropItem* pDropItem = new DropItem("Health"); // Sam Fox
	//pDropItem->SetDropItemPool(&m_dropItems);
}


void EnemyShip::Update(const GameTime& gameTime)
{
	if (m_delaySeconds > 0)
	{
		m_delaySeconds -= gameTime.GetElapsedTime();

		if (m_delaySeconds <= 0)
		{
			GameObject::Activate();
		}
	}

	if (IsActive())
	{
		m_activationSeconds += gameTime.GetElapsedTime();
		if (m_activationSeconds > 2 && !IsOnScreen()) Deactivate();
	}

	Ship::Update(gameTime);
}


void EnemyShip::Initialize(const Vector2 position, const double delaySeconds)
{
	SetPosition(position);
	m_delaySeconds = delaySeconds;

	

	Ship::Initialize();
}

DropItem* EnemyShip::GetDropItem() // Sam Fox
{
	for (DropItem* pDropItem : *m_pdropItems)
	{
		if (!pDropItem->IsActive()) return pDropItem;
	}

	return nullptr;
}

void EnemyShip::Hit(const float damage)
{
	Ship::Hit(damage);

	if (Ship::m_hitPoints <= 0)
	{
		//GetDropItem(&pDropItem);
		//pDropItem->Activate();
	}
}

