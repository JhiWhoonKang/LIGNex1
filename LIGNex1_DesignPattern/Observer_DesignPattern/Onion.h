#pragma once

#include "snack.h"
#include <iostream>
class Onion : public Snack 
{
public:
    int getPrice() const override 
    {
        return 5;
    }
};