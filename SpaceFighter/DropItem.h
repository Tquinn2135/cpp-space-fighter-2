#pragma once

#include "KatanaEngine.h"
#include "GameObject.h"


class DropItem : public GameObject
{

public:

	DropItem();
	virtual ~DropItem() { }

	//virtual void LoadContent(ResourceManager& resourceManager);
	static void SetTexture(Texture* pTexture) { s_pTexture = pTexture; }

	/** @brief Set the texture that will be used to render the drop item.
		@param pTexture A pointer to the texture. */
	//static void SetTexture(Texture* pTexture) { s_pTexture = pTexture; }

	/** @brief Update the drop item.
		@param pGameTime Timing values including time since last update. */
	virtual void Update(const GameTime& gameTime);

	/** @brief Render the drop item.
		@param spriteBatch A reference to the game's sprite batch, used for rendering. */
	virtual void Draw(SpriteBatch& spriteBatch);

	/** @brief Activate the drop item.*/
	virtual void Activate() { GameObject::Activate(); }
	
	/** @brief Get the amount of damage the drop item will deal.
		@return The amount of damage the drop item will deal. */
	virtual float GetDamage() const { return m_damage; }

	/** @brief Get the string representation of the drop item.
		@return The string representation of the drop item. */
	virtual std::string ToString() const { return "Drop Item"; }

	/** @brief Get the type of collision the drop item will have.
		@return The type of collision the drop item will have. */
	virtual CollisionType GetCollisionType() const { return m_dropItem; }


protected:

	/** @brief Set the speed of the drop item.
		@param speed The speed of the drop item. */
	virtual void SetSpeed(const float speed) { m_speed = speed; }

	/** @brief Set the amount of damage the drop item will deal.
		@param damage The amount of damage the drop item will deal. */
	virtual void SetDamage(const float damage) { m_damage = damage; }

	/** @brief Set the direction of the drop item.
		@param direction The direction of the drop item. */
	virtual void SetDirection(const Vector2 direction) { m_direction = direction; }

	/** @brief Get the speed of the drop item.
		@return The speed of the drop item. */
	virtual float GetSpeed() const { return m_speed; }

	/** @brief Get the direction of the drop item.
		@return The direction of the drop item. */
	virtual Vector2& GetDirection() { return m_direction; }

	/** @brief Determine if the drop item was fired by the player.
		@return True if the drop item was fired by the player. */
	//virtual bool WasShotByPlayer() const { return m_wasShotByPlayer; }

	/** @brief Get the collision type of the drop item.
		@return The collision type of the drop item. */
	virtual CollisionType GetProjectileType() const { return CollisionType::Projectile | CollisionType::Player; }


private:

	//DropItem* p_DropItem;

	static Texture* s_pTexture;
	//Texture* m_pDropItemTexture = nullptr;

	float m_speed = 0; // pixels per second
	float m_damage = -1;

	Vector2 m_direction;

	//Vector2 position = (0, 0);

	CollisionType m_dropItem;

	//bool m_wasShotByPlayer = true;



};

