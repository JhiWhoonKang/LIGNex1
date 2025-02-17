#pragma once
#include "snack.h"
#include <iostream>
class Shrimp : public Snack 
{
public:
    int getPrice() const override 
    {
        return 7;
    }
};