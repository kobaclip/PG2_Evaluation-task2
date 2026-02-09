#pragma once
#include "Bullet.h"

class Player {
public:
public:
    Player();
    void Update(char* keys);
    void Draw();

    // Getter
    float GetPosX() const { return posX_; }
    float GetPosY() const { return posY_; }
    float GetSpeed() const { return speed_; }
    float GetRadius() const { return radius_; }
    bool GetIsAlive()const { return isAlive_; }
    Bullet* GetBullets() { return bullets_; }
    void OnDamage();
    int GetHp() const { return hp_; }
    void Reset();

    // Setter
    void SetPosition(float x, float y);
    void SetSpeed(float speed);
    void SetIsAlive(bool isAlive);

private:
    float posX_;
    float posY_;
    float speed_;
    float radius_;
    bool isAlive_;
    int hp_;
    int redTimer_;
    int shotTimer_;
    int shotInterval_;

    static const int kBulletMax = 10;
    Bullet bullets_[kBulletMax];
};