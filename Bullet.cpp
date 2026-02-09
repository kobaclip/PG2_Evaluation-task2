#include "Bullet.h"
#include "Novice.h"

Bullet::Bullet()
    : posX_(0), posY_(0), speed_(8.0f), radius_(4.0f), isActive_(false) {
}

void Bullet::Update() {
    if (!isActive_) return;

    posY_ -= speed_;

    if (posY_ < -radius_) {
        isActive_ = false;
    }
}

void Bullet::Draw() {

    if (!isActive_) return;
    Novice::DrawTriangle(
        static_cast<int>(posX_),
        static_cast<int>(posY_ - radius_),
        static_cast<int>(posX_ - radius_),
        static_cast<int>(posY_ + radius_),
        static_cast<int>(posX_ + radius_),
        static_cast<int>(posY_ + radius_),
        0xFFFFFFFF, kFillModeSolid
    );

}

void Bullet::SetPosition(float x, float y) {
    posX_ = x;
    posY_ = y;
}

void Bullet::SetIsActive(bool active) {
    isActive_ = active;
}