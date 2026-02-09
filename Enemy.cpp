#include "Enemy.h"
#include "Novice.h"
#include <math.h>
#include <stdlib.h>

Enemy::Enemy() {
    Reset();
}

void Enemy::Reset() {
    posX_ = static_cast<float>(rand() % 1080 + 100);
    posY_ = -50.0f;
    speed_ = 4.0f;
    radius_ = 30.0f;
    hp_ = 5;
    isAlive_ = true;
    redTimer_ = 0;
}

void Enemy::Update() {
    if (!isAlive_) return;
    if (redTimer_ > 0) redTimer_--;

    posY_ += 2.0f;
    posX_ += speed_ + sinf(posY_ / 50.0f) * 8.0f;

    if (posX_ < radius_) {
        posX_ = radius_;
        speed_ *= -1;
    }
    if (posX_ > 1280.0f - radius_) {
        posX_ = 1280.0f - radius_;
        speed_ *= -1;
    }

    if (posY_ > 720.0f + radius_) {
        posY_ = 720.0f + radius_;
       
        Reset(); 
    }
}

void Enemy::OnDamage() {
    if (hp_ > 0) {
        hp_--;
        redTimer_ = 10;
    }
    if (hp_ <= 0) isAlive_ = false;
}

void Enemy::Draw() {
    if (!isAlive_) return;

    unsigned int color = (redTimer_ > 0) ? 0xFF0000FF : 0xFFFFFFFF;
    Novice::DrawEllipse((int)posX_, (int)posY_, (int)radius_, (int)radius_, 0.0f, color, kFillModeSolid);
}