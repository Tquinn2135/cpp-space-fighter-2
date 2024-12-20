
#include "GameObject.h"
#include "GameplayScreen.h"
#include "Level02.h"
#include "BioEnemyShip.h"
#include "BossEnemyShip.h"


void Level02::LoadContent(ResourceManager& resourceManager)
{
	std::cout << "Level 02\n";//level indication in the console //tpq
	// Setup enemy ships
	Texture* pTexture = resourceManager.Load<Texture>("Textures\\BioEnemyShip.png");

	const int COUNT = 22;

	setEnemycount(COUNT); //TPQ

	double xPositions[COUNT] =
	{
		0.25, 0.2, 0.3,
		0.75, 0.8, 0.7,
		0.3, 0.25, 0.35, 0.2, 0.4,
		0.7, 0.75, 0.65, 0.8, 0.6,
		0.5, 0.4, 0.6, 0.45, 0.55, .6
	};

	double delays[COUNT] =
	{
		0.0, 0.25, 0.25,
		3.0, 0.25, 0.25,
		3.25, 0.25, 0.25, 0.25, 0.25,
		3.25, 0.25, 0.25, 0.25, 0.25,
		3.5, 0.3, 0.3, 0.3, 0.3, 0.3
	};

	float delay = 3.0; // start delay
	Vector2 position;

	for (int i = 0; i < COUNT; i++)
	{
		delay += delays[i];
		position.Set(xPositions[i] * Game::GetScreenWidth(), -pTexture->GetCenter().Y);

		BioEnemyShip* pEnemy = new BioEnemyShip();
		pEnemy->SetTexture(pTexture);
		pEnemy->SetCurrentLevel(this);
		pEnemy->Initialize(position, (float)delay);
		AddGameObject(pEnemy);
	}

	//TPQ: Add boss enemy ship 
	if (COUNT > 0)
	{
		delay += 5.0; // adds a delay of 5 seconds after the last enemy ship

		BossEnemyShip* pBossEnemy = new BossEnemyShip();
		pBossEnemy->SetTexture(resourceManager.Load<Texture>("Textures\\BioEnemyBoss.png"));
		pBossEnemy->SetCurrentLevel(this);
		pBossEnemy->Initialize(position, (float)delay);
		AddGameObject(pBossEnemy);
	}	

	SetBackground(resourceManager.Load<Texture>("Textures\\SpaceBackground04.png"));//--TPQ
	Level::LoadContent(resourceManager);
}

