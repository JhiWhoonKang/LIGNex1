#include "onion.h"
#include "shrimp.h"
#include "snackset.h"
#include <iostream>

int main() 
{
    Onion onion;
    Shrimp shrimp;
    SnackSet set;

    set.add(&onion);
    set.add(&shrimp);

    std::cout << "Total price: " << set.getPrice() << "\n";

    set.remove(&onion);
    std::cout << "Price after removing onion: " << set.getPrice() << "\n";

    return 0;
}