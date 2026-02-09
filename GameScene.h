#pragma once
#include "Player.h"
#include "Enemy.h"

enum Scene {
	TITLE,
	PLAY,
	CLEAR,
	GAMEOVER
};

class GameScene {

public:
	GameScene();
	~GameScene();

	int GetScene() { return scene; }

	void Update(char* keys, char* preKeys,Player* player,Enemy* enemy);
	void Draw();
	void SetScene(Scene scene_);

private:
	Scene scene;

};

