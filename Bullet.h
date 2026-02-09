#pragma once

class Bullet {
public:
    Bullet();
    void Update();
    void Draw();

    // Getter
    float GetPosX() const { return posX_; }
    float GetPosY() const { return posY_; }
    float GetRadius() const { return radius_; }
    bool GetIsActive() const { return isActive_; }

    // Setter
    void SetPosition(float x, float y);
    void SetIsActive(bool active);

private:
    float posX_;
    float posY_;
    float speed_;
    float radius_;
    bool isActive_;
};