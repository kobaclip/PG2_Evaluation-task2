#pragma once

class Enemy {
public:
    Enemy();
    void Update();
    void Draw();

    void OnDamage();
    void Reset();

    // Getter
    float GetPosX() const { return posX_; }
    float GetPosY() const { return posY_; }
    float GetRadius() const { return radius_; }
    bool GetIsAlive() const { return isAlive_; }

private:
    float posX_;
    float posY_;
    float speed_;
    float radius_;
    int hp_;
    bool isAlive_;
    int redTimer_;
};