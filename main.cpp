#include <Novice.h>
#include <math.h>
#include "Player.h"
#include "Enemy.h"
#include "GameScene.h"

const char kWindowTitle[] = "LC1B_16_コバヤシ_リョウガ_PG";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	Player* player = new Player();

	Enemy* enemy = new Enemy();

	GameScene* gameScene = new GameScene();

	int enemyDefeatCount = 0;

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		gameScene->Update(keys,preKeys,player,enemy);

		int nowScene = gameScene->GetScene();


		if (nowScene == PLAY) {
			player->Update(keys);
			enemy->Update();

			Bullet* bullets = player->GetBullets();
			for (int i = 0; i < 10; i++) {
				if (bullets[i].GetIsActive() && enemy->GetIsAlive()) {
					float dx = bullets[i].GetPosX() - enemy->GetPosX();
					float dy = bullets[i].GetPosY() - enemy->GetPosY();
					if (sqrtf(dx * dx + dy * dy) < (bullets[i].GetRadius() + enemy->GetRadius())) {
						enemy->OnDamage();
						bullets[i].SetIsActive(false);
					}
				}
			}

			if (!enemy->GetIsAlive()) {
				enemyDefeatCount++;
				if (enemyDefeatCount >= 3) {
					gameScene->SetScene(CLEAR);
					enemyDefeatCount = 0;
				} else {
					enemy->Reset();
				}
			}

			if (player->GetIsAlive() && enemy->GetIsAlive()) {
				float dx = player->GetPosX() - enemy->GetPosX();
				float dy = player->GetPosY() - enemy->GetPosY();
				if (sqrtf(dx * dx + dy * dy) < (player->GetRadius() + enemy->GetRadius())) {
					player->OnDamage();
					if (player->GetHp() <= 0) {
						gameScene->SetScene(GAMEOVER);
					}
				}
			}
		}

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		gameScene->Draw();

		if (nowScene == PLAY) {
			player->Draw();
			enemy->Draw();
		}

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
