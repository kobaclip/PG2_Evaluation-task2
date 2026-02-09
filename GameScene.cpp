#include "GameScene.h"
#include <Novice.h>

GameScene::GameScene() {
	scene = TITLE;
}

GameScene::~GameScene() {}

void GameScene::SetScene(Scene scene_) {
	scene = scene_;
}

void GameScene::Update(char* keys, char* preKeys, Player* player, Enemy* enemy) {
	Novice::GetHitKeyStateAll(keys);

	switch (scene) {

	case TITLE:

		if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
			scene = PLAY;
			player->Reset();
			enemy->Reset();
		}

		break;

	case PLAY:

		break;

	case CLEAR:

		if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
			scene = TITLE;
		}

		break;

	case GAMEOVER:

		if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
			scene = TITLE;
		}

		break;

	}

}

void GameScene::Draw() {

	switch (scene) {

	case TITLE:


		Novice::ScreenPrintf(580, 300, "TITLE");
		Novice::ScreenPrintf(550, 450, "PRESS TO SPACE");

		break;

	case PLAY:

		break;

	case CLEAR:

		Novice::ScreenPrintf(560, 300, "CONGRATULATIONS!");
		Novice::ScreenPrintf(555, 330, "MISSION COMPLETE");

		Novice::ScreenPrintf(530, 500, "PRESS SPACE TO TITLE");

		break;

	case GAMEOVER:

		Novice::ScreenPrintf(580, 300, "GAME OVER");
		Novice::ScreenPrintf(565, 330, "YOU WERE DEFEATED");

		Novice::ScreenPrintf(530, 500, "PRESS SPACE TO RETRY");

		break;

	}

}