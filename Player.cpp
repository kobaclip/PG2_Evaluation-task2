#include "Player.h"
#include "Novice.h"

Player::Player(){
    posX_ = 640;
    posY_ = 360;
    speed_ = 10;
    radius_ = 15;
    Reset();

    shotTimer_ = 0;
    shotInterval_ = 12;

    isAlive_ = true;
}

void Player::Update(char* keys) {
    if (keys[DIK_A]) posX_ -= speed_;
    if (keys[DIK_D]) posX_ += speed_;
    if (keys[DIK_W]) posY_ -= speed_;
    if (keys[DIK_S]) posY_ += speed_;

    if (posX_ < radius_) {
        posX_ = radius_;
    }

    if (posX_ > 1280.0f - radius_) {
        posX_ = 1280.0f - radius_;
    }
    
    if (posY_ < radius_) {
        posY_ = radius_;
    }
    
    if (posY_ > 720.0f - radius_) {
        posY_ = 720.0f - radius_;
    }

    if (shotTimer_ > 0) {
        shotTimer_--;
    }

    if (keys[DIK_SPACE]) {
        if (shotTimer_ <= 0) {
            for (int i = 0; i < kBulletMax; i++) {
                if (!bullets_[i].GetIsActive()) {
                    bullets_[i].SetPosition(posX_, posY_);
                    bullets_[i].SetIsActive(true);

                    // 発射したのでタイマーをセット
                    shotTimer_ = shotInterval_;
                    break;
                }
            }
        }
    }

    for (int i = 0; i < kBulletMax; i++) {
        bullets_[i].Update();
    }
}

void Player::Reset() {
    posX_ = 640.0f;
    posY_ = 600.0f;
    speed_ = 10.0f;
    radius_ = 15.0f;
    hp_ = 3;
    isAlive_ = true;
    redTimer_ = 0;

    shotTimer_ = 0;
    shotInterval_ = 12;

    for (int i = 0; i < kBulletMax; i++) {
        bullets_[i].SetIsActive(false);
    }
}

void Player::OnDamage() {
    if (hp_ > 0) {
        hp_--;
        redTimer_ = 15;
    }
    if (hp_ <= 0) isAlive_ = false;
}

void Player::Draw() {
    if (!isAlive_) return;

    unsigned int color = (redTimer_ > 0) ? 0xFF0000FF : 0xFFFFFFFF;
    if (redTimer_ > 0) redTimer_--;

    Novice::DrawEllipse(
        static_cast<int>(posX_), static_cast<int>(posY_),
        static_cast<int>(radius_), static_cast<int>(radius_),
        0.0f, color, kFillModeSolid
    );

    for (int i = 0; i < kBulletMax; i++) {
        bullets_[i].Draw();
    }
}

void Player::SetPosition(float x, float y) {
    posX_ = x;
    posY_ = y;
}

void Player::SetSpeed(float speed) {
    speed_ = speed;
}

void Player::SetIsAlive(bool isAlive) {
    isAlive_ = isAlive;
}