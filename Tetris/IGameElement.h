#pragma once
struct IGameElement
{
    virtual void MoveLeft() = 0;
    virtual void MoveRight() = 0;
    virtual void MoveTop() = 0;
    virtual void MoveDown() = 0;
    virtual void Draw() = 0;
};
