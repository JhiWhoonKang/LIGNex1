#pragma once
#include "snack.h"
#include <vector>

class SnackSet : public Snack 
{
private:
    std::vector<Snack*> snacks;
public:
    void add(Snack* snack) override 
    {
        snacks.push_back(snack);
    }
    void remove(Snack* snack) override 
    {
        snacks.erase(std::remove(snacks.begin(), snacks.end(), snack), snacks.end());
    }
    int getPrice() const override 
    {
        int total = 0;
        for (const auto& snack : snacks) 
        {
            total += snack->getPrice();
        }
        return total;
    }
};