#include <iostream>
#include "my_mean.h"

int main()
{
    std::cout << static_cast<int>(myMean(std::vector<int8_t>{0, -1})) << std::endl;
}