// (C) Alan Ludwig. All rights reserved

#include <iostream>
#include "gsmath.h"

int main(void)
{
    std::cout << "Let's do some MATH!" << std::endl;

    uint64_t result;

    result = mul(0xBAADF00D, 0xDEADBEAF);

    std::cout << "Result: " << result << std::endl;
    std::cout << "Answer: " << (0xBAADF00Dull * 0xDEADBEAFull) << std::endl;

    return 1;
}