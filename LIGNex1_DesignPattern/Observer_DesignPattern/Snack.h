#pragma once
class Snack {
public:
    virtual ~Snack() = default;
    virtual void add(Snack* snack) {}
    virtual void remove(Snack* snack) {}
    virtual int getPrice() const = 0;
};